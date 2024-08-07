#include "planner_node.hpp"
#include <iostream>
#include <cmath>

Planner::Planner() : rclcpp::Node("planner")
{
    next_waypoint_pub = this->create_publisher<nav_msgs::msg::Odometry>("next_waypoint", 1);
    all_waypoints_pub = this->create_publisher<nav_msgs::msg::Path>("waypoints", 1);
    odom_sub = this->create_subscription<nav_msgs::msg::Odometry>("/odometry/filtered", 1, bind(&Planner::current_state_callback, this, placeholders::_1));
    pose_sub = this->create_subscription<geometry_msgs::msg::PoseStamped>("des_pose", 1, bind(&Planner::des_pose_callback, this, placeholders::_1));
    obstacle_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>("obstacles", 1, bind(&Planner::obstacle_callback, this, placeholders::_1));
    tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
    this->declare_parameter("publish_rate", 30);
    this->declare_parameter("waypoints", 20);
    num_points = this->get_parameter("waypoints").as_int();
    int publish_rate = this->get_parameter("publish_rate").as_int();
    timer = this->create_wall_timer(std::chrono::milliseconds(1000 / publish_rate), std::bind(&Planner::timer_callback, this));
    prev_time = this->now();
}

void Planner::des_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
{
    if (des_pose_msg == nullptr)
    {
        des_pose_msg = msg;
        new_pose = true;
    }
    else if (des_pose_msg->pose.position.x != msg->pose.position.x ||
             des_pose_msg->pose.position.y != msg->pose.position.y ||
             des_pose_msg->pose.position.z != msg->pose.position.z ||
             des_pose_msg->pose.orientation.x != msg->pose.orientation.x ||
             des_pose_msg->pose.orientation.y != msg->pose.orientation.y ||
             des_pose_msg->pose.orientation.z != msg->pose.orientation.z ||
             des_pose_msg->pose.orientation.w != msg->pose.orientation.w)
    {
        // std::cout << "new pose: " << msg->pose.position.x << std::endl;
        des_pose_msg = msg;
        new_pose = true;
    }
    else
    {
        new_pose = false;
    }
}

void Planner::current_state_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    current_pose.pose.position.x = msg->pose.pose.position.x;
    current_pose.pose.position.y = msg->pose.pose.position.y;
    current_pose.pose.position.z = msg->pose.pose.position.z;
    current_pose.pose.orientation.x = msg->pose.pose.orientation.x;
    current_pose.pose.orientation.y = msg->pose.pose.orientation.y;
    current_pose.pose.orientation.z = msg->pose.pose.orientation.z;
    current_pose.pose.orientation.w = msg->pose.pose.orientation.w;
}

void Planner::obstacle_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg)
{
    if (!msg->data.empty())
    {
        uint8_t rows = msg->layout.dim[0].size;
        uint8_t cols = 5;
        // x, y, z, width, height of bounding box
        Eigen::Matrix<float, Eigen::Dynamic, 5> obs_xyz(rows, cols);
        for (uint8_t i = 0; i < rows; ++i)
        {
            for (uint8_t j = 0; j < cols; ++j)
            {
                obs_xyz(i, j) = msg->data[i * cols + j];
            }
        }
        Eigen::Vector3f curr_pos(current_pose.pose.position.x, current_pose.pose.position.y, current_pose.pose.position.z);
        Eigen::Vector3f des_pos(des_pose_msg->pose.position.x, des_pose_msg->pose.position.y, des_pose_msg->pose.position.z);
        std::vector<Eigen::Vector<float, 4>> obs_xyz_f = filter_obstacles(obs_xyz, curr_pos, des_pos);

        find_path(obs_xyz_f);
    }
}

std::vector<Eigen::Vector<float, 4>> Planner::filter_obstacles(const Eigen::Matrix<float, Eigen::Dynamic, 5> &obs_xyz, const Eigen::Vector3f &curr_pos, const Eigen::Vector3f &des_pos)
{
    Eigen::Vector<float, 3> line = des_pos - curr_pos;
    float norm = line.squaredNorm();
    // std::cout << "norm " << norm << std::endl;
    std::vector<Eigen::Vector<float, 3>> filtered_obs;
    std::vector<Eigen::Vector<float, 4>> intersection;
    for (size_t i = 0; i < obs_xyz.rows(); i++)
    {
        Eigen::Vector<float, 3> pt = obs_xyz.row(i).segment(0, 3);
        float width = obs_xyz(i, 3);
        float height = obs_xyz(i, 4);
        float theta = atan2(-pt[1], -pt[0]);

        // pt[0] += width * sin(theta);
        // pt[1] += height * cos(theta);

        float u = pt.dot(line) / norm;
        if (u > -0.2 && u < 1 + 0.1)
        {
            Eigen::Vector<float, 3> x = curr_pos + u * line;
            Eigen::Vector<float, 3> dx = x - pt;
            float dist = dx.norm();
            const float max_dist = 2.0;
            Eigen::Vector<float, 4> buffer;
            buffer.segment(0, 3) = ((max_dist - dist) / max_dist) * dx + x;
            buffer[3] = u;
            // std::cout << "dist " << x << " dx " << dx << " u " << pt << std::endl;
            if (dist < 5.0)
            {
                Eigen::Vector<float, 4> x_front;
                x_front.segment(0, 3) = buffer.segment(0, 3) - 0.1 * line;
                x_front[3] = u - 0.1;
                Eigen::Vector<float, 4> x_back;
                x_back.segment(0, 3) = buffer.segment(0, 3) + 0.5 * line;
                x_back[3] = u + 0.5;
                filtered_obs.push_back(pt);
                // intersection.push_back(x_front);
                intersection.push_back(buffer);
                // intersection.push_back(x_back);
            }
        }
    }

    return (intersection);
}

void Planner::find_path(std::vector<Eigen::Vector<float, 4>> waypoints)
{
    path_msg.poses.clear();
    float dx = des_pose_msg->pose.position.x;
    float dy = des_pose_msg->pose.position.y;
    float dz = des_pose_msg->pose.position.z;

    float cx = current_pose.pose.position.x;
    float cy = current_pose.pose.position.y;
    float cz = current_pose.pose.position.z;

    float d_x = (dx - cx) / num_points;
    float d_y = (dy - cy) / num_points;
    float d_z = (dz - cz) / num_points;

    tf2::Quaternion des;
    tf2::Quaternion curr;
    tf2::fromMsg(des_pose_msg->pose.orientation, des);
    tf2::fromMsg(current_pose.pose.orientation, curr);

    auto msg = geometry_msgs::msg::PoseStamped();
    msg.pose.position.x = cx;
    msg.pose.position.y = cy;
    msg.pose.position.z = cz;
    for (size_t i = 0; i < num_points; i++)
    {
        msg.pose.position.x += d_x;
        msg.pose.position.y += d_y;
        msg.pose.position.z += d_z;
        msg.pose.orientation = tf2::toMsg(tf2::slerp(curr, des, static_cast<double>(i + 1) / num_points));

        path_msg.poses.push_back(msg);
    }
    if (!waypoints.empty())
    {
        for (size_t i = 0; i < num_points; i++)
        {
            if (!waypoints.empty())
            {
                std::cout << "pts " << waypoints.front()[3] << "i" << (static_cast<double>(i + 1) / num_points) << std::endl;
                if (waypoints.front()[3] < (static_cast<double>(i + 2) / num_points))
                {
                    std::cout << "idx " << waypoints.front()[3] << "i" << static_cast<double>(i + 2) / num_points << "i " << i << std::endl;
                    path_msg.poses[i].pose.position.x = waypoints.front()[0];
                    path_msg.poses[i].pose.position.y = waypoints.front()[1];
                    path_msg.poses[i].pose.position.z = waypoints.front()[2];
                    std::rotate(waypoints.begin(), waypoints.begin() + 1, waypoints.end());
                    waypoints.pop_back();
                }
            }
        }
    }
    waypoint_msg.pose.pose = path_msg.poses.front().pose;
    path_msg.header.frame_id = "map";
    new_pose = false;
}

void Planner::timer_callback()
{
    if (new_pose)
    {
        find_path();
    }
    else
    {
        if (!path_msg.poses.empty())
        {
            tf2::Transform curr;
            tf2::Transform des;
            tf2::fromMsg(current_pose.pose, curr);
            tf2::fromMsg(waypoint_msg.pose.pose, des);
            float posDist = tf2::tf2Distance(curr.getOrigin(), des.getOrigin());
            float orientDist = pow(tf2::length(curr.getRotation().inverse() * des.getRotation()) - 1, 2);
            float orientation_multiplier = 2.0;
            float diff_norm = posDist + orientation_multiplier * orientDist;
            // std::cout << "pos" << posDist << "orient" << orientDist << "norm" << diff_norm << std::endl;
            if (diff_norm < 0.5)
            {
                std::cout << "heading to next waypoint" << std::endl;
                std::rotate(path_msg.poses.begin(), path_msg.poses.begin() + 1, path_msg.poses.end());
                path_msg.poses.pop_back();
                waypoint_msg.pose.pose = path_msg.poses.front().pose;
            }
            else if (diff_norm > 5.0)
            {
                new_pose = true;
            }
        }
        else
        {
            at_destination = true;
        }
    }
    waypoint_msg.header.frame_id = "base_link";
    all_waypoints_pub->publish(path_msg);
    next_waypoint_pub->publish(waypoint_msg);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Planner>());
    rclcpp::shutdown();
    return 0;
}
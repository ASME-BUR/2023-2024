#include "joy_command.hpp"
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <cmath>

JoyCommand::JoyCommand() : rclcpp::Node("joy_command")
{
    this->declare_parameter("cmd_pub_topic", "command");
    this->declare_parameter("joy_topic", "joy");
    this->declare_parameter("pose_topic", "pose");
    this->declare_parameter("imu_topic", "imu");
    this->declare_parameter("velocity", 0.5);
    const std::map<std::string, int> &axis_mapping = {{"linear_x", 1}, {"linear_y", 0}, {"linear_z", 2}, {"angular_x", 3}, {"angular_y", 4}, {"angular_z", 5}};
    this->declare_parameters("axis_mapping", axis_mapping);
    cmd_pub = this->create_publisher<bur_rov_msgs::msg::Command>(this->get_parameter("cmd_pub_topic").as_string(), 10);
    joy_sub = this->create_subscription<sensor_msgs::msg::Joy>(this->get_parameter("joy_topic").as_string(), 10,
                                                               bind(&JoyCommand::joy_callback, this, placeholders::_1));
    pose_sub = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(this->get_parameter("pose_topic").as_string(), 10,
                                                                                        bind(&JoyCommand::pose_callback, this, placeholders::_1));
    const rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort().durability_volatile();
    imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(this->get_parameter("imu_topic").as_string(), qos_profile,
                                                               bind(&JoyCommand::imu_callback, this, placeholders::_1));
    vel_cap = this->get_parameter("velocity").as_double();
    this->get_parameters("axis_mapping", axis_mapping_);
    prev_time = this->now();

    debug_imu_pub = this->create_publisher<geometry_msgs::msg::PoseStamped>("imu_debug", 10);

    debug_joy_pub = this->create_publisher<geometry_msgs::msg::PoseStamped>("joy_debug", 10);
}

void JoyCommand::joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
    if (!msg->axes.empty())
    {
        this->output.target_vel.linear.x = vel_cap * msg->axes[axis_mapping_.at("linear_x")];
        this->output.target_vel.linear.y = vel_cap * -msg->axes[axis_mapping_.at("linear_y")];
        this->output.target_vel.linear.z = vel_cap * msg->axes[axis_mapping_.at("linear_z")];
        this->output.target_vel.angular.x = vel_cap * msg->axes[axis_mapping_.at("angular_x")];
        this->output.target_vel.angular.y = vel_cap * msg->axes[axis_mapping_.at("angular_y")];
        this->output.target_vel.angular.z = vel_cap * msg->axes[axis_mapping_.at("angular_z")];


        tf2::Quaternion q;
        q.setRPY(msg->axes[axis_mapping_.at("angular_x")] * M_PI_2, msg->axes[axis_mapping_.at("angular_y")] * M_PI_2, 0);
        q.normalize();
        this->output.target_pos.orientation = tf2::toMsg(q);
        this->output.buttons.clear();
        for (uint8_t i = 0; i < msg->buttons.size(); i++)
        {
            this->output.buttons.push_back(msg->buttons[i]);
        }
        cmd_pub->publish(output);

        auto debug_msg = geometry_msgs::msg::PoseStamped();
        debug_msg.header.stamp = this->now();
        debug_msg.header.frame_id = "map";
    
        debug_msg.pose.orientation.w = this->output.target_pos.orientation.w;
        debug_msg.pose.orientation.x = this->output.target_pos.orientation.x;
        debug_msg.pose.orientation.y = this->output.target_pos.orientation.y;
        debug_msg.pose.orientation.z = this->output.target_pos.orientation.z;

        debug_msg.pose.position.x=0;
        debug_msg.pose.position.y=0;
        debug_msg.pose.position.z=0;

        debug_joy_pub->publish(debug_msg);
    }
}

void JoyCommand::pose_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
{
    this->output.current_pos.position.z = msg->pose.pose.position.z;
    cmd_pub->publish(output);
}

void JoyCommand::imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    // IMU output is ENU, everything else is NWU coordinates so we need to swap some axes
    this->output.current_pos.orientation.x = msg->orientation.x;
    this->output.current_pos.orientation.y = msg->orientation.y;
    this->output.current_pos.orientation.z = msg->orientation.z;
    this->output.current_pos.orientation.w = msg->orientation.w;

    this->output.current_vel.angular.x = msg->angular_velocity.x;
    this->output.current_vel.angular.y = msg->angular_velocity.y;
    this->output.current_vel.angular.z = msg->angular_velocity.z;
    rclcpp::Time now = this->now();
    double acceleration[3] = {msg->linear_acceleration.x, msg->linear_acceleration.y, -msg->linear_acceleration.z};

    // Gravity adjustment
    Eigen::Quaterniond orientation;
    orientation.x() = msg->orientation.x;
    orientation.y() = msg->orientation.y;
    orientation.z() = msg->orientation.z;
    orientation.w() = msg->orientation.w;

    Eigen::Matrix3d rotationMatrix = orientation.toRotationMatrix();
    Eigen::Vector3d gravity = {0, 0, 9.80665};
    Eigen::Vector3d gravityOffset = rotationMatrix * gravity;

    acceleration[0] -= gravityOffset[0];
    acceleration[1] -= gravityOffset[1];
    acceleration[2] += gravityOffset[2];


    vel_calc(acceleration, now, prev_time);

    this->output.current_vel.linear.x = velocity[0];
    this->output.current_vel.linear.y = velocity[1];
    this->output.current_vel.linear.z = velocity[2];

    cmd_pub->publish(output);
    prev_time = this->now();

    auto debug_msg = geometry_msgs::msg::PoseStamped();
    debug_msg.header.stamp = this->now();
    debug_msg.header.frame_id = "map";
   
    debug_msg.pose.orientation.w = this->output.current_pos.orientation.w;
    debug_msg.pose.orientation.x = this->output.current_pos.orientation.x;
    debug_msg.pose.orientation.y = this->output.current_pos.orientation.y;
    debug_msg.pose.orientation.z = this->output.current_pos.orientation.z;

    debug_msg.pose.position.x=0;
    debug_msg.pose.position.y=0;
    debug_msg.pose.position.z=0;

    debug_imu_pub->publish(debug_msg);
}

double* JoyCommand::vel_calc(double acceleration[3], rclcpp::Time current_time, rclcpp::Time previous_time)
{
    rclcpp::Duration diff = current_time - previous_time;
    auto num_of_ns = diff.to_chrono<std::chrono::nanoseconds>();
    double delta_t = num_of_ns.count();
    delta_t = delta_t/pow(10, 9);
    // std::cout << "delta_t: " << delta_t << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        velocity[i] = acceleration[i] * delta_t + v_0[i];
        v_0[i] = velocity[i];
    }
    return velocity;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JoyCommand>());
    rclcpp::shutdown();
    return 0;
}
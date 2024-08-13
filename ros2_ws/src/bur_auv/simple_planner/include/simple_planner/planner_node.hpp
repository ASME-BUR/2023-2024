#ifndef PLANNER_NODE_HPP
#define PLANNER_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/utils.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include "tf2_ros/transform_broadcaster.h"
#include "std_msgs/msg/float32_multi_array.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <optional>
#include <Eigen/Dense>
using namespace std;

class Planner : public rclcpp::Node
{
public:
    Planner();

private:
    void des_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    void current_state_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void obstacle_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg);
    void find_path(vector<Eigen::Vector<float, 4>> waypoints = {});
    vector<Eigen::Vector<float, 4>> filter_obstacles(const Eigen::Matrix<float, Eigen::Dynamic, 5> &obs_xyz, const Eigen::Vector3f &curr_pos, const Eigen::Vector3f &des_pos);
    void timer_callback();

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr next_waypoint_pub;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr all_waypoints_pub;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub;
    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr obstacle_sub;
    rclcpp::TimerBase::SharedPtr timer;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster;

    nav_msgs::msg::Path path_msg;
    nav_msgs::msg::Odometry waypoint_msg;
    geometry_msgs::msg::PoseStamped::SharedPtr des_pose_msg = nullptr;
    geometry_msgs::msg::PoseStamped current_pose;
    bool new_pose = false;
    bool at_destination = false;
    uint8_t num_points = 0;

    rclcpp::Time prev_time;
};

#endif
#ifndef JOY_COMMAND_HPP
#define JOY_COMMAND_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/vector3_stamped.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "bur_rov_msgs/msg/command.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/utils.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <array>
#include <memory>
using namespace std;

class JoyCommand : public rclcpp::Node
{
public:
    JoyCommand();

private:
    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg);
    void pose_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);
    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg);
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    double *vel_calc(double acceleration[3], rclcpp::Time current_time, rclcpp::Time previous_time);

    rclcpp::Publisher<bur_rov_msgs::msg::Command>::SharedPtr cmd_pub;
    rclcpp::Publisher<geometry_msgs::msg::Vector3Stamped>::SharedPtr imu_euler;
    rclcpp::Publisher<geometry_msgs::msg::Vector3Stamped>::SharedPtr joy_euler;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr debug_imu_pub;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr debug_joy_pub;

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub;
    rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pose_sub;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub;
    
    bur_rov_msgs::msg::Command output;
    geometry_msgs::msg::Vector3Stamped joy_euler_msg;
    float multiplier;
    double v_0[3] = {};
    double velocity[3] = {};
    rclcpp::Time prev_time;
    std::map<std::string, int64_t> axis_mapping_;
};

#endif
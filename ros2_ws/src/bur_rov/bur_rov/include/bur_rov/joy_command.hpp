#ifndef JOY_COMMAND_HPP
#define JOY_COMMAND_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "bur_rov_msgs/msg/command.hpp"
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
    void pose_callback(const geometry_msgs::msg::Pose::SharedPtr msg);
    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg);
    rclcpp::Publisher<bur_rov_msgs::msg::Command>::SharedPtr cmd_pub;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub;
    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr pose_sub;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;
    geometry_msgs::msg::Pose pose;
    bur_rov_msgs::msg::Command output;
    float vel;
    std::map<std::string, int64_t> axis_mapping_;
};

#endif
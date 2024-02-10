#ifndef JOY_COMMAND_HPP
#define JOY_COMMAND_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "bur_rov_msgs/msg/command.hpp"
#include <iostream>
#include <memory>
using namespace std;

class Joy_cmd : public rclcpp::Node
{
public:
    Joy_cmd();

private:
    void joy_cb(const sensor_msgs::msg::Joy::SharedPtr msg);
    rclcpp::Publisher<bur_rov_msgs::msg::Command>::SharedPtr pub_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_;
};

#endif

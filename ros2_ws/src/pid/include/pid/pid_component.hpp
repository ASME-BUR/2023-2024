#ifndef PID_COMPONENT_HPP
#define PID_COMPONENT_HPP

#include "rclcpp/rclcpp.hpp"
#include "visibility_control.h"
#include "std_msgs/msg/float64.hpp"
#include "custom_msg_srv/msg/float64_stamped.hpp"
#include "pid.hpp"
#include <cmath>
#include <vector>
#include <chrono>
#include <iostream>
using namespace std::chrono_literals;

class Pid_component
{
public:
    COMPOSITION_PUBLIC
    explicit Pid_component(const rclcpp::NodeOptions &options);

    COMPOSITION_PUBLIC
    rclcpp::node_interfaces::NodeBaseInterface::SharedPtr get_node_base_interface() const;

protected:
    void setConstants();
    void pid_callback();

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr ctrl_effort;
    rclcpp::Subscription<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint;
    rclcpp::Subscription<custom_msg_srv::msg::Float64Stamped>::SharedPtr state;
    rclcpp::TimerBase::SharedPtr timer_;
    PID pid_controller;

    double setpoint_ = 0;
    double state_ = 0;
    double last_output_ = 0;

    // Primary PID controller input variables
    bool pid_enabled_;                // PID is enabled to run
    bool new_state_or_setpt_ = false; // Indicate that fresh calculations need to be run
    rclcpp::Time last_time;
};
#endif
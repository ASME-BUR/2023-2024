#ifndef PID_NODE_H
#define PID_NODE_H

#include "pid/pid.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <memory>
#include <functional>
#include "common_functions.hpp"
#include <array>
#include "auv_msgs/msg/allocator_command.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"

using std::placeholders::_1;

class Pid_node : public rclcpp::Node
{
public:
    Pid_node();

protected:
    void setConstants();
    void pid_callback();
    void setpoint_callback(const geometry_msgs::msg::TransformStamped::SharedPtr msg);
    void state_callback(const sensor_msgs::msg::Imu::SharedPtr msg);
    rclcpp::Publisher<auv_msgs::msg::AllocatorCommand>::SharedPtr ctrl_effort_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr dummy_pub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr state_sub_;
    rclcpp::Subscription<geometry_msgs::msg::TransformStamped>::SharedPtr setpoint_sub_;
    rclcpp::TimerBase::SharedPtr timer_;
    rcl_interfaces::msg::SetParametersResult parametersCallback(
        const std::vector<rclcpp::Parameter> &parameters);

    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_callback_;
    rclcpp::Time last_loop_time_;
    bool new_params = false;

    double setpoint_[6] = {0};
    double state_[6] = {0};
    double last_output_[6] = {0};

    // Primary PID controller input variables
    bool pid_enabled_[6];             // PID is enabled to run
    bool new_state_or_setpt_ = false; // Indicate that fresh calculations need to be run

    PID pid[6];
};
#endif // PID_NODE_H

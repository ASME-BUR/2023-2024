#ifndef BAR30_NODE_HPP
#define BAR30_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "std_msgs/msg/float32.hpp"
#include "MS5837.h"
#include <cmath>
#include <chrono>
#include <functional>
#include <memory>
#include <iostream>
using namespace std;

class Bar30_node : public rclcpp::Node
{
public:
    Bar30_node();
    ~Bar30_node();
    // void run();

private:
    rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr depth_pub;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pressure_pub;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr temp_pub;
    void timer_Callback();
    rclcpp::TimerBase::SharedPtr timer;
    unique_ptr<MS5837> sensor;
    int pi;
    size_t count;
};

#endif
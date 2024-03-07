#ifndef IMU_NODE_HPP
#define IMU_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "LPS.h"
#include <cmath>
#include <chrono>
#include <functional>
#include <memory>
#include <iostream>
using namespace std;

class LPS_node : public rclcpp::Node
{
public:
    LPS_node();
    ~LPS_node();
    // void run();

private:
    rclcpp::Publisher<std::msgs::>::SharedPtr imu_pub;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr imu_eul_pub;
    // North(x)-East(y)-Down(z) Coordinate
    void timer_Callback();
    rclcpp::TimerBase::SharedPtr timer_;
    unique_ptr<LPS> lps;
    int pi;
};

#endif
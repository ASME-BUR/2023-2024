#ifndef IMU_NODE_HPP
#define IMU_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "MTi.h"
#include <cmath>
#include <chrono>
#include <functional>
#include <memory>
#include <iostream>
using namespace std;

class Imu_node : public rclcpp::Node
{
public:
    Imu_node();
    ~Imu_node();
    // void run();

private:
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub;
    
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr imu_eul_pub;
    // North(x)-East(y)-Down(z) Coordinate
    void timer_Callback();
    rclcpp::TimerBase::SharedPtr timer_;
    unique_ptr<MTi> imu;
    int pi;
    size_t count;
};

#endif
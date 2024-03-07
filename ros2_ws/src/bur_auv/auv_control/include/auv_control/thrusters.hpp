#ifndef THRUSTERS_HPP
#define THRUSTERS_HPP

#include "rclcpp/rclcpp.hpp"
#include "auv_msgs/msg/motor_command_list.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "raspi_dma_pwm.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

#define NUMBER_OF_MOTORS 3

class Thrusters : public rclcpp::Node
{
public:
    Thrusters();
private:
    void sub_Callback(const auv_msgs::msg::MotorCommandList::SharedPtr msg);
    rclcpp::Subscription<auv_msgs::msg::MotorCommandList>::SharedPtr ctrl_sub;
    unique_ptr<PWM_obj> motor_[NUMBER_OF_MOTORS];

    // Thrustrs in triangle formation
    /*            0
    //           / \
    //          2   1
    */
    // Directional Vectors
    // North(x)-East(y)-Down(z) Coordinate
    float speed[NUMBER_OF_MOTORS] = { 0 };
    int pi;
};

#endif
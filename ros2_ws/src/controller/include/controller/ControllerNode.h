#ifndef CONTROLLER
#define CONTROLLER

#include <memory> 
#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/wrench.hpp>
#include <std_msgs/msg/header.hpp>
#include <pid.hpp>
#include <algorithm> // clamp
#include <message_filters/subscriber.h>

namespace controller {

  class ControllerNode : public rclcpp::Node {
  public:

    ControllerNode();

  private:

    // publishers

    rclcpp::Publisher<geometry_msgs::msg::Wrench>::SharedPtr pubControlEffort;

    
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subTargetTwist;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subCurrentTwist;

    rclcpp::Time prevTime;

    // implementation
    control_toolbox::Pid linear_x;
    control_toolbox::Pid linear_y;
    control_toolbox::Pid linear_z;

    control_toolbox::Pid angular_x;
    control_toolbox::Pid angular_y;
    control_toolbox::Pid angular_z;

    rclcpp::TimerBase::SharedPtr pubTimer_;

    geometry_msgs::msg::Twist targetTwist;
    geometry_msgs::msg::Twist currentTwist;


    //  callbacks
    void targetTwistCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void currentTwistCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void publishState();

    rclcpp::Time lastTime;
  };
} 

#endif 

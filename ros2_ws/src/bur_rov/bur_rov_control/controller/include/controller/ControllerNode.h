#ifndef CONTROLLER
#define CONTROLLER

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include "bur_rov_msgs/msg/command.hpp"
#include <geometry_msgs/msg/wrench.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <std_msgs/msg/header.hpp>
#include <pid.hpp>
#include <algorithm> // clamp
#include <message_filters/subscriber.h>

namespace controller
{

  class ControllerNode : public rclcpp::Node
  {
  public:
    ControllerNode();

  private:
    // publishers

    rclcpp::Publisher<geometry_msgs::msg::Wrench>::SharedPtr pubControlEffort;

    rclcpp::Subscription<bur_rov_msgs::msg::Command>::SharedPtr state_setpoint_sub;

    rclcpp::Time prevTime;

    // implementation
    control_toolbox::Pid linear_x;
    control_toolbox::Pid linear_y;
    control_toolbox::Pid linear_z;

    control_toolbox::Pid angular_x;
    control_toolbox::Pid angular_y;
    control_toolbox::Pid angular_z;

    rclcpp::TimerBase::SharedPtr pubTimer_;

    // bur_rov_msgs::msg::Command command;
    geometry_msgs::msg::Pose pose_state;
    geometry_msgs::msg::Pose pose_setpoint;
    geometry_msgs::msg::Twist twist_state;
    geometry_msgs::msg::Twist twist_setpoint;

    //  callbacks
    void currentCommandCallback(const bur_rov_msgs::msg::Command::SharedPtr msg);
    void publishState();

    rclcpp::Time lastTime;
  };
} 

#endif

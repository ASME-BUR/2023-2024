#include "joy_command.hpp"

JoyCommand::JoyCommand() : rclcpp::Node("joy_command")
{
    this->declare_parameter("pub_topic", "joy_command/command");
    this->declare_parameter("sub_topic", "joy");
    this->declare_parameter("pose_topic", "pose");
    pub_ = this->create_publisher<bur_rov_msgs::msg::Command>(this->get_parameter("pub_topic").as_string(), 10);
    sub_ = this->create_subscription<sensor_msgs::msg::Joy>(this->get_parameter("sub_topic").as_string(), 10,
                                                            bind(&JoyCommand::joy_callback, this, placeholders::_1));
    poseSub = this->create_subscription<geometry_msgs::msg::Pose>(this->get_parameter("pose_topic").as_string(), 10,
                                                            bind(&JoyCommand::pose_callback, this, placeholders::_1));
}

void JoyCommand::joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
    auto output = bur_rov_msgs::msg::Command();
    output.target_vel.linear.x = -msg->axes[0];
    output.target_vel.linear.y = msg->axes[1];
    output.target_vel.linear.z = 0;
    output.target_vel.angular.x = -msg->axes[3];
    output.target_vel.angular.y = msg->axes[4];
    output.target_vel.angular.z = 0;
    for(uint8_t i = 0; i < msg->buttons.size(); i++){
        output.buttons.push_back(msg->buttons[i]);
    }
    pub_->publish(output);
}

void JoyCommand::pose_callback(const geometry_msgs::msg::Pose::SharedPtr msg)
{
    this->pose = *msg;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JoyCommand>());
    rclcpp::shutdown();
    return 0;
}
#include "behaviortree_cpp/bt_factory.h"

#include "simple_planner.h"
#include "rclcpp/rclcpp.hpp"

SimpleManager::SimpleManager() : rclcpp::Node::Node("simple_manager")
{
    this->declare_parameter("tree", "simple_tree.xml");
    this->declare_parameter("localizer_topic", "/odometry/filtered");
    this->declare_parameter("vision_topic", "/vision");
    this->declare_parameter("tick_rate", 10);

    int tick_rate = this->get_parameter("tick_rate").as_int();

    localizer_sub = this->create_subscription<nav_msgs::msg::Odometry>(
        this->get_parameter("localizer_topic").as_string(), 
        10, std::bind(&SimpleManager::localizer_callback, this, std::placeholders::_1));

    pubTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / tick_rate), 
        std::bind(&SimpleManager::tick_behavior, this));

    BT::BehaviorTreeFactory factory;
    factory.registerBehaviorTreeFromFile(this->get_parameter("tree").as_string());

    this->behavior_tree = factory.createTree("MainTree");

}

void SimpleManager::localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    this->current_pos = msg->pose.pose;
    this->current_vel = msg->twist.twist;
}

void SimpleManager::tick_behavior() {
    this->behavior_tree.tickOnce();
}

int main(int argc, char * argv[])
{

    std::shared_ptr<SimpleManager> manager;

    rclcpp::spin(manager);
    rclcpp::shutdown(); 

    return 0;
}

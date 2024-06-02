#include "behaviortree_cpp_v3/bt_factory.h"
#include "rclcpp/rclcpp.hpp"

#include "bur_planner.h"

#include "nav2_behavior_tree/behavior_tree_engine.hpp"


namespace bur_planner {
    BurPlanner::BurPlanner() : rclcpp::Node::Node("bur_planner")
    {
        this->declare_parameter("localizer_topic", "/odometry/filtered");
        this->declare_parameter("vision_topic", "/vision");
        this->declare_parameter("publish_rate", 10);

        localizer_sub = this->create_subscription<nav_msgs::msg::Odometry>(
            this->get_parameter("localizer_topic").as_string(), 
            10, std::bind(&BurPlanner::localizer_callback, this, std::placeholders::_1));
        
        start_pub = this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "bur_planner/start_position", 1);
        gate_pub = this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "bur_planner/gate_position", 1);
        
        start_position.position.x = 0;
        start_position.position.y = 0;
        start_position.position.z = 0;

        gate_position.position.x = 2;
        gate_position.position.y = 0;
        gate_position.position.z = 0;

        int publish_rate = this->get_parameter("publish_rate").as_int();

        pubTimer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000 / publish_rate), 
            std::bind(&BurPlanner::publish_targets, this));
    }

    void BurPlanner::publish_targets() {
        geometry_msgs::msg::PoseStamped start_msg;
        start_msg.pose = start_position;

        geometry_msgs::msg::PoseStamped gate_msg;
        gate_msg.pose = gate_position;

        start_pub->publish(start_msg);
        gate_pub->publish(gate_msg);
    }

    void BurPlanner::localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        current_pos = msg->pose.pose;
        current_vel = msg->twist.twist;
    }
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<bur_planner::BurPlanner>());

    rclcpp::shutdown();

    return 0;
}

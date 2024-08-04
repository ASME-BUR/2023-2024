#include "manager_node.h"
#include "bt_nodes.h"

#include "tf2/exceptions.h"
#include "rclcpp/rclcpp.hpp"

SimpleManager::SimpleManager() : rclcpp::Node::Node("simple_manager")
{
    this->declare_parameter("localizer_topic", "/odometry/filtered");
    this->declare_parameter("vision_topic", "/vision");

    this->declare_parameter("goal_topic", "/goal_pose");
    this->declare_parameter("pub_rate", 10);

    this->declare_parameter("behavior_tree", "tree.xml");
    this->declare_parameter("tick_rate", 10);

    int pub_rate = this->get_parameter("pub_rate").as_int();
    int tick_rate = this->get_parameter("tick_rate").as_int();

    localizer_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        this->get_parameter("localizer_topic").as_string(), 
        10, std::bind(&SimpleManager::localizer_callback, this, std::placeholders::_1));

    goal_pose_pub_ = this->create_publisher<geometry_msgs::msg::Pose>(
        this->get_parameter("goal_topic").as_string(), 10);

    pubTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / pub_rate), 
        std::bind(&SimpleManager::publish_goal_pose, this));
    btTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / tick_rate), 
        std::bind(&SimpleManager::tick_behavior, this));

    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

}

void SimpleManager::initialize_tree(BT::BehaviorTreeFactory &factory) {
    factory.registerBehaviorTreeFromFile(this->get_parameter("behavior_tree").as_string());
    this->behavior_tree_ = factory.createTree("MainTree");
}

void SimpleManager::localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    try {
        this->baselink2Odom = tf_buffer_->lookupTransform("odom", "base_link", tf2::TimePointZero);
    } catch (const tf2::TransformException& ex) {
        RCLCPP_INFO(this->get_logger(), "Could no transform base_link to odom: %s", ex.what());
    }

    this->current_pos_ = msg->pose.pose;
    this->current_vel_ = msg->twist.twist;
}

void SimpleManager::set_goal_pose(geometry_msgs::msg::Pose target_pos) {
    this->goal_pose_ = target_pos;
}

void SimpleManager::publish_goal_pose() {
    this->goal_pose_pub_->publish(this->goal_pose_);
}

void SimpleManager::tick_behavior() {
    this->behavior_tree_.tickOnce();
}

int main(int argc, char * argv[])
{

    rclcpp::init(argc, argv);

    BT::BehaviorTreeFactory factory;

    auto manager = std::make_shared<SimpleManager>();

    factory.registerNodeType<IncrementCounter>("IncrementCounter", manager);

    manager->initialize_tree(factory);

    rclcpp::spin(manager);
    rclcpp::shutdown(); 

    return 0;
}

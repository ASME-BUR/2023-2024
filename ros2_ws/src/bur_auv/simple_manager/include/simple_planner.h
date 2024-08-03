#include <memory>

#include "behaviortree_cpp/behavior_tree.h"

#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;

class SimpleManager : public rclcpp::Node
{
    public:
        SimpleManager();

    private:

        BT::Tree behavior_tree;
    
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr localizer_sub;
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr vision_sub;

        geometry_msgs::msg::Pose current_pos;
        geometry_msgs::msg::Twist current_vel;

        // Target Locations
        geometry_msgs::msg::Pose gate_position;
        std::vector<geometry_msgs::msg::Pose> marker_poses;
        geometry_msgs::msg::Pose start_position;

        rclcpp::TimerBase::SharedPtr pubTimer_;

        void tick_behavior();

        void localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

};


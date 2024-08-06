#ifndef SIMPLE_MANAGER
#define SIMPLE_MANAGER

#include <memory>

#include "behaviortree_cpp/behavior_tree.h"
#include "behaviortree_cpp/bt_factory.h"

#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"

#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "rclcpp/rclcpp.hpp"


class SimpleManager : public rclcpp::Node
{
    public:
        SimpleManager();

        void initialize_tree(BT::BehaviorTreeFactory &factory);

        geometry_msgs::msg::Pose const getCurrentPosition() { return current_pos_; }
        geometry_msgs::msg::Pose const getStartPosition()   { return start_position_; }
        geometry_msgs::msg::Pose const getGatePosition()    { return gate_position_;}

        void set_goal_pose(geometry_msgs::msg::Pose target_pos);

        // Target Locations
        geometry_msgs::msg::Pose start_position_;
        geometry_msgs::msg::Pose gate_position_;
        std::vector<geometry_msgs::msg::Pose> marker_poses_;

        int i = 0;

    private:
    
        BT::Tree behavior_tree_;

        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr localizer_sub_;
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr vision_sub_;
        
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pose_pub_;

        geometry_msgs::msg::Pose current_pos_;
        geometry_msgs::msg::Twist current_vel_;

        geometry_msgs::msg::Pose goal_pose_;

        geometry_msgs::msg::TransformStamped baselink2Odom;

        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
        std::unique_ptr<tf2_ros::Buffer> tf_buffer_;

        rclcpp::TimerBase::SharedPtr pubTimer_;
        rclcpp::TimerBase::SharedPtr btTimer_;

        void tick_behavior();

        // ROS Callbacks
        void publish_goal_pose();
        void localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

};

#endif

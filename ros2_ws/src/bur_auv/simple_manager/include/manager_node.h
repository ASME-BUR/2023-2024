#ifndef SIMPLE_MANAGER
#define SIMPLE_MANAGER

#include <memory>

#include "behaviortree_cpp/behavior_tree.h"
#include "behaviortree_cpp/bt_factory.h"

#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "yolo_msgs/msg/cv_detection.hpp"
#include "yolo_msgs/msg/cv_detections.hpp"

#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "rclcpp/rclcpp.hpp"

const int YOLO_GATE = 0;
const int YOLO_BUOY = 1;

const int ZED_WIDTH = 1920;
const int ZED_HEIGHT = 1080;

class SimpleManager : public rclcpp::Node
{
    public:
        SimpleManager();

        void initialize_tree(BT::BehaviorTreeFactory &factory);
        void initialize_targets();

        geometry_msgs::msg::Pose const getCurrentPosition() { return current_pos_; }

        void set_goal_pose(geometry_msgs::msg::Pose target_pos);
        void publish_joy_msg(sensor_msgs::msg::Joy joy_msg);
        void publish_odometry_msg(nav_msgs::msg::Odometry);

        // Target Locations
        std::shared_ptr<geometry_msgs::msg::Pose> start_position_;
        std::shared_ptr<geometry_msgs::msg::Pose> gate_position_;
        std::vector<geometry_msgs::msg::Pose> marker_poses_;

        bool buoy_is_left_ = true;
        bool gate_complete = false;

        std::vector<yolo_msgs::msg::CVDetection> detected_;

    private:
    
        BT::Tree behavior_tree_;

        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr localizer_sub_;
        rclcpp::Subscription<yolo_msgs::msg::CVDetections>::SharedPtr vision_sub_;
        rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr depth_sub_;
        
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pose_pub_;
        rclcpp::Publisher<sensor_msgs::msg::Joy>::SharedPtr joy_pub_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odometry_pub_;


        geometry_msgs::msg::Pose current_pos_;
        geometry_msgs::msg::Twist current_vel_;

        geometry_msgs::msg::Pose goal_pose_;

        geometry_msgs::msg::TransformStamped baselink2Odom;

        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
        std::unique_ptr<tf2_ros::Buffer> tf_buffer_;

        rclcpp::TimerBase::SharedPtr pubTimer_;
        rclcpp::TimerBase::SharedPtr btTimer_;

        double depth = 1000;

        void tick_behavior();

        // ROS Callbacks
        void publish_goal_pose();
        void localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
        void vision_callback(const yolo_msgs::msg::CVDetections::SharedPtr msg);
        void depth_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);
};

#endif

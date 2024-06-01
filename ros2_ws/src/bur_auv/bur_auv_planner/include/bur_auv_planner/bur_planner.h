#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include "nav_msgs/msg/odometry.hpp"

namespace bur_planner {
    class BurPlanner : public rclcpp::Node {
        public:
            BurPlanner();

        private:
            rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr localizer_sub;
            rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr vision_sub;

            rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr start_pub;
            // rclcpp::Publisher<vector<geometry_msgs::msg::PoseStamped>>::SharedPtr marker_pub;
            rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr gate_pub;

            geometry_msgs::msg::Pose current_pos;
            geometry_msgs::msg::Twist current_vel;

            // Target Locations
            geometry_msgs::msg::Pose gate_position;
            std::vector<geometry_msgs::msg::Pose> marker_poses;
            geometry_msgs::msg::Pose start_position;

            rclcpp::TimerBase::SharedPtr pubTimer_;

            void publish_targets();

            void localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
            void vision_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    };

}

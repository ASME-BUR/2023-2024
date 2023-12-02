#ifndef ESKF_NODE_HPP_
#define ESKF_NODE_HPP_

#include <memory> 
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/magnetic_field.hpp"
#include "sensor_msgs/msg/range.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <mavros_msgs/msg/optical_flow_rad.hpp>
#include <mavros_msgs/msg/extended_state.hpp>
#include <message_filters/subscriber.h>
#include "ESKF.hpp"

namespace eskf {

  class Node : public rclcpp::Node {
  public:
    static constexpr int default_publish_rate_ = 100;
    static constexpr int default_fusion_mask_ = MASK_EV;

    Node();

  private:

    // publishers

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pubPose_;

    //  subsribers
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subImu_;
    rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr subVisionPose_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subGpsPose_;
    rclcpp::Subscription<sensor_msgs::msg::MagneticField>::SharedPtr subMagPose_;
    rclcpp::Subscription<mavros_msgs::msg::ExtendedState>::SharedPtr subExtendedState_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr subRangeFinderPose_;

    // implementation
    eskf::ESKF eskf_;
    rclcpp::Time prevStampImu_;
    rclcpp::Time prevStampVisionPose_;
    rclcpp::Time prevStampGpsPose_;
    rclcpp::Time prevStampMagPose_;
    rclcpp::Time prevStampRangeFinderPose_;
    rclcpp::TimerBase::SharedPtr pubTimer_;
    bool init_;

    //  callbacks
    void inputCallback(const sensor_msgs::msg::Imu::SharedPtr imuMsg);
    void visionCallback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr poseMsg);
    void gpsCallback(const nav_msgs::msg::Odometry::SharedPtr odomMsg);
    void magCallback(const sensor_msgs::msg::MagneticField::SharedPtr magMsg);
    void extendedStateCallback(const mavros_msgs::msg::ExtendedState::SharedPtr extendedStateMsg);
    void rangeFinderCallback(const sensor_msgs::msg::Range::SharedPtr rangeMsg);
    void publishState();
  };
} //  namespace eskf

#endif // ESKF_NODE_HPP_

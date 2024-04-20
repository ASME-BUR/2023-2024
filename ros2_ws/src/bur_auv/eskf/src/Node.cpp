#include <iostream>

#include "Node.hpp"

namespace eskf
{

  Node::Node() : rclcpp::Node("ESKF_Node")
  {
    this->declare_parameter("fusion_mask", rclcpp::PARAMETER_INTEGER);
    this->declare_parameter("publish_rate", rclcpp::PARAMETER_INTEGER);

    const rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(1)).best_effort().durability_volatile();
    RCLCPP_INFO(this->get_logger(), "Subscribing to imu.");
    subImu_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "imu", qos_profile, std::bind(&Node::inputCallback, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Subscribing to extended state");
    subExtendedState_ = this->create_subscription<mavros_msgs::msg::ExtendedState>(
        "extended_state", 1, std::bind(&Node::extendedStateCallback, this, std::placeholders::_1));

    int fusion_mask = default_fusion_mask_;
    fusion_mask = this->get_parameter("fusion_mask").as_int();

    if ((fusion_mask & MASK_EV_POS) || (fusion_mask & MASK_EV_YAW) || (fusion_mask & MASK_EV_HGT))
    {
      RCLCPP_INFO(this->get_logger(), "Subscribing to vision");
      subVisionPose_ = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
          "vision", 1, std::bind(&Node::visionCallback, this, std::placeholders::_1));
    }
    if ((fusion_mask & MASK_GPS_POS) || (fusion_mask & MASK_GPS_VEL) || (fusion_mask & MASK_GPS_HGT))
    {
      RCLCPP_INFO(this->get_logger(), "Subscribing to gps");
      subGpsPose_ = this->create_subscription<nav_msgs::msg::Odometry>(
          "gps", 1, std::bind(&Node::gpsCallback, this, std::placeholders::_1));
    }
    if (fusion_mask & MASK_MAG_HEADING)
    {
      RCLCPP_INFO(this->get_logger(), "Subscribing to mag");
      subMagPose_ = this->create_subscription<sensor_msgs::msg::MagneticField>(
          "mag", 1, std::bind(&Node::magCallback, this, std::placeholders::_1));
    }
    if (fusion_mask & MASK_RANGEFINDER)
    {
      RCLCPP_INFO(this->get_logger(), "Subscribing to rangefinder");
      subRangeFinderPose_ = this->create_subscription<sensor_msgs::msg::Range>(
          "rangefinder", 1, std::bind(&Node::rangeFinderCallback, this, std::placeholders::_1));
    }

    eskf_.setFusionMask(fusion_mask);

    pubPose_ = this->create_publisher<nav_msgs::msg::Odometry>("pose", 1);

    int publish_rate = default_publish_rate_;
    publish_rate = this->get_parameter("publish_rate").as_int();

    pubTimer_ = this->create_wall_timer(
        std::chrono::seconds(static_cast<int>(1.0 / publish_rate)), std::bind(&Node::publishState, this));
  }


  void Node::inputCallback(const sensor_msgs::msg::Imu::SharedPtr imuMsg)
  {
    RCLCPP_INFO(this->get_logger(), "Callback Entered");
    vec3 wm = vec3(imuMsg->angular_velocity.x, imuMsg->angular_velocity.y, imuMsg->angular_velocity.z);          //  measured angular rate
    vec3 am = vec3(imuMsg->linear_acceleration.x, imuMsg->linear_acceleration.y, imuMsg->linear_acceleration.z); //  measured linear acceleration

    rclcpp::Time header_time;
    //change later
    // header_time = this->get_clock()->now();
    header_time = imuMsg.header.stamp;
    
    if (prevStampImu_.seconds() != 0)
    {
      // const double delta = (header_time - prevStampImu_).seconds();
      rclcpp::Duration diff = header_time - prevStampImu_;
        auto num_of_ns = diff.to_chrono<std::chrono::nanoseconds>();
        double delta = num_of_ns.count();

      if (!init_)
      {
        init_ = true;
        RCLCPP_INFO(this->get_logger(), "Initialized ESKF");
      }

       
      //  run kalman filter
      eskf_.run(wm, am, static_cast<uint64_t>(header_time.seconds())/1e6f, delta * 1e-9);
      // RCLCPP_INFO(this->get_logger(), "ESKF Updated");
    }
    prevStampImu_ = header_time;
  }

  void Node::visionCallback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr poseMsg)
  {
    // RCLCPP_INFO(this->get_logger(), "Vision Callback Entered");
    rclcpp::Time header_time;
    // header_time = rclcpp::Time(static_cast<int32_t>(poseMsg->header.stamp.sec), static_cast<uint32_t>(poseMsg->header.stamp.nanosec), RCL_SYSTEM_TIME);
    // header_time = this->get_clock()->now();
    header_time = poseMsg.header.stamp
    if (prevStampVisionPose_.seconds() != 0)
    {
        rclcpp::Duration diff = header_time - prevStampVisionPose_;
        auto num_of_ns = diff.to_chrono<std::chrono::nanoseconds>();
        double delta = num_of_ns.count();
      // get measurements
      quat z_q = quat(poseMsg->pose.pose.orientation.w, poseMsg->pose.pose.orientation.x, poseMsg->pose.pose.orientation.y, poseMsg->pose.pose.orientation.z);
      vec3 z_p = vec3(poseMsg->pose.pose.position.x, poseMsg->pose.pose.position.y, poseMsg->pose.pose.position.z);
      // update vision
      std::cout<<z_p<<std::endl;
      eskf_.updateVision(z_q, z_p, static_cast<uint64_t>(header_time.seconds()/1e6f), delta * 1e-9);
      //  RCLCPP_INFO(this->get_logger(), "Vision Updated");
    }
    prevStampVisionPose_ = header_time;
  }

  void Node::gpsCallback(const nav_msgs::msg::Odometry::SharedPtr odomMsg)
  {
    rclcpp::Time header_time;
    header_time = rclcpp::Time(static_cast<int32_t>(odomMsg->header.stamp.sec), static_cast<uint32_t>(odomMsg->header.stamp.nanosec), RCL_SYSTEM_TIME);
    if (prevStampGpsPose_.seconds() != 0)
    {
      const double delta = (header_time - prevStampGpsPose_).seconds();

      // get gps measurements
      vec3 z_v = vec3(odomMsg->twist.twist.linear.x, odomMsg->twist.twist.linear.y, odomMsg->twist.twist.linear.z);
      vec3 z_p = vec3(odomMsg->pose.pose.position.x, odomMsg->pose.pose.position.y, odomMsg->pose.pose.position.z);
      // update gps
      eskf_.updateGps(z_v, z_p, static_cast<uint64_t>(header_time.seconds()/1e6f), delta * 1e-9);
    }
    prevStampGpsPose_ = header_time;
  }

  void Node::magCallback(const sensor_msgs::msg::MagneticField::SharedPtr magMsg)
  {
    rclcpp::Time header_time;
    header_time = rclcpp::Time(static_cast<int32_t>(magMsg->header.stamp.sec), static_cast<uint32_t>(magMsg->header.stamp.nanosec), RCL_SYSTEM_TIME);
    if (prevStampMagPose_.seconds() != 0)
    {
      const double delta = (header_time - prevStampMagPose_).seconds();

      // get mag measurements
      vec3 m = vec3(magMsg->magnetic_field.x * 1e4f, magMsg->magnetic_field.y * 1e4f, magMsg->magnetic_field.z * 1e4f);
      eskf_.updateMagnetometer(m, static_cast<uint64_t>(header_time.seconds()/1e6f), delta * 1e-9);
    }
    prevStampMagPose_ = header_time;
  }

  void Node::rangeFinderCallback(const sensor_msgs::msg::Range::SharedPtr rangeMsg)
  {
    rclcpp::Time header_time;
    header_time = rclcpp::Time(static_cast<int32_t>(rangeMsg->header.stamp.sec), static_cast<uint32_t>(rangeMsg->header.stamp.nanosec), RCL_SYSTEM_TIME);
    if (prevStampRangeFinderPose_.seconds() != 0)
    {
      const double delta = (header_time - prevStampRangeFinderPose_).seconds();

      // get rangefinder measurements
      eskf_.updateRangeFinder(rangeMsg->range, static_cast<uint64_t>(header_time.seconds()/1e6f), delta * 1e-9);
    }
    prevStampRangeFinderPose_ = header_time;
  }

  void Node::extendedStateCallback(const mavros_msgs::msg::ExtendedState::SharedPtr extendedStateMsg)
  {
    eskf_.updateLandedState(extendedStateMsg->landed_state & mavros_msgs::msg::ExtendedState::LANDED_STATE_IN_AIR);
  }

  void Node::publishState()
  {

    // get kalman filter result
    const quat e2g = eskf_.getQuat();
    const vec3 position = eskf_.getPosition();
    const vec3 velocity = eskf_.getVelocity();

    static size_t trace_id_ = 0;
    std_msgs::msg::Header header;
    header.frame_id = "map";
    header.stamp = this->get_clock()->now();

    nav_msgs::msg::Odometry odom;
    odom.header = header;
    odom.pose.pose.position.x = position[0];
    odom.pose.pose.position.y = position[1];
    odom.pose.pose.position.z = position[2];
    odom.twist.twist.linear.x = velocity[0];
    odom.twist.twist.linear.y = velocity[1];
    odom.twist.twist.linear.z = velocity[2];
    odom.pose.pose.orientation.w = e2g.w();
    odom.pose.pose.orientation.x = e2g.x();
    odom.pose.pose.orientation.y = e2g.y();
    odom.pose.pose.orientation.z = e2g.z();

    pubPose_->publish(odom);
    RCLCPP_INFO(this->get_logger(), "Pose Published");
  }

}
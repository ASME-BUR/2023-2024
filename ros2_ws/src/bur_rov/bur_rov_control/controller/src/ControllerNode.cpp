#include "ControllerNode.hpp"
#include <iostream>
namespace controller
{
  template <typename T>
  T clamp(T val, T low, T high)
  {
    if (val < low)
    {
      return low;
    }
    else if (val > high)
    {
      return high;
    }
    return val;
  }

  ControllerNode::ControllerNode() : rclcpp::Node::Node("bur_controller")
  {

    this->declare_parameter("sub_topic", "command");
    this->declare_parameter("pub_topic", "control_effort");
    this->declare_parameter("publish_rate", 100);

    state_setpoint_sub = this->create_subscription<bur_rov_msgs::msg::Command>(
        this->get_parameter("sub_topic").as_string(), 1,
        std::bind(&ControllerNode::currentCommandCallback, this, std::placeholders::_1));

    pubControlEffort = this->create_publisher<geometry_msgs::msg::WrenchStamped>(
        this->get_parameter("pub_topic").as_string(), 1);

    int publish_rate = this->get_parameter("publish_rate").as_int();

    pubTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / publish_rate), std::bind(&ControllerNode::publishState, this));

    linear_x = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    linear_y = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    linear_z = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);

    angular_x = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    angular_y = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    angular_z = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);

    this->declare_parameter("linear_x/p", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("linear_x/i", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("linear_x/d", rclcpp::PARAMETER_DOUBLE);

    this->declare_parameter("linear_y/p", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("linear_y/i", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("linear_y/d", rclcpp::PARAMETER_DOUBLE);

    this->declare_parameter("linear_z/p", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("linear_z/i", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("linear_z/d", rclcpp::PARAMETER_DOUBLE);

    this->declare_parameter("angular_x/p", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("angular_x/i", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("angular_x/d", rclcpp::PARAMETER_DOUBLE);

    this->declare_parameter("angular_y/p", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("angular_y/i", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("angular_y/d", rclcpp::PARAMETER_DOUBLE);

    this->declare_parameter("angular_z/p", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("angular_z/i", rclcpp::PARAMETER_DOUBLE);
    this->declare_parameter("angular_z/d", rclcpp::PARAMETER_DOUBLE);
  }

  void ControllerNode::currentCommandCallback(const bur_rov_msgs::msg::Command::SharedPtr msg)
  {
    pose_state = msg->current_pos;
    pose_setpoint = msg->target_pos;
    twist_state = msg->current_vel;
    twist_setpoint = msg->target_vel;
    active = msg->buttons[13];
    double roll_state, pitch_state, yaw_state;
    tf2::Quaternion q = tf2::Quaternion(msg->current_pos.orientation.x, msg->current_pos.orientation.y, msg->current_pos.orientation.z, msg->current_pos.orientation.w);
    tf2::Matrix3x3 rot_matrix = tf2::Matrix3x3(q);
    rot_matrix.getRPY(roll_state, pitch_state, yaw_state);
    state_angle = tf2::Vector3(roll_state, pitch_state, yaw_state);
    double roll_setpoint, pitch_setpoint, yaw_setpoint;
    q = tf2::Quaternion(msg->target_pos.orientation.x, msg->target_pos.orientation.y, msg->target_pos.orientation.z, msg->target_pos.orientation.w);
    rot_matrix = tf2::Matrix3x3(q);
    rot_matrix.getRPY(roll_setpoint, pitch_setpoint, yaw_setpoint);
    if (abs(twist_setpoint.angular.z) <= 0.1 && yaw_hold == false)
    {
      yaw_setpoint = yaw_state;
      yaw_hold_pos = yaw_state;
      yaw_hold = true;
    }
    else if (yaw_hold && abs(twist_setpoint.angular.z) <= 0.1)
    {
      yaw_setpoint = yaw_hold_pos;
    }
    else
    {
      yaw_hold = false;
    }
    setpoint_angle = tf2::Vector3(roll_setpoint, pitch_setpoint, yaw_setpoint);
    if (abs(twist_setpoint.linear.z) <= 0.1 && depth_hold == false)
    {
      pose_setpoint.position.z = msg->current_pos.position.z;
      depth_hold = true;
    }
    else
    {
      depth_hold = false;
    }
  }

  void ControllerNode::publishState()
  {
    if (active)
    {
      linear_x.setGains(this->get_parameter("linear_x/p").as_double(), this->get_parameter("linear_x/i").as_double(), this->get_parameter("linear_x/d").as_double(), 1.0, -1.0, true);
      linear_y.setGains(this->get_parameter("linear_y/p").as_double(), this->get_parameter("linear_y/i").as_double(), this->get_parameter("linear_y/d").as_double(), 1.0, -1.0, true);
      linear_z.setGains(this->get_parameter("linear_z/p").as_double(), this->get_parameter("linear_z/i").as_double(), this->get_parameter("linear_z/d").as_double(), 1.0, -1.0, true);

      angular_x.setGains(this->get_parameter("angular_x/p").as_double(), this->get_parameter("angular_x/i").as_double(), this->get_parameter("angular_x/d").as_double(), 1.0, -1.0, true);
      angular_y.setGains(this->get_parameter("angular_y/p").as_double(), this->get_parameter("angular_y/i").as_double(), this->get_parameter("angular_y/d").as_double(), 1.0, -1.0, true);
      angular_z.setGains(this->get_parameter("angular_z/p").as_double(), this->get_parameter("angular_z/i").as_double(), this->get_parameter("angular_z/d").as_double(), 1.0, -1.0, true);

      rclcpp::Time time = this->now(); // might have to change the now ????
      if (lastTime.seconds() != 0)
      {
        double dt = (time - lastTime).nanoseconds();
        if (dt != 0)
        {
          geometry_msgs::msg::WrenchStamped controlEffort;
          controlEffort.header.stamp = this->now();
          controlEffort.header.frame_id = "map";
          controlEffort.wrench.force.x = linear_x.computeCommand(twist_setpoint.linear.x - twist_state.linear.x, dt);
          controlEffort.wrench.force.y = linear_y.computeCommand(twist_setpoint.linear.y - twist_state.linear.y, dt);
          // std::cout << pose_setpoint.position.z << std::endl;
          // std::cout << pose_state.position.z << std::endl;
          std::cout << twist_setpoint.linear.z << std::endl;
          std::cout << twist_state.linear.z << std::endl;
          if (depth_hold)
          {
            RCLCPP_INFO(this->get_logger(), "depth hold");
            controlEffort.wrench.force.z = linear_z.computeCommand(pose_setpoint.position.z - pose_state.position.z, dt);
            // std::cout << controlEffort.wrench.force.z << std::endl;
          }
          else
          {
            controlEffort.wrench.force.z = linear_z.computeCommand(twist_setpoint.linear.z - twist_state.linear.z, dt);
            // std::cout << controlEffort.wrench.force.z << std::endl;
            depth_hold = false;
          }

          if (yaw_hold)
          {
            RCLCPP_INFO(this->get_logger(), "yaw hold");
            controlEffort.wrench.torque.z = angular_z.computeCommand(angle_wrap_pi(setpoint_angle.getZ() - state_angle.getZ()), dt);
            std::cout << "torque z: " << controlEffort.wrench.torque.z << std::endl;
          }
          else
          {
            controlEffort.wrench.torque.z = angular_z.computeCommand(twist_setpoint.angular.z - twist_state.angular.z, dt);
            std::cout << "torque z: " << controlEffort.wrench.torque.z << std::endl;
            yaw_hold = false;
          }
          controlEffort.wrench.torque.x = angular_x.computeCommand(angle_wrap_pi(setpoint_angle.getX() - state_angle.getX()), dt);
          controlEffort.wrench.torque.y = angular_y.computeCommand(angle_wrap_pi(setpoint_angle.getY() - state_angle.getY()), dt);

          pubControlEffort->publish(controlEffort);
        }
      }
      lastTime = time;
    }
    else
    {
      geometry_msgs::msg::WrenchStamped controlEffort;
      controlEffort.header.stamp = this->now();
      controlEffort.header.frame_id = "map";
      controlEffort.wrench.force.x = 0;
      controlEffort.wrench.force.y = 0;
      controlEffort.wrench.force.z = 0;

      controlEffort.wrench.torque.x = 0;
      controlEffort.wrench.torque.y = 0;
      controlEffort.wrench.torque.z = 0;

      pubControlEffort->publish(controlEffort);
    }
  }
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<controller::ControllerNode>());

  rclcpp::shutdown();
  return 0;
}
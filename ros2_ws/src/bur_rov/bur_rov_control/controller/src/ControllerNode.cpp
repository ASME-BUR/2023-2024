#include "ControllerNode.h"
#include <Eigen/Dense>

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

    this->declare_parameter("linear_x/p", 0.0);
    this->declare_parameter("linear_x/i", 0.0);
    this->declare_parameter("linear_x/d", 0.0);

    this->declare_parameter("linear_y/p", 0.0);
    this->declare_parameter("linear_y/i", 0.0);
    this->declare_parameter("linear_y/d", 0.0);

    this->declare_parameter("linear_z/p", 0.0);
    this->declare_parameter("linear_z/i", 0.0);
    this->declare_parameter("linear_z/d", 0.0);

    this->declare_parameter("angular_x/p", 0.0);
    this->declare_parameter("angular_x/i", 0.0);
    this->declare_parameter("angular_x/d", 0.0);

    this->declare_parameter("angular_y/p", 0.0);
    this->declare_parameter("angular_y/i", 0.0);
    this->declare_parameter("angular_y/d", 0.0);

    this->declare_parameter("angular_z/p", 0.0);
    this->declare_parameter("angular_z/i", 0.0);
    this->declare_parameter("angular_z/d", 0.0);
  }

  rcl_interfaces::msg::SetParametersResult ControllerNode::parametersCallback(
      const std::vector<rclcpp::Parameter> &parameters)
  {
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "success";
    for (const auto &param : parameters)
    {
      RCLCPP_INFO(this->get_logger(), "%s", param.get_name().c_str());
      RCLCPP_INFO(this->get_logger(), "%s", param.get_type_name().c_str());
      RCLCPP_INFO(this->get_logger(), "%s", param.value_to_string().c_str());
    }
    new_params = true;
    return result;
  }

  void ControllerNode::setConstants()
  {
    RCLCPP_INFO(this->get_logger(), "Setting PID Gains");
    linear_x.setGains(this->get_parameter("linear_x/p").as_double(), this->get_parameter("linear_x/i").as_double(), this->get_parameter("linear_x/d").as_double(), 1.0, -1.0, true);
    linear_y.setGains(this->get_parameter("linear_y/p").as_double(), this->get_parameter("linear_y/i").as_double(), this->get_parameter("linear_y/d").as_double(), 1.0, -1.0, true);
    linear_z.setGains(this->get_parameter("linear_z/p").as_double(), this->get_parameter("linear_z/i").as_double(), this->get_parameter("linear_z/d").as_double(), 1.0, -1.0, true);
    angular_x.setGains(this->get_parameter("angular_x/p").as_double(), this->get_parameter("angular_x/i").as_double(), this->get_parameter("angular_x/d").as_double(), 1.0, -1.0, true);
    angular_y.setGains(this->get_parameter("angular_y/p").as_double(), this->get_parameter("angular_y/i").as_double(), this->get_parameter("angular_y/d").as_double(), 1.0, -1.0, true);
    angular_z.setGains(this->get_parameter("angular_z/p").as_double(), this->get_parameter("angular_z/i").as_double(), this->get_parameter("angular_z/d").as_double(), 1.0, -1.0, true);
    new_params = false;
  }

  void ControllerNode::currentCommandCallback(const bur_rov_msgs::msg::Command::SharedPtr msg)
  {
    pose_state = msg->current_pos;
    pose_setpoint = msg->target_pos;
    twist_state = msg->current_vel;
    twist_setpoint = msg->target_vel;
    active = msg->buttons[13];
    state_angle = ToEulerAngles(msg->current_pos.orientation.w, msg->current_pos.orientation.x, msg->current_pos.orientation.y, msg->current_pos.orientation.z);
    if (abs(twist_setpoint.linear.z) <= 0.1)
    {
      pose_setpoint.position.z = pose_state.position.z;
    }
    if (abs(twist_setpoint.angular.z) <= 0.1)
    {
      setpoint_angle = ToEulerAngles(pose_setpoint.orientation.w, pose_setpoint.orientation.x, pose_setpoint.orientation.y, pose_setpoint.orientation.z);
    }
  }

  void ControllerNode::publishState()
  {
    geometry_msgs::msg::WrenchStamped controlEffort;
    controlEffort.header.stamp = this->get_clock()->now();
    if (active)
    {
      rclcpp::Time time = this->get_clock()->now(); // might have to change the now ????
      if (new_params)
      {
        setConstants();
      }
      if (lastTime.seconds() != 0)
      {
        double dt = (time - lastTime).nanoseconds();
        if (dt != 0)
        {
          controlEffort.wrench.force.x = linear_x.computeCommand(twist_setpoint.linear.x - twist_state.linear.x, dt);
          controlEffort.wrench.force.y = linear_y.computeCommand(twist_setpoint.linear.y - twist_state.linear.y, dt);

          if (abs(twist_setpoint.linear.z) <= 0)
          {
            RCLCPP_INFO(this->get_logger(), "depth hold");
            controlEffort.wrench.force.z = linear_z.computeCommand(pose_setpoint.position.z - pose_state.position.z, dt);
          }
          else
          {
            controlEffort.wrench.force.z = linear_z.computeCommand(twist_setpoint.linear.z - twist_state.linear.z, dt);
          }
          if (abs(twist_setpoint.angular.z) <= 0)
          {
            RCLCPP_INFO(this->get_logger(), "yaw hold");
            controlEffort.wrench.torque.z = angular_z.computeCommand(angle_wrap_pi(setpoint_angle.z - state_angle.z), dt);
          }
          else
          {
            controlEffort.wrench.torque.z = angular_z.computeCommand(twist_setpoint.angular.z - twist_state.angular.z, dt);
          }

          // Eigen::Quaternionf currentQuaternion(pose_state.orientation.w, pose_state.orientation.x, pose_state.orientation.y, pose_state.orientation.z);            // Example current quaternion (w, x, y, z)
          // Eigen::Quaternionf targetQuaternion(pose_setpoint.orientation.w, pose_setpoint.orientation.x, pose_setpoint.orientation.y, pose_setpoint.orientation.z); // Example target quaternion (w, x, y, z)

          // Extracting roll and pitch from quaternions
          // double currentRoll = atan2(2 * (currentQuaternion.w() * currentQuaternion.x() + currentQuaternion.y() * currentQuaternion.z()),
          //  1 - 2 * (currentQuaternion.x() * currentQuaternion.x() + currentQuaternion.y() * currentQuaternion.y()));
          // double currentPitch = asin(2 * (currentQuaternion.w() * currentQuaternion.y() - currentQuaternion.z() * currentQuaternion.x()));

          // double targetRoll = atan2(2 * (targetQuaternion.w() * targetQuaternion.x() + targetQuaternion.y() * targetQuaternion.z()),
          // 1 - 2 * (targetQuaternion.x() * targetQuaternion.x() + targetQuaternion.y() * targetQuaternion.y()));
          // double targetPitch = asin(2 * (targetQuaternion.w() * targetQuaternion.y() - targetQuaternion.z() * targetQuaternion.x()));

          controlEffort.wrench.torque.x = angular_x.computeCommand(angle_wrap_pi(setpoint_angle.x - state_angle.x), dt);
          controlEffort.wrench.torque.y = angular_y.computeCommand(angle_wrap_pi(setpoint_angle.y - state_angle.y), dt);
        }
      }
      lastTime = time;
    }
    else
    {
      controlEffort.wrench.force.x = 0;
      controlEffort.wrench.force.y = 0;
      controlEffort.wrench.force.z = 0;
      controlEffort.wrench.torque.x = 0;
      controlEffort.wrench.torque.y = 0;
      controlEffort.wrench.torque.z = 0;
    }
    pubControlEffort->publish(controlEffort);
  }
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<controller::ControllerNode>());

  rclcpp::shutdown();
  return 0;
}
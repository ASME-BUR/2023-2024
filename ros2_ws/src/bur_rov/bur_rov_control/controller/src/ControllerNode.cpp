#include "ControllerNode.hpp"
#include <iostream>
namespace controller
{

  ControllerNode::ControllerNode() : rclcpp::Node::Node("bur_controller")
  {

    this->declare_parameter("sub_topic", "command");
    this->declare_parameter("target_vel_topic", "/cmd_vel");
    this->declare_parameter("pub_topic", "control_effort");
    this->declare_parameter("publish_rate", 100);
    this->declare_parameter("use_command_target", false);
    this->declare_parameter("using_joy", true);

    state_setpoint_sub = this->create_subscription<bur_rov_msgs::msg::Command>(
        this->get_parameter("sub_topic").as_string(), 1,
        std::bind(&ControllerNode::currentCommandCallback, this, std::placeholders::_1));

    param_callback = this->add_on_set_parameters_callback(bind(&ControllerNode::parametersCallback, this, std::placeholders::_1));
    pubControlEffort = this->create_publisher<geometry_msgs::msg::WrenchStamped>(this->get_parameter("pub_topic").as_string(), 1);

    int publish_rate = this->get_parameter("publish_rate").as_int();

    pubTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / publish_rate), std::bind(&ControllerNode::publishState, this));

    linear_x = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    linear_y = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    linear_z = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);

    angular_x = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    angular_y = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
    angular_z = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);

    this->declare_parameter("max_force", 100.0);
    this->declare_parameter("max_torque", 60.0);

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

    set_constants();
  }

  void ControllerNode::set_constants()
  {
    double max_force = this->get_parameter("max_force").as_double();
    double max_torque = this->get_parameter("max_torque").as_double();
    using_joy = this->get_parameter("using_joy").as_bool();
    linear_x.setGains(this->get_parameter("linear_x/p").as_double(), this->get_parameter("linear_x/i").as_double(), this->get_parameter("linear_x/d").as_double(), max_force, -max_force, true);
    linear_y.setGains(this->get_parameter("linear_y/p").as_double(), this->get_parameter("linear_y/i").as_double(), this->get_parameter("linear_y/d").as_double(), max_force, -max_force, true);
    linear_z.setGains(this->get_parameter("linear_z/p").as_double(), this->get_parameter("linear_z/i").as_double(), this->get_parameter("linear_z/d").as_double(), max_force, -max_force, true);

    angular_x.setGains(this->get_parameter("angular_x/p").as_double(), this->get_parameter("angular_x/i").as_double(), this->get_parameter("angular_x/d").as_double(), max_torque, -max_torque, true);
    angular_y.setGains(this->get_parameter("angular_y/p").as_double(), this->get_parameter("angular_y/i").as_double(), this->get_parameter("angular_y/d").as_double(), max_torque, -max_torque, true);
    angular_z.setGains(this->get_parameter("angular_z/p").as_double(), this->get_parameter("angular_z/i").as_double(), this->get_parameter("angular_z/d").as_double(), max_torque, -max_torque, true);
    new_params = false;
  }

  rcl_interfaces::msg::SetParametersResult ControllerNode::parametersCallback(const std::vector<rclcpp::Parameter> &parameters)
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

  void ControllerNode::currentCommandCallback(const bur_rov_msgs::msg::Command::SharedPtr msg)
  {
    pose_state = msg->current_pos.pose;
    pose_setpoint = msg->target_pos.pose;

    twist_state = msg->current_vel.twist;
    twist_setpoint = msg->target_vel.twist;

    if (using_joy)
    {
      if (!msg->buttons.empty())
      {
        active = msg->buttons[9];
      }
      else
      {
        active = false;
      }
    }
    else
    {
      active = true;
    }

    if (active)
    {
      double roll_state, pitch_state, yaw_state;
      tf2::Quaternion q = tf2::Quaternion(msg->current_pos.pose.orientation.x, msg->current_pos.pose.orientation.y, msg->current_pos.pose.orientation.z, msg->current_pos.pose.orientation.w);
      tf2::Matrix3x3 rot_matrix = tf2::Matrix3x3(q);
      rot_matrix.getRPY(roll_state, pitch_state, yaw_state);
      state_angle = tf2::Vector3(roll_state, pitch_state, yaw_state);

      double roll_setpoint, pitch_setpoint, yaw_setpoint;
      q = tf2::Quaternion(msg->target_pos.pose.orientation.x, msg->target_pos.pose.orientation.y, msg->target_pos.pose.orientation.z, msg->target_pos.pose.orientation.w);
      std::cout << msg->target_pos.pose.orientation.x << msg->target_pos.pose.orientation.y << msg->target_pos.pose.orientation.z << msg->target_pos.pose.orientation.w << std::endl;
      rot_matrix = tf2::Matrix3x3(q);
      rot_matrix.getRPY(roll_setpoint, pitch_setpoint, yaw_setpoint);

      // Yaw hold
      if (yaw_setpoint != 0)
      {
        yaw_hold = true;
      }
      else
      {
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
      }
      // Roll hold
      if (abs(twist_setpoint.angular.x) <= 0.1 && roll_hold == false)
      {
        roll_setpoint = 0;
        roll_hold_pos = 0;
        roll_hold = true;
      }
      else if (roll_hold && abs(twist_setpoint.angular.x) <= 0.1)
      {
        roll_setpoint = roll_hold_pos;
      }
      else
      {
        roll_hold = false;
      }
      // Pitch hold
      if (abs(twist_setpoint.angular.y) <= 0.1 && pitch_hold == false)
      {
        pitch_setpoint = pitch_state;
        pitch_hold_pos = pitch_state;
        pitch_hold = true;
      }
      else if (pitch_hold && abs(twist_setpoint.angular.y) <= 0.1)
      {
        pitch_setpoint = pitch_hold_pos;
      }
      else
      {
        pitch_hold = false;
      }

      setpoint_angle = tf2::Vector3(roll_setpoint, pitch_setpoint, yaw_setpoint);
    }
  }

  void ControllerNode::publishState()
  {
    if (active)
    {
      if (new_params)
      {
        set_constants();
      }
      rclcpp::Time time = this->now(); // might have to change the now ????
      if (lastTime.seconds() != 0)
      {
        double dt = (time - lastTime).nanoseconds();
        if (dt != 0)
        {
          geometry_msgs::msg::WrenchStamped controlEffort;
          controlEffort.header.stamp = this->now();
          controlEffort.header.frame_id = "base_link";
          controlEffort.wrench.force.x = -linear_x.computeCommand(twist_setpoint.linear.x - twist_state.linear.x, dt);
          controlEffort.wrench.force.y = -linear_y.computeCommand(twist_setpoint.linear.y - twist_state.linear.y, dt);
          controlEffort.wrench.force.z = linear_z.computeCommand(pose_setpoint.position.z - pose_state.position.z, dt);
          std::cout << "state: " << state_angle.getX() << " " << state_angle.getY() << " " << state_angle.getZ() << std::endl;
          std::cout << "setpoint: " << setpoint_angle.getX() << " " << setpoint_angle.getY() << " " << setpoint_angle.getZ() << std::endl;
          // std::cout << "angle_wrap x: " << angle_wrap_pi(setpoint_angle.getX() - state_angle.getX()) << std::endl;
          // std::cout << "angle_wrap y: " << angle_wrap_pi(setpoint_angle.getY() - state_angle.getY()) << std::endl;
          // std::cout << pose_setpoint.position.z << std::endl;
          // std::cout << pose_state.position.z << std::endl;
          // std::cout << twist_setpoint.linear.z << std::endl;
          // std::cout << twist_state.linear.z << std::endl;

          if (yaw_hold)
          {
            // RCLCPP_INFO(this->get_logger(), "yaw hold");
            controlEffort.wrench.torque.z = angular_z.computeCommand(angle_wrap_pi(setpoint_angle.getZ() - state_angle.getZ()), dt);
          }
          else
          {
            controlEffort.wrench.torque.z = angular_z.computeCommand(twist_setpoint.angular.z - twist_state.angular.z, dt);
          }

          if (roll_hold)
          {
            controlEffort.wrench.torque.x = angular_x.computeCommand(angle_wrap_pi(setpoint_angle.getX() - state_angle.getX()), dt);
          }
          else
          {
            controlEffort.wrench.torque.x = angular_x.computeCommand(twist_setpoint.angular.x - twist_state.angular.x, dt);
          }

          if (pitch_hold)
          {
            controlEffort.wrench.torque.y = angular_y.computeCommand(angle_wrap_pi(setpoint_angle.getY() - state_angle.getY()), dt);
          }
          else
          {
            controlEffort.wrench.torque.y = angular_y.computeCommand(twist_setpoint.angular.y - twist_state.angular.y, dt);
          }

          pubControlEffort->publish(controlEffort);
        }
      }
      lastTime = time;
    }
    else
    {
      geometry_msgs::msg::WrenchStamped controlEffort;
      controlEffort.header.stamp = this->now();
      controlEffort.header.frame_id = "base_link";
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
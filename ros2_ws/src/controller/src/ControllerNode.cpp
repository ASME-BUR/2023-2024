#include "ControllerNode.h"

namespace controller
{
    template <typename T>
T clamp(T val, T low, T high)
{
  if (val < low) {
    return low;
  } else if (val > high) {
    return high;
  }
  return val;
}

    ControllerNode::ControllerNode():rclcpp::Node::Node("bur_controller") {
        subTargetTwist = this->create_subscription<geometry_msgs::msg::Twist>(
      "target_twist", 1, std::bind(&ControllerNode::targetTwistCallback, this, std::placeholders::_1));
        subCurrentTwist = this->create_subscription<geometry_msgs::msg::Twist>(
      "current_twist", 1, std::bind(&ControllerNode::currentTwistCallback, this, std::placeholders::_1));

        pubControlEffort = this->create_publisher<geometry_msgs::msg::Wrench>("control_effort",1);

        int publish_rate = 100;
        // publish_rate = this->get_parameter("~publish_rate").as_int();

        pubTimer_ = this->create_wall_timer(
        std::chrono::seconds(static_cast<int>(1.0/publish_rate)), std::bind(&ControllerNode::publishState, this));


        linear_x = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
        linear_y = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
        linear_z = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);

        angular_x = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
        angular_y = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);
        angular_z = control_toolbox::Pid(0.0, 0.0, 0.0, 1.0, -1.0, true);

        this->declare_parameter("~linear_x/p", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~linear_x/i", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~linear_x/d", rclcpp::PARAMETER_DOUBLE);

        this->declare_parameter("~linear_y/p", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~linear_y/i", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~linear_y/d", rclcpp::PARAMETER_DOUBLE);

        this->declare_parameter("~linear_z/p", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~linear_z/i", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~linear_z/d", rclcpp::PARAMETER_DOUBLE);

        this->declare_parameter("~angular_x/p", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~angular_x/i", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~angular_x/d", rclcpp::PARAMETER_DOUBLE);

        this->declare_parameter("~angular_y/p", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~angular_y/i", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~angular_y/d", rclcpp::PARAMETER_DOUBLE);

        this->declare_parameter("~angular_z/p", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~angular_z/i", rclcpp::PARAMETER_DOUBLE);
        this->declare_parameter("~angular_z/d", rclcpp::PARAMETER_DOUBLE);
    }


    void ControllerNode::targetTwistCallback(const geometry_msgs::msg::Twist::SharedPtr msg){
        this->targetTwist = *msg;
    }
    void ControllerNode::currentTwistCallback(const geometry_msgs::msg::Twist::SharedPtr msg){
        this->currentTwist = *msg;
    }

    void ControllerNode::publishState(){
        linear_x.setGains(this->get_parameter("~linear_x/p").as_double(), this->get_parameter("~linear_x/i").as_double(), this->get_parameter("~linear_x/d").as_double(), 1.0, -1.0, true);
        linear_y.setGains(this->get_parameter("~linear_y/p").as_double(), this->get_parameter("~linear_y/i").as_double(), this->get_parameter("~linear_y/d").as_double(), 1.0, -1.0, true);
        linear_z.setGains(this->get_parameter("~linear_z/p").as_double(), this->get_parameter("~linear_z/i").as_double(), this->get_parameter("~linear_z/d").as_double(), 1.0, -1.0, true);

        angular_x.setGains(this->get_parameter("~angular_x/p").as_double(), this->get_parameter("~angular_x/i").as_double(), this->get_parameter("~angular_x/d").as_double(), 1.0, -1.0, true);
        angular_y.setGains(this->get_parameter("~angular_y/p").as_double(), this->get_parameter("~angular_y/i").as_double(), this->get_parameter("~angular_y/d").as_double(), 1.0, -1.0, true);
        angular_z.setGains(this->get_parameter("~angular_z/p").as_double(), this->get_parameter("~angular_z/i").as_double(), this->get_parameter("~angular_z/d").as_double(), 1.0, -1.0, true);

        rclcpp::Time time = this->get_clock()->now(); //might have to change the now ????
        if(lastTime.seconds() != 0){
            double dt = (time-lastTime).nanoseconds();

            std_msgs::msg::Header header;
            header.frame_id = "/target_wrench";
            header.stamp = this->get_clock()->now();

            geometry_msgs::msg::Wrench controlEffort;
            // controlEffort.header = header;
            controlEffort.force.x = clamp(linear_x.computeCommand(targetTwist.linear.x-currentTwist.linear.x, dt), -1.0, 1.0);
            controlEffort.force.y = clamp(linear_y.computeCommand(targetTwist.linear.y-currentTwist.linear.y, dt), -1.0, 1.0);
            controlEffort.force.z = clamp(linear_z.computeCommand(targetTwist.linear.z-currentTwist.linear.z, dt), -1.0, 1.0);

            controlEffort.torque.x = clamp(angular_x.computeCommand(targetTwist.angular.x-currentTwist.angular.x, dt), -1.0, 1.0);
            controlEffort.torque.y = clamp(angular_y.computeCommand(targetTwist.angular.y-currentTwist.angular.y, dt), -1.0, 1.0);
            controlEffort.torque.z = clamp(angular_z.computeCommand(targetTwist.angular.z-currentTwist.angular.z, dt), -1.0, 1.0);

            pubControlEffort->publish(controlEffort);
        }
        lastTime = time;

    }
}

int main(int argc, char *argv[])
{
	rclcpp::init(argc, argv);


	rclcpp::spin(std::make_shared<controller::ControllerNode>());

	rclcpp::shutdown();
	return 0;
}
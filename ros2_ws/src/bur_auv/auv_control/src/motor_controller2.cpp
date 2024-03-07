#include <chrono>
#include <functional>
#include <algorithm>
#include <memory>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "utilities/common_functions.hpp"
#include "auv_msgs/msg/allocator_command.hpp"
#include "auv_msgs/msg/motor_command.hpp"
#include "auv_msgs/msg/motor_command_list.hpp"
#include "raspi_dma_pwm.h"

using namespace std;
/*
// Does thrust allocation and sends PWM
// Only for three thruster configuration
// Thrustrs in triangle formation
//             0
//            / \
//           2   1
*/
// Directional Vectors
// North(x)-East(y)-Down(z) Coordinate, x-axis pointing into the page
// Motor0 (CCW), Motor1(CCW), Motor2(CW)
// No y or z motion with 3-thruster config
// Assume value of 1 for triangle size, Center of gravity in middle of triangle
// Assume thruster values at full power forward
//
// Motor Wrenches {x, y, z, roll, pitch, yaw}
// motor0 = {1 0 0 0 -1 0}
// motor1 = {1 0 0 0 sin(30) -cos(30)}
// motor2 = {1 0 0 0 sin(30) cos(30)}

class MotorController : public rclcpp::Node
{
public:
    MotorController()
        : Node("motor_controller")
    {
        this->declare_parameter("sub_topic", "alloc_cmd");
        this->declare_parameter("pub_topic", "pwm_command_list");
        sub_ = this->create_subscription<auv_msgs::msg::AllocatorCommand>(this->get_parameter("sub_topic").as_string(),
                                                                           10, std::bind(&MotorController::topic_callback, this, std::placeholders::_1));
        pub_ = this->create_publisher<auv_msgs::msg::MotorCommandList>(
            this->get_parameter("pub_topic").as_string(), 1);

        this->declare_parameter("pi_address", "192.168.8.157");
        this->declare_parameter("pi_port", "8888");
        this->declare_parameter("motor_pins", vector<int64_t>{17, 22, 27});
        pi = pigpio_start((const char *)this->get_parameter("pi_address").as_string().c_str(), this->get_parameter("pi_port").as_string().c_str());
        cout << "pigpio_id " << pi << endl;
        vector<int64_t> motor_pins = this->get_parameter("motor_pins").as_integer_array();
        for (int i = 0; i < 3; i++)
        {
            unique_ptr<PWM_obj> temp(new PWM_obj(pi, motor_pins.at(i)));
            motor_[i] = move(temp);
        }
    }

private:
    void topic_callback(const auv_msgs::msg::AllocatorCommand::SharedPtr msg)
    {
        speed[2] = (msg->axes_command[5] / sqrt(3)) + ((msg->axes_command[0] + msg->axes_command[4]) / 3);
        speed[1] = (msg->axes_command[0] + msg->axes_command[4]) / 1.5 - speed[2];
        speed[0] = msg->axes_command[0] - speed[1] - speed[2];

        auto motor_command_msg = auv_msgs::msg::MotorCommandList();
        for (size_t i = 0; i < 3; ++i)
        {
            speed[i] = CommonFunctions::Clamp(speed[i], -1, 1);
            auto command = auv_msgs::msg::MotorCommand();
            command.name = string("motor" + to_string(i));
            command.position = speed[i];
            motor_command_msg.motor_commands.push_back(command);
            motor_[i]->run(speed[i]);
        }
        pub_->publish(motor_command_msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<auv_msgs::msg::AllocatorCommand>::SharedPtr sub_;
    rclcpp::Publisher<auv_msgs::msg::MotorCommandList>::SharedPtr pub_;
    unique_ptr<PWM_obj> motor_[3];
    float speed[3] = {0};
    int pi;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MotorController>());
    rclcpp::shutdown();
    return 0;
}
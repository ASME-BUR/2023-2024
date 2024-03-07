#include "thrusters.hpp"

using std::placeholders::_1;

Thrusters::Thrusters() : rclcpp::Node("thrusters")
{
    this->declare_parameter("pi_address", "192.168.8.157");
    this->declare_parameter("pi_port", "8888");
    this->declare_parameter("motor_pins", vector<int64_t>{17, 22, 27});
    pi = pigpio_start((const char *)this->get_parameter("pi_address").as_string().c_str(), this->get_parameter("pi_port").as_string().c_str());
    cout << "pigpio_id " << pi << endl;

    vector<int64_t> motor_pins = this->get_parameter("motor_pins").as_integer_array();
    for (int i = 0; i < NUMBER_OF_MOTORS; i++)
    {
        unique_ptr<PWM_obj> temp(new PWM_obj(pi, motor_pins.at(i)));
        motor_[i] = move(temp);
    }

    ctrl_sub = this->create_subscription<auv_msgs::msg::MotorCommandList>(
        "motor_command", 10, std::bind(&Thrusters::sub_Callback, this, _1));
}

void Thrusters::sub_Callback(const auv_msgs::msg::MotorCommandList::SharedPtr msg)
{
    for (size_t i = 0; i < NUMBER_OF_MOTORS; ++i)
    {
        motor_[i]->run(msg->motor_commands[i].position);
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Thrusters>());
    rclcpp::shutdown();
    return 0;
}
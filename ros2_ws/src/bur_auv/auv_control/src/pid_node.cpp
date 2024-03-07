#include "pid_node.hpp"
#include <cmath>
using namespace std;

Pid_node::Pid_node() : rclcpp::Node("pid_node")
{
    this->declare_parameter("P_gain", vector<double>{1, 1, 1, 1, 1, 1});
    this->declare_parameter("I_gain", vector<double>{1, 1, 1, 1, 1, 1});
    this->declare_parameter("D_gain", vector<double>{1, 1, 1, 1, 1, 1});
    this->declare_parameter("I_lim", vector<double>{5, 5, 5, 5, 5, 5});
    this->declare_parameter("Out_lim", vector<double>{10, 10, 10, 10, 10, 10});
    this->declare_parameter("antiwindup", vector<double>{100, 100, 100, 100, 100, 100});
    this->declare_parameter("pid_enable", vector<bool>{true, true, true, true, true, true});
    this->declare_parameter("angle_wrap_compensation", vector<bool>{false, false, false, true, true, true});
    this->declare_parameter("cutoff_frequency", 10.0);
    this->declare_parameter("state_topic", "imu_data");
    this->declare_parameter("setpoint_topic", "setpoint");
    this->declare_parameter("ctrl_effort_topic", "ctrl_effort");
    this->declare_parameter("rate", 20);

    state_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(this->get_parameter("state_topic").as_string(),
                                                                  1, bind(&Pid_node::state_callback, this, _1));
    setpoint_sub_ = this->create_subscription<geometry_msgs::msg::TransformStamped>(this->get_parameter("setpoint_topic").as_string(),
                                                                                    1, bind(&Pid_node::setpoint_callback, this, _1));

    ctrl_effort_pub_ = this->create_publisher<auv_msgs::msg::AllocatorCommand>(this->get_parameter("ctrl_effort_topic").as_string(), 1);
    dummy_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("dummy", 1);

    param_callback_ = this->add_on_set_parameters_callback(
        bind(&Pid_node::parametersCallback, this, placeholders::_1));

    timer_ = this->create_wall_timer(chrono::milliseconds(1000 / this->get_parameter("rate").as_int()),
                                     bind(&Pid_node::pid_callback, this));
    last_loop_time_ = this->now();
    setConstants();
}

rcl_interfaces::msg::SetParametersResult Pid_node::parametersCallback(
    const vector<rclcpp::Parameter> &parameters)
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

void Pid_node::setConstants()
{
    vector<bool> angle_wrap_compensation = this->get_parameter("angle_wrap_compensation").as_bool_array();
    vector<double> p = this->get_parameter("P_gain").as_double_array();
    vector<double> i = this->get_parameter("I_gain").as_double_array();
    vector<double> d = this->get_parameter("D_gain").as_double_array();
    vector<double> out_lim = this->get_parameter("Out_lim").as_double_array();
    vector<double> i_lim = this->get_parameter("I_lim").as_double_array();
    vector<bool> enable = this->get_parameter("pid_enable").as_bool_array();
    vector<double> antiwindup = this->get_parameter("antiwindup").as_double_array();
    for (size_t n = 0; n < 6; n++)
    {
        pid_enabled_[n] = enable.at(n);
        RCLCPP_INFO(this->get_logger(), "PID state: '%i'", pid_enabled_[n]);
        RCLCPP_INFO(this->get_logger(), "P: '%f' I: '%f' D: '%f' I_lim: '%f' Output_lim: '%f' Antiwindup: '%i'", p.at(n),
                    i.at(n), d.at(n), out_lim.at(n),
                    i_lim.at(n), angle_wrap_compensation.at(n), antiwindup.at(n));
        pid[n].setGains(p.at(n), i.at(n), d.at(n), out_lim.at(n),
                        i_lim.at(n), angle_wrap_compensation.at(n), antiwindup.at(n),
                        this->get_parameter("cutoff_frequency").as_double());
    }
    new_params = false;
}

void Pid_node::setpoint_callback(const geometry_msgs::msg::TransformStamped::SharedPtr msg)
{
    new_state_or_setpt_ = true;
    setpoint_[0] = msg->transform.translation.x;
    setpoint_[1] = msg->transform.translation.y;
    setpoint_[2] = msg->transform.translation.z;
    CommonFunctions::Quaternion q;
    q.w = msg->transform.rotation.w;
    q.x = msg->transform.rotation.x;
    q.y = msg->transform.rotation.y;
    q.z = msg->transform.rotation.z;
    CommonFunctions::EulerAngles e = CommonFunctions::ToEulerAngles(q);
    setpoint_[3] = e.roll;
    setpoint_[4] = e.pitch;
    setpoint_[5] = e.yaw;
    cout << "setpoint roll: " << e.roll * 180 / M_PI << " pitch: " << e.pitch * 180 / M_PI << " yaw: " << e.yaw * 180 / M_PI << endl;
}
void Pid_node::state_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    new_state_or_setpt_ = true;
    state_[0] = msg->linear_acceleration.x;
    state_[1] = msg->linear_acceleration.x;
    state_[2] = msg->linear_acceleration.x;
    CommonFunctions::Quaternion q;
    q.w = msg->orientation.w;
    q.x = msg->orientation.x;
    q.y = msg->orientation.y;
    q.z = msg->orientation.z;
    CommonFunctions::EulerAngles e = CommonFunctions::ToEulerAngles(q);
    state_[3] = e.roll;
    state_[4] = e.pitch;
    state_[5] = e.yaw;
    cout << "state roll: " << e.roll * 180 / M_PI << " pitch: " << e.pitch * 180 / M_PI << " yaw: " << e.yaw * 180 / M_PI << endl;
}

void Pid_node::pid_callback()
{
    if (new_params)
    {
        setConstants();
    }

    if (new_state_or_setpt_)
    {
        // calculate delta_t
        rclcpp::Time current_time = this->now();
        rclcpp::Duration diff = current_time - last_loop_time_;
        auto diff_ns = diff.to_chrono<chrono::nanoseconds>();
        double delta_time = diff_ns.count() / 1e9;
        // cout << "dt " << delta_time << endl;
        last_loop_time_ = current_time;
        if (delta_time < 0.0001)
        {
            RCLCPP_INFO(this->get_logger(), "delta_t is 0, skipping this loop. Possible overloaded cpu "
                                            "at time: %f",
                        this->now());
            return;
        }
        auto output = auv_msgs::msg::AllocatorCommand();
        auto dummy = geometry_msgs::msg::Twist();
        for (size_t i = 0; i < 6; i++)
        {
            if (pid_enabled_[i] == true)
            {
                // cout << "error " << setpoint_[i] - state_[i] << endl;
                output.axes_command[i] = pid[i].compute(setpoint_[i], state_[i], delta_time);
                last_output_[i] = output.axes_command[i];
                // cout << "ctrl " << output.axes_command[i] << endl;
            }
            else
            {
                output.axes_command[i] = last_output_[i];
            }
        }
        dummy.linear.x = output.axes_command[0];
        dummy.linear.y = output.axes_command[1];
        dummy.linear.z = output.axes_command[2];
        dummy.angular.x = output.axes_command[3];
        dummy.angular.y = output.axes_command[4];
        dummy.angular.z = output.axes_command[5];
        dummy_pub_->publish(dummy);
        output.header.stamp = this->now();
        ctrl_effort_pub_->publish(output);
        new_state_or_setpt_ = false;
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pid_node>());
    rclcpp::shutdown();
    return 0;
}

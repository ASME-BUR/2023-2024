#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "custom_msg_srv/msg/float64_stamped.hpp"

using namespace std;
using StampedFloatMsg = custom_msg_srv::msg::Float64Stamped;
using std::placeholders::_1;

class Pid_recombiner : public rclcpp::Node
{
public:
    Pid_recombiner()
        : Node("pid_recombiner")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("target", 10);
        int hz = 60;
        timer_ = this->create_wall_timer(chrono::milliseconds(1000 * (1 / hz)), bind(&Pid_recombiner::timer_Callback, this));
        RCLCPP_INFO(this->get_logger(), "Publishing to topic: imu_data at '%i' hz", hz);

        const std::map<std::string, std::string> &ctrl_effort = {
            {"x", "ctrl_effort_x"},
            {"y", "ctrl_effort_y"},
            {"z", "ctrl_effort_z"},
            {"rx", "ctrl_effort_rx"},
            {"ry", "ctrl_effort_ry"},
            {"rz", "ctrl_effort_rz"}};
        this->declare_parameters("ctrl_effort", ctrl_effort);

        // 6 pid controller outputs
        sub_x = this->create_subscription<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("ctrl_effort.x").as_string(), 10, std::bind(&Pid_recombiner::ctrl_effort_x_callback, this, _1));
        sub_y = this->create_subscription<StampedFloatMsg>(this->get_parameter("ctrl_effort.y").as_string(), 10, std::bind(&Pid_recombiner::ctrl_effort_y_callback, this, _1));
        sub_z = this->create_subscription<StampedFloatMsg>(this->get_parameter("ctrl_effort.z").as_string(), 10, std::bind(&Pid_recombiner::ctrl_effort_z_callback, this, _1));
        sub_rx = this->create_subscription<StampedFloatMsg>(this->get_parameter("ctrl_effort.rx").as_string(), 10, std::bind(&Pid_recombiner::ctrl_effort_rx_callback, this, _1));
        sub_ry = this->create_subscription<StampedFloatMsg>(this->get_parameter("ctrl_effort.ry").as_string(), 10, std::bind(&Pid_recombiner::ctrl_effort_ry_callback, this, _1));
        sub_rz = this->create_subscription<StampedFloatMsg>(this->get_parameter("ctrl_effort.rz").as_string(), 10, std::bind(&Pid_recombiner::ctrl_effort_rz_callback, this, _1));
    }

private:
    void ctrl_effort_x_callback(const StampedFloatMsg::SharedPtr msg_x)
    {
        output[0] = msg_x->data;
    }
    void ctrl_effort_y_callback(const StampedFloatMsg::SharedPtr msg_y)
    {
        output[1] = msg_y->data;
    }
    void ctrl_effort_z_callback(const StampedFloatMsg::SharedPtr msg_z)
    {
        output[2] = msg_z->data;
    }
    void ctrl_effort_rx_callback(const StampedFloatMsg::SharedPtr msg_rx)
    {
        output[3] = msg_rx->data;
    }
    void ctrl_effort_ry_callback(const StampedFloatMsg::SharedPtr msg_ry)
    {
        output[4] = msg_ry->data;
    }
    void ctrl_effort_rz_callback(const StampedFloatMsg::SharedPtr msg_rz)
    {
        output[5] = msg_rz->data;
    }

    void timer_Callback()
    {
        // RCLCPP_INFO(this->get_logger(), "received");
        int n = sizeof(output) / sizeof(output[0]);
        double min = *min_element(output, output + n);
        double max = *max_element(output, output + n);
        if (max != min)
        {
            for (int i = 0; i < n; i++)
            {
                output[i] = (output[i] - min) / (max - min);
            }
        }
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = output[0];
        msg.linear.y = output[1];
        msg.linear.z = output[2];
        msg.angular.x = output[3];
        msg.angular.y = output[4];
        msg.angular.z = output[5];
        publisher_->publish(msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<StampedFloatMsg>::SharedPtr sub_x;
    rclcpp::Subscription<StampedFloatMsg>::SharedPtr sub_y;
    rclcpp::Subscription<StampedFloatMsg>::SharedPtr sub_z;
    rclcpp::Subscription<StampedFloatMsg>::SharedPtr sub_rx;
    rclcpp::Subscription<StampedFloatMsg>::SharedPtr sub_ry;
    rclcpp::Subscription<StampedFloatMsg>::SharedPtr sub_rz;
    rclcpp::TimerBase::SharedPtr timer_;
    double output[6] = {0};
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pid_recombiner>());
    rclcpp::shutdown();
    return 0;
}
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher()
        : Node("minimal_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::Joy>("joy", 1);
        timer_ = this->create_wall_timer(
            100ms, std::bind(&MinimalPublisher::timer_callback, this));
        init = this->now();
    }

private:
    void timer_callback()
    {
        auto message = sensor_msgs::msg::Joy();
        std::vector<double> values(9, 0);
        message.axes.clear();
        rclcpp::Duration diff = this->now() - init;
        auto num_of_s = diff.to_chrono<std::chrono::seconds>();
        double delta_t = num_of_s.count();
        message.header.stamp.sec = delta_t;
        message.buttons.clear();
        std::vector<int> buttons(10, 0);
        for (size_t i = 0; i < buttons.size(); i++)
        {
            message.buttons.push_back(buttons[i]);
        }
        if (delta_t < 10.0 && delta_t >= 5.0)
        {
            values[1] = -0.7;
            message.buttons.clear();
            buttons[9] = 1;
            for (size_t i = 0; i < buttons.size(); i++)
            {
                message.buttons.push_back(buttons[i]);
            }
        }
        else if (delta_t < 45.0 && delta_t >= 10.0)
        {
            values[1] = -0.7;
            // values[4] = 1.0;
            buttons[9] = 1;
            message.buttons.clear();
            for (size_t i = 0; i < buttons.size(); i++)
            {
                message.buttons.push_back(buttons[i]);
            }
        }

        for (size_t i = 0; i < values.size(); i++)
        {
            message.axes.push_back(values[i]);
        }
        publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::Joy>::SharedPtr publisher_;
    size_t count_;
    rclcpp::Time init;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}
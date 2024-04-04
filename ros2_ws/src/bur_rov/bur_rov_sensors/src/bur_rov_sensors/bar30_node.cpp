#include "bar30_node.hpp"

using std::placeholders::_1;

Bar30_node::Bar30_node() : rclcpp::Node("bar30"), count(0)
{
    this->declare_parameter("pi_address", "192.168.8.157");
    this->declare_parameter("pi_port", "8888");
    this->declare_parameter("rate", 30);
    this->declare_parameter("fluid_density", 1029.0);
    pi = pigpio_start(this->get_parameter("pi_address").as_string().c_str(),
                      this->get_parameter("pi_port").as_string().c_str());
    if (pi < 0)
    {
        RCLCPP_INFO(this->get_logger(), "PI not detected!");
    }
    cout << "pigpio_id " << pi << endl;
    // create a dummy pointer for the class obj Bar30
    unique_ptr<MS5837> dummy(new MS5837(pi));
    sensor = move(dummy);
    if (sensor->init())
    {
        sensor->setFluidDensity(this->get_parameter("fluid_density").as_double());
        sensor->setOSR(5);
        pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("depth_sensor", 10);
        // pub_ = this->create_publisher<geometry_msgs::msg::Pose>("depth_sensor", 10);
        int period = 1000/this->get_parameter("rate").as_int();
        timer_ = this->create_wall_timer(chrono::milliseconds(period), bind(&Bar30_node::timer_Callback, this));
        RCLCPP_INFO(this->get_logger(), "Publishing to topic: Bar30_data at '%i' hz", 1000 / period);
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Bar30 not detected!");
    }
}

Bar30_node::~Bar30_node()
{
    RCLCPP_INFO(this->get_logger(), "Destructing");
}

void Bar30_node::timer_Callback()
{
    auto msg = geometry_msgs::msg::PoseWithCovarianceStamped();
    // auto msg = geometry_msgs::msg::Pose();
    // Bar30->printData();
    sensor->read();
    msg.header.stamp = this->now();
    msg.header.frame_id = "depth_sensor";
    msg.pose.pose.position.z = sensor->depth();
    msg.pose.covariance = {0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0,
                           0, 0, 0.002, 0, 0, 0,
                           0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0};
    pub_->publish(msg);
    count++;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Bar30_node>());
    rclcpp::shutdown();
    return 0;
}
#include "bar30_node.hpp"

using std::placeholders::_1;

Bar30_node::Bar30_node() : rclcpp::Node("bar30"), count(0)
{
    this->declare_parameter("pi_address", "NULL");
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
        sensor->setModel(1);
        depth_pub = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("depth_sensor", 10);
        depth_pub2 = this->create_publisher<nav_msgs::msg::Odometry>("depth_sensor2", 10);
        pressure_pub = this->create_publisher<std_msgs::msg::Float32>("pressure", 10);
        temp_pub = this->create_publisher<std_msgs::msg::Float32>("temp", 10);
        int period = 1000/this->get_parameter("rate").as_int();
        timer = this->create_wall_timer(chrono::milliseconds(period), bind(&Bar30_node::timer_Callback, this));
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
    auto depth_msg = geometry_msgs::msg::PoseWithCovarianceStamped();
    auto depth_msg2 = nav_msgs::msg::Odometry();
    auto pressure_msg = std_msgs::msg::Float32();
    auto temp_msg = std_msgs::msg::Float32();
    sensor->read();
    depth_msg.header.stamp = this->now();
    depth_msg.header.frame_id = "depth_sensor";
    depth_msg.pose.pose.position.z = -sensor->depth();
    depth_msg.pose.covariance = {0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,};

    depth_msg2.header.stamp = this->now();
    depth_msg2.header.frame_id = "odom";
    depth_msg2.child_frame_id = "base_link";
    depth_msg2.pose.pose.position.z = -sensor->depth();
    depth_msg2.pose.covariance = {0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,
                                0.005, 0.005, 0.005, 0.005, 0.005, 0.005,};
    pressure_msg.data = sensor->pressure();
    temp_msg.data = sensor->temperature();
    depth_pub2->publish(depth_msg2);
    pressure_pub->publish(pressure_msg);
    temp_pub->publish(temp_msg);
    depth_pub->publish(depth_msg);
    count++;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    // while(rclcpp::ok()){
        // rclcpp::spin_some(std::make_shared<Bar30_node>());
    // }
    rclcpp::spin(std::make_shared<Bar30_node>());
    rclcpp::shutdown();
    return 0;
}
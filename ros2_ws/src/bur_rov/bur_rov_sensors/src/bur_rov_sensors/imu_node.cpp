#include "imu_node.hpp"

using std::placeholders::_1;

Imu_node::Imu_node() : rclcpp::Node("imu"), count(0)
{
    this->declare_parameter("pi_address", "192.168.8.157");
    this->declare_parameter("pi_port", "8888");
    pi = pigpio_start(this->get_parameter("pi_address").as_string().c_str(),
                      this->get_parameter("pi_port").as_string().c_str());
    if (pi < 0)
    {
        RCLCPP_INFO(this->get_logger(), "PI not detected!");
    }
    cout << "pigpio_id " << pi << endl;
    // create a dummy pointer for the class obj imu
    unique_ptr<MTi> dummy(new MTi(pi));
    imu = move(dummy);
    if (imu->detect(1000))
    {
        const string modes[] = {"QUATERNION", "RATEOFTURNHR", "ACCELERATION", "EULER"};
        const uint16_t hz[] = {30, 30, 30, 30};
        imu->configureOutputs(modes, hz, 4);
        imu_pub = this->create_publisher<sensor_msgs::msg::Imu>("imu_data", 10);
        imu_eul_pub = this->create_publisher<geometry_msgs::msg::Vector3>("imu_euler", 10);
        
        int n = sizeof(hz) / sizeof(hz[0]);
        int period = 0.5 * (1000 / (*max_element(hz, hz + n)));
        timer_ = this->create_wall_timer(chrono::milliseconds(period), bind(&Imu_node::timer_Callback, this));
        RCLCPP_INFO(this->get_logger(), "Publishing to topic: imu_data at '%i' hz", 1000 / period);
        imu->goToMeasurement();
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "IMU not detected!");
    }
}

Imu_node::~Imu_node()
{
    RCLCPP_INFO(this->get_logger(), "Destructing");
}

void Imu_node::timer_Callback()
{
    auto msg = sensor_msgs::msg::Imu();
    // imu->printData();
    imu->readData();
    msg.header.stamp = now();
    msg.header.frame_id = "imu_data";
    // Covariance values from here https://mtidocs.movella.com/sensor-specifications$sensor-specifications
    msg.orientation.w = imu->getQuat()[0];
    msg.orientation.x = imu->getQuat()[1];
    msg.orientation.y = imu->getQuat()[2];
    msg.orientation.z = imu->getQuat()[3];
    msg.orientation_covariance = {0.0139626, 0, 0, 
                                  0, 0.0139626, 0,
                                  0, 0, 0.0349066};

    msg.angular_velocity.x = imu->getRateOfTurn()[0];
    msg.angular_velocity.y = imu->getRateOfTurn()[1];
    msg.angular_velocity.z = imu->getRateOfTurn()[2];
    msg.angular_velocity_covariance = {0.007330383, 0, 0,
                                       0, 0.007330383, 0,
                                       0, 0, 0.007330383};

    msg.linear_acceleration.x = imu->getAcceleration()[0];
    msg.linear_acceleration.y = imu->getAcceleration()[1];
    msg.linear_acceleration.z = imu->getAcceleration()[2];
    msg.linear_acceleration_covariance = {0.07056, 0, 0,
                                          0, 0.07056, 0,
                                          0, 0, 0.07056};

    imu_pub->publish(msg);
    count++;

    auto msg_euler = geometry_msgs::msg::Vector3();
    msg_euler.x = imu->getEulerAngles()[0];
    msg_euler.y = imu->getEulerAngles()[1];
    msg_euler.z = imu->getEulerAngles()[2];

    imu_eul_pub->publish(msg_euler);


}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Imu_node>());
    rclcpp::shutdown();
    return 0;
}
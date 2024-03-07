#include <memory>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include <vector>
#include "sensor_msgs/msg/imu.hpp"
#include "custom_msg_srv/msg/float64_stamped.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "qos_profile.hpp"
using std::placeholders::_1;
using namespace std;

struct Quaternion
{
    double w, x, y, z;
};

struct EulerAngles
{
    double roll, pitch, yaw;
};

// this implementation assumes normalized quaternion
// converts to Euler angles in 3-2-1 sequence
EulerAngles ToEulerAngles(Quaternion q)
{
    EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = std::sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
    double cosp = std::sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
    angles.pitch = 2 * std::atan2(sinp, cosp) - M_PI / 2;

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.yaw = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}

class Imu_repub : public rclcpp::Node
{
public:
    Imu_repub()
        : Node("imu_repub")
    {
        imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(
            "imu_data", 10, std::bind(&Imu_repub::state_callback, this, _1));
        setpoint_sub = this->create_subscription<geometry_msgs::msg::TransformStamped>(
            "setpoint", 10, std::bind(&Imu_repub::setpoint_callback, this, _1));

        const std::map<std::string, std::string> &imu = {
            {"x", "imu_x"},
            {"y", "imu_y"},
            {"z", "imu_z"},
            {"rx", "imu_rx"},
            {"ry", "imu_ry"},
            {"rz", "imu_rz"}};
        this->declare_parameters("imu", imu);

        const std::map<std::string, std::string> &setpoint = {
            {"x", "setpoint_x"},
            {"y", "setpoint_y"},
            {"z", "setpoint_z"},
            {"rx", "setpoint_rx"},
            {"ry", "setpoint_ry"},
            {"rz", "setpoint_rz"}};
        this->declare_parameters("setpoint", setpoint);

        state_x = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.x").as_string(), 10);
        state_y = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.y").as_string(), 10);
        state_z = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.z").as_string(), 10);
        state_rx = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.rx").as_string(), 10);
        state_ry = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.ry").as_string(), 10);
        state_rz = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.rz").as_string(), 10);
        setpoint_x = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.x").as_string(), 10);
        setpoint_y = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.y").as_string(), 10);
        setpoint_z = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.z").as_string(), 10);
        setpoint_rx = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.rx").as_string(), 10);
        setpoint_ry = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.ry").as_string(), 10);
        setpoint_rz = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.rz").as_string(), 10);

        // state_x = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.x").as_string(), custom_qos_profile);
        // state_y = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.y").as_string(), custom_qos_profile);
        // state_z = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.z").as_string(), custom_qos_profile);
        // state_rx = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.rx").as_string(), custom_qos_profile);
        // state_ry = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.ry").as_string(), custom_qos_profile);
        // state_rz = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("imu.rz").as_string(), custom_qos_profile);
        // setpoint_x = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.x").as_string(), custom_qos_profile);
        // setpoint_y = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.y").as_string(), custom_qos_profile);
        // setpoint_z = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.z").as_string(), custom_qos_profile);
        // setpoint_rx = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.rx").as_string(), custom_qos_profile);
        // setpoint_ry = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.ry").as_string(), custom_qos_profile);
        // setpoint_rz = this->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->get_parameter("setpoint.rz").as_string(), custom_qos_profile);
    }

private:
    void state_callback(const sensor_msgs::msg::Imu::SharedPtr msg) const
    {
        auto msg_x = custom_msg_srv::msg::Float64Stamped();
        auto msg_y = custom_msg_srv::msg::Float64Stamped();
        auto msg_z = custom_msg_srv::msg::Float64Stamped();
        auto msg_rx = custom_msg_srv::msg::Float64Stamped();
        auto msg_ry = custom_msg_srv::msg::Float64Stamped();
        auto msg_rz = custom_msg_srv::msg::Float64Stamped();

        msg_x.data = msg->linear_acceleration.x;
        msg_y.data = msg->linear_acceleration.y;
        msg_z.data = msg->linear_acceleration.z;

        Quaternion q = {msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z};
        EulerAngles e = ToEulerAngles(q);
        msg_rx.data = e.pitch;
        msg_ry.data = e.roll;
        msg_rz.data = e.yaw;

        msg_x.header.stamp = msg->header.stamp;
        msg_y.header.stamp = msg->header.stamp;
        msg_z.header.stamp = msg->header.stamp;
        msg_rx.header.stamp = msg->header.stamp;
        msg_ry.header.stamp = msg->header.stamp;
        msg_rz.header.stamp = msg->header.stamp;

        state_x->publish(msg_x);
        state_y->publish(msg_y);
        state_z->publish(msg_z);
        state_rx->publish(msg_rx);
        state_ry->publish(msg_ry);
        state_rz->publish(msg_rz);
    }

    void setpoint_callback(const geometry_msgs::msg::TransformStamped::SharedPtr msg) const
    {
        auto msg_x = custom_msg_srv::msg::Float64Stamped();
        auto msg_y = custom_msg_srv::msg::Float64Stamped();
        auto msg_z = custom_msg_srv::msg::Float64Stamped();
        auto msg_rx = custom_msg_srv::msg::Float64Stamped();
        auto msg_ry = custom_msg_srv::msg::Float64Stamped();
        auto msg_rz = custom_msg_srv::msg::Float64Stamped();

        msg_x.data = msg->transform.translation.x;
        msg_y.data = msg->transform.translation.y;
        msg_z.data = msg->transform.translation.z;

        Quaternion q = {msg->transform.rotation.w, msg->transform.rotation.x, msg->transform.rotation.y, msg->transform.rotation.z};
        EulerAngles e = ToEulerAngles(q);
        msg_rx.data = e.pitch;
        msg_ry.data = e.roll;
        msg_rz.data = e.yaw;

        msg_x.header.stamp = msg->header.stamp;
        msg_y.header.stamp = msg->header.stamp;
        msg_z.header.stamp = msg->header.stamp;
        msg_rx.header.stamp = msg->header.stamp;
        msg_ry.header.stamp = msg->header.stamp;
        msg_rz.header.stamp = msg->header.stamp;

        setpoint_x->publish(msg_x);
        setpoint_y->publish(msg_y);
        setpoint_z->publish(msg_z);
        setpoint_rx->publish(msg_rx);
        setpoint_ry->publish(msg_ry);
        setpoint_rz->publish(msg_rz);
    }
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;
    rclcpp::Subscription<geometry_msgs::msg::TransformStamped>::SharedPtr setpoint_sub;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr state_x;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr state_y;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr state_z;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr state_rx;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr state_ry;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr state_rz;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint_x;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint_y;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint_z;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint_rx;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint_ry;
    rclcpp::Publisher<custom_msg_srv::msg::Float64Stamped>::SharedPtr setpoint_rz;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Imu_repub>());
    rclcpp::shutdown();
    return 0;
}
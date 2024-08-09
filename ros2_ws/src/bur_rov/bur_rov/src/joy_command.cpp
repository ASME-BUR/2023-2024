#include "joy_command.hpp"
#include <iostream>
#include <cmath>

JoyCommand::JoyCommand() : rclcpp::Node("joy_command")
{
    this->declare_parameter("cmd_pub_topic", "command");
    this->declare_parameter("twist_topic", "set_twist");
    this->declare_parameter("joy_topic", "joy");
    this->declare_parameter("depth_topic", "depth_sensor");
    this->declare_parameter("pose_topic", "set_pose");
    this->declare_parameter("imu_topic", "imu");
    this->declare_parameter("multiplier", 0.5);
    const std::map<std::string, int> &axis_mapping = {{"linear_x", 1}, {"linear_y", 0}, {"linear_z", 2}, {"angular_x", 3}, {"angular_y", 4}, {"angular_z", 5}};
    this->declare_parameters("axis_mapping", axis_mapping);
    this->declare_parameter("using_ekf", false);
    this->declare_parameter("using_joy", true);
    this->declare_parameter("publish_rate", 100);
    cmd_pub = this->create_publisher<bur_rov_msgs::msg::Command>(this->get_parameter("cmd_pub_topic").as_string(), 10);

    int publish_rate = this->get_parameter("publish_rate").as_int();
    timer = this->create_wall_timer(std::chrono::milliseconds(1000 / publish_rate), std::bind(&JoyCommand::timer_callback, this));
    create_subscribers();
    set_constants();
    prev_time = this->now();
    debug_imu_pub = this->create_publisher<geometry_msgs::msg::PoseStamped>("imu_debug", 10);
    debug_joy_pub = this->create_publisher<geometry_msgs::msg::PoseStamped>("joy_debug", 10);
    imu_euler = this->create_publisher<geometry_msgs::msg::Vector3Stamped>("imu_euler", 10);
    joy_euler = this->create_publisher<geometry_msgs::msg::Vector3Stamped>("joy_euler", 10);
}

void JoyCommand::create_subscribers()
{
    param_callback = this->add_on_set_parameters_callback(bind(&JoyCommand::parametersCallback, this, placeholders::_1));
    joy_sub = this->create_subscription<sensor_msgs::msg::Joy>(this->get_parameter("joy_topic").as_string(), 10, bind(&JoyCommand::joy_callback, this, placeholders::_1));
    twist_sub = this->create_subscription<geometry_msgs::msg::TwistStamped>(this->get_parameter("twist_topic").as_string(), 10, bind(&JoyCommand::twist_callback, this, placeholders::_1));
    odom_sub = this->create_subscription<nav_msgs::msg::Odometry>("/odometry/filtered", 10, bind(&JoyCommand::odom_callback, this, placeholders::_1));
    pose_sub = this->create_subscription<nav_msgs::msg::Odometry>("next_waypoint", 10, bind(&JoyCommand::des_pose_callback, this, placeholders::_1));
    depth_sub = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(this->get_parameter("depth_topic").as_string(), 10, bind(&JoyCommand::depth_callback, this, placeholders::_1));
    const rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort().durability_volatile();
    imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(this->get_parameter("imu_topic").as_string(), qos_profile, bind(&JoyCommand::imu_callback, this, placeholders::_1));
}
void JoyCommand::set_constants()
{
    using_joy = this->get_parameter("using_joy").as_bool();
    using_ekf = this->get_parameter("using_ekf").as_bool();
    multiplier = this->get_parameter("multiplier").as_double();
    this->get_parameters("axis_mapping", axis_mapping_);
    new_params = false;
}
rcl_interfaces::msg::SetParametersResult JoyCommand::parametersCallback(
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

void JoyCommand::joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
    if (using_joy)
    {
        if (!msg->axes.empty())
        {
            output.header.stamp = this->now();
            output.header.frame_id = "odom";
            output.target_vel.header.stamp = this->now();
            output.target_vel.header.frame_id = "odom";
            output.target_vel.twist.linear.x = multiplier * msg->axes[abs(axis_mapping_.at("linear_x"))];
            output.target_vel.twist.linear.y = multiplier * msg->axes[abs(axis_mapping_.at("linear_y"))];
            output.target_vel.twist.linear.z = multiplier * msg->axes[abs(axis_mapping_.at("linear_z"))];
            output.target_vel.twist.angular.x = multiplier * msg->axes[abs(axis_mapping_.at("angular_x"))];
            output.target_vel.twist.angular.y = multiplier * -msg->axes[abs(axis_mapping_.at("angular_y"))];
            output.target_vel.twist.angular.z = multiplier * msg->axes[abs(axis_mapping_.at("angular_z"))];

            // Debug
            joy_euler_msg.header.stamp = this->now();
            joy_euler_msg.header.frame_id = "odom";
            if (msg->buttons[8])
            {
                joy_euler_msg.vector.x = 0;
                joy_euler_msg.vector.y = 0;
            }
            else
            {
                joy_euler_msg.vector.x += msg->axes[axis_mapping_.at("angular_x")];
                joy_euler_msg.vector.y += msg->axes[axis_mapping_.at("angular_y")];
            }
            joy_euler->publish(joy_euler_msg);

            tf2::Quaternion q;
            q.setRPY(joy_euler_msg.vector.x * M_PI_2 / 180, joy_euler_msg.vector.y * M_PI_2 / 180, 0);
            q.normalize();
            output.target_pos.pose.orientation = tf2::toMsg(q);

            output.buttons.clear();
            for (uint8_t i = 0; i < msg->buttons.size(); i++)
            {
                output.buttons.push_back(msg->buttons[i]);
            }

            auto debug_msg = geometry_msgs::msg::PoseStamped();
            debug_msg.header.stamp = this->now();
            debug_msg.header.frame_id = "odom";
            debug_msg.pose.orientation.w = q.getW();
            debug_msg.pose.orientation.x = q.getX();
            debug_msg.pose.orientation.y = q.getY();
            debug_msg.pose.orientation.z = q.getZ();

            debug_msg.pose.position.x = 0;
            debug_msg.pose.position.y = 0;
            debug_msg.pose.position.z = 0;
            debug_joy_pub->publish(debug_msg);
        }
    }
}

void JoyCommand::depth_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
{
    output.current_pos.header.stamp = this->now();
    output.current_pos.pose.position.z = msg->pose.pose.position.z;
}

void JoyCommand::twist_callback(const geometry_msgs::msg::TwistStamped::SharedPtr msg)
{
    if (!using_joy)
    {
        output.target_vel = *msg;
    }
}

void JoyCommand::des_pose_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    // if (using_ekf)
    // {
    // output.target_pos.pose.position.x = msg->pose.pose.position.x;
    // output.target_pos.pose.position.y = msg->pose.pose.position.y;
    output.target_pos.pose.position.z = msg->pose.pose.position.z;
    // output.target_pos.pose.orientation.x = msg->pose.pose.orientation.x;
    // output.target_pos.pose.orientation.y = msg->pose.pose.orientation.y;
    // output.target_pos.pose.orientation.z = msg->pose.pose.orientation.z;
    // output.target_pos.pose.orientation.w = msg->pose.pose.orientation.w;
    // }
}

void JoyCommand::imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    if (!using_ekf)
    {
        output.current_pos.header.stamp = this->now();
        output.current_pos.header.frame_id = "imu";
        output.current_pos.header = msg->header;
        output.current_pos.pose.orientation = msg->orientation;

        output.current_vel.header.frame_id = "imu";
        output.current_vel.twist.angular.x = msg->angular_velocity.x;
        output.current_vel.twist.angular.y = msg->angular_velocity.y;
        output.current_vel.twist.angular.z = msg->angular_velocity.z;
    }

    tf2::Quaternion q = tf2::Quaternion(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);
    tf2::Matrix3x3 rot_matrix = tf2::Matrix3x3(q);

    auto debug_msg = geometry_msgs::msg::PoseStamped();
    debug_msg.header.stamp = this->now();
    debug_msg.header.frame_id = "base_link";
    debug_msg.pose.orientation.w = output.current_pos.pose.orientation.w;
    debug_msg.pose.orientation.x = output.current_pos.pose.orientation.x;
    debug_msg.pose.orientation.y = output.current_pos.pose.orientation.y;
    debug_msg.pose.orientation.z = output.current_pos.pose.orientation.z;
    debug_msg.pose.position.x = 0;
    debug_msg.pose.position.y = 0;
    debug_msg.pose.position.z = 0;
    debug_imu_pub->publish(debug_msg);

    auto imu_euler_msg = geometry_msgs::msg::Vector3Stamped();
    imu_euler_msg.header.stamp = this->now();
    imu_euler_msg.header.frame_id = "base_link";
    double roll, pitch, yaw;
    rot_matrix.getRPY(roll, pitch, yaw);
    imu_euler_msg.vector.x = roll;
    imu_euler_msg.vector.y = pitch;
    imu_euler_msg.vector.z = yaw;
    imu_euler->publish(imu_euler_msg);
}

void JoyCommand::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    if (using_ekf)
    {
        output.header.stamp = this->now();
        output.header.frame_id = "base_link";
        output.current_pos.header = msg->header;
        output.current_pos.pose.position.x = msg->pose.pose.position.x;
        output.current_pos.pose.position.y = msg->pose.pose.position.y;
        // use the depth sensor z position bc it updates more frequently
        output.current_pos.pose.orientation.x = msg->pose.pose.orientation.x;
        output.current_pos.pose.orientation.y = msg->pose.pose.orientation.y;
        output.current_pos.pose.orientation.z = msg->pose.pose.orientation.z;
        output.current_pos.pose.orientation.w = msg->pose.pose.orientation.w;
        // output.current_vel.header = msg->header;
        // output.current_vel.twist = msg->twist.twist;
    }
}

void JoyCommand::timer_callback()
{
    if (new_params)
    {
        set_constants();
    }
    cmd_pub->publish(output);
}

double *JoyCommand::vel_calc(double acceleration[3], rclcpp::Time current_time, rclcpp::Time previous_time)
{
    rclcpp::Duration diff = current_time - previous_time;
    auto num_of_ns = diff.to_chrono<std::chrono::nanoseconds>();
    double delta_t = num_of_ns.count();
    delta_t = delta_t / pow(10, 9);
    // std::cout << "delta_t: " << delta_t << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        velocity[i] = acceleration[i] * delta_t + v_0[i];
        if (abs(velocity[i]) > 5.0)
        {
            velocity[i] = 0;
        }
        v_0[i] = velocity[i];
    }
    return velocity;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JoyCommand>());
    rclcpp::shutdown();
    return 0;
}
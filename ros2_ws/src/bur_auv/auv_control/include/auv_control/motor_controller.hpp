/*
 C++ Motor Controller
 6-DOF motor mixer and controller node, takes in 6-DOF desired thrust commands (roll, pitch, yaw, heave, surge, sway) and transforms them to lower-level motor commands

 Note: this node was originally in NED coordinates, and now does the transform in the subscriber callbacks

 DOFs used in code:
    0: Surge (x)
    1: Sway (y)
    2: Heave (z)
    3: Roll (x rotation)
    4: Pitch (y rotation)
    5: Yaw (z rotation)
 */

#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_listener.h"
#include "std_msgs/msg/float64.hpp"

#include "raspi_dma_pwm.h"
#include "auv_msgs/msg/motor_command.hpp"
#include "auv_msgs/msg/motor_command_list.hpp"
#include "auv_msgs/msg/allocator_command.hpp"
#include "utilities/common_functions.hpp"

using namespace std;

#define NUMBER_OF_MOTORS 3

#define SURGE 0
#define SWAY 1
#define HEAVE 2
#define ROLL 3
#define PITCH 4
#define YAW 5

// 

namespace constants
{
    // Global constants (should these instead be member constants?)
    const double MOTOR_FORWARD_BACKWARD_RATIO = 0.78; // BlueROV T200 produce 5.25kgf forward, 4.1 kgf backwards, at 16V
    const double THRUST_MAX_FWD = 5.25;               // kg-f @ 16V
    const double THRUST_MAX_BWD = 4.1;                // kg-f @ 16V
    const double KGF2N = 9.80665;                     // kg-f to Newton constant
    const double THRUST_MAX_FWD_N = THRUST_MAX_FWD * KGF2N;
    const double THRUST_MAX_BWD_N = THRUST_MAX_BWD * KGF2N;
    const double THRUST_DEADBAND_EPS = 0.000001;
    const double MOTOR_DRIVER_DEADBAND = 0.0625; // Scale from 0 to 1

    const double FORCE_MAX = 60.0; // N
    const double TORQUE_MAX = 8.0; // N-m

    const std::array<std::string, 6> DOFs = {"surge", "sway", "heave", "roll", "pitch", "yaw"};
}

class Motor_controller : public rclcpp::Node
{
public:
    Motor_controller();
    void runNode();

private:
    // Functions
    static double thrust_to_motor_comm(const double thrust_n);
    void setVariables();
    void allocate_generic_motors(std::map<std::string, double> &des_forces, std::vector<double> &des_motor_thrusts);
    void allocate_prioritized_motors(std::map<std::string, double> &des_forces, std::vector<double> &des_motor_thrusts);
    double rateLimitMotorCommand(double new_command, double last_command) const;
    void alloc_Callback(const auv_msgs::msg::AllocatorCommand::SharedPtr msg);

    // Ros stuff
    rclcpp::Subscription<auv_msgs::msg::AllocatorCommand>::SharedPtr alloc_sub_;
    rclcpp::Publisher<auv_msgs::msg::MotorCommandList>::SharedPtr cmd_pub_;

    // Variables
    double rate_hz = 50;
    unique_ptr<rclcpp::Rate> loop_rate;
    map<int, std::map<std::string, double>> motors;
    vector<std::string> allocation_priorities;
    vector<std::string> motor_names;
    array<double, 6> last_motor_command = {0};
    array<double, 6> pwr = {0};
    array<double, 6> pwr_limit = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    double max_step_per_loop = 1;
    bool enable_priorities = true;
};

#endif
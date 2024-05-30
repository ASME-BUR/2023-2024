#include "thruster_manager.hpp"

#include <iostream>

using std::placeholders::_1;

Thruster_manager::Thruster_manager() : rclcpp::Node("thruster_manager")
{
    // Parameters
    this->declare_parameter("wrench_sub_topic", "wrench_cmd");
    this->declare_parameter("cmd_sub_topic", "cmd");
    this->declare_parameter("thrust_cmd_pub_topic", "thrust_cmd");
    this->declare_parameter("thrust_max_fwd", 5.25);
    this->declare_parameter("thrust_max_bwd", 4.1);
    this->declare_parameter("thrust_deadband", 0.000001);
    this->declare_parameter("motor_driver_deadband", 0.0625);
    this->declare_parameter("max_force", 60.0);
    this->declare_parameter("max_torque", 8.0);
    this->declare_parameter("num_motors", 8);
    this->declare_parameter("test_mode", false);
    // Parameter Lists
    const std::map<std::string, double> &motor = {{"surge", 0.0}, {"sway", 0.0}, {"heave", 0.0}, {"roll", 0.0}, {"pitch", 0.0}, {"yaw", 0.0}};

    for (size_t i = 0; i < this->get_parameter("num_motors").as_int(); i++)
    {
        this->declare_parameters(string("motor" + to_string(i)), motor);
        motor_names.push_back(string("motor" + to_string(i)));
    }

    wrench_sub = this->create_subscription<geometry_msgs::msg::WrenchStamped>(
        this->get_parameter("wrench_sub_topic").as_string(), 1, std::bind(&Thruster_manager::wrench_Callback, this, _1));
    cmd_sub = this->create_subscription<bur_rov_msgs::msg::Command>(
        this->get_parameter("cmd_sub_topic").as_string(), 1, std::bind(&Thruster_manager::cmd_Callback, this, _1));
    cmd_pub = this->create_publisher<bur_rov_msgs::msg::ThrusterCommand>(
        this->get_parameter("thrust_cmd_pub_topic").as_string(), 1);
    test_mode = this->get_parameter("test_mode").as_bool();

    setVariables();
}

void Thruster_manager::setVariables()
{
    THRUST_MAX_FWD = this->get_parameter("thrust_max_fwd").as_double();
    THRUST_MAX_BWD = this->get_parameter("thrust_max_bwd").as_double();
    MOTOR_FORWARD_BACKWARD_RATIO = THRUST_MAX_BWD / THRUST_MAX_FWD;
    THRUST_DEADBAND_EPS = this->get_parameter("thrust_deadband").as_double();
    MOTOR_DRIVER_DEADBAND = this->get_parameter("motor_driver_deadband").as_double();
    FORCE_MAX = this->get_parameter("max_force").as_double();
    TORQUE_MAX = this->get_parameter("max_torque").as_double();
    THRUST_MAX_FWD_N = THRUST_MAX_FWD * KGF2N;
    THRUST_MAX_BWD_N = THRUST_MAX_BWD * KGF2N;
    last_motor_command.resize(8, 0);
    for (int i = 0; i < this->get_parameter("num_motors").as_int(); ++i)
    {
        motors[i]["surge"] = this->get_parameter(string(motor_names[i] + ".surge")).as_double();
        motors[i]["sway"] = this->get_parameter(string(motor_names[i] + ".sway")).as_double();
        motors[i]["heave"] = this->get_parameter(string(motor_names[i] + ".heave")).as_double();
        motors[i]["roll"] = this->get_parameter(string(motor_names[i] + ".roll")).as_double();
        motors[i]["pitch"] = this->get_parameter(string(motor_names[i] + ".pitch")).as_double();
        motors[i]["yaw"] = this->get_parameter(string(motor_names[i] + ".yaw")).as_double();
    }

}

void Thruster_manager::cmd_Callback(const bur_rov_msgs::msg::Command::SharedPtr msg)
{
    this->output.auxilary.clear();
    this->output.buttons.clear();
    for (uint8_t i = 0; i < msg->auxilary.size(); i++)
    {
        this->output.auxilary.push_back(msg->auxilary[i]);
    }
    for (uint8_t i = 0; i < msg->buttons.size(); i++)
    {
        this->output.buttons.push_back(msg->buttons[i]);
    }
    // runNode();
}

void Thruster_manager::wrench_Callback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg)
{
    pwr[0] = msg->wrench.force.x;   // surge
    pwr[1] = -msg->wrench.force.y;  // sway
    pwr[2] = -msg->wrench.force.z;  // heave
    pwr[3] = msg->wrench.torque.x;  // roll
    pwr[4] = -msg->wrench.torque.y; // pitch
    pwr[5] = -msg->wrench.torque.z; // yaw
    runNode();
}

// Takes in thrust command in Newtons and returns motor commands in [-1,1] scaled accordingly with deadbands
double Thruster_manager::thrust_to_motor_comm(const double thrust_n)
{
    // Returns motor comms
    if (abs(thrust_n) < THRUST_DEADBAND_EPS)
    {
        return 0;
    }
    else if (thrust_n > 0)
    {
        return CommonFunctions::Interpolate(thrust_n, 0, THRUST_MAX_FWD_N, MOTOR_DRIVER_DEADBAND, 1);
    }
    else
    {
        return CommonFunctions::Interpolate(thrust_n, 0, -THRUST_MAX_BWD_N, -MOTOR_DRIVER_DEADBAND, -1);
    }
} // End of thrust_to_motor function

// Allocate thrusts to motors (generic)
void Thruster_manager::allocate_generic_motors(std::map<std::string, double> &des_forces, std::vector<double> &des_motor_thrusts)
{
    // Loop through each motor
    for (size_t i = 0; i < motors.size(); ++i)
    {
        std::map<std::string, double> motor = motors[i];
        // Loop through each direction
        for (auto const &DOF : constants::DOFs)
        {
            des_motor_thrusts[i] += des_forces[DOF] * motor[DOF];
        }
    }
}

double Thruster_manager::rateLimitMotorCommand(double new_command, double last_command) const
{
    if (abs(last_command) < MOTOR_DRIVER_DEADBAND && new_command >= MOTOR_DRIVER_DEADBAND)
    {
        return MOTOR_DRIVER_DEADBAND;
    }
    else if (abs(last_command) < MOTOR_DRIVER_DEADBAND && new_command <= -MOTOR_DRIVER_DEADBAND)
    {
        return -MOTOR_DRIVER_DEADBAND;
    }
    else
    {
        return CommonFunctions::Clamp(new_command, last_command - max_step_per_loop, last_command + max_step_per_loop); // Rate limit
    }
}

void Thruster_manager::runNode()
{
    // Assemble desired commands, ensure proper ranges and convert to force/torque requests
    // DOF order: surge, sway, heave, roll, pitch, yaw)
    std::map<std::string, double> des_forces;
    des_forces["surge"] = FORCE_MAX * CommonFunctions::Clamp(pwr[0], -1, 1);
    des_forces["sway"] = FORCE_MAX * CommonFunctions::Clamp(pwr[1], -1, 1);
    des_forces["heave"] = FORCE_MAX * CommonFunctions::Clamp(pwr[2], -1, 1);
    des_forces["roll"] = TORQUE_MAX * CommonFunctions::Clamp(pwr[3], -1, 1);
    des_forces["pitch"] = TORQUE_MAX * CommonFunctions::Clamp(pwr[4], -1, 1);
    des_forces["yaw"] = TORQUE_MAX * CommonFunctions::Clamp(pwr[5], -1, 1);

    // Force direction prioritization to deal with saturation
    // NOTE: there are many corner cases that this logic doesn't handle
    std::vector<double> des_motor_thrusts(motors.size(), 0);

    allocate_generic_motors(des_forces, des_motor_thrusts);

    // Convert motor thrusts to commands
    std::vector<float> motor_comms(motors.size(), 0);
    // Publish message
    this->output.thrusters.clear();

    if(this->test_mode == false) {
        for (size_t i = 0; i < motors.size(); ++i) {
            double m_comms = thrust_to_motor_comm(des_motor_thrusts[i]);
            m_comms = CommonFunctions::Clamp(m_comms, -1.0, 1.0); // Clamp just in case
            // std::cout << "m_comms " << i << " " << m_comms << " last_cmd " << last_motor_command[i]<< std::endl;
            motor_comms[i] = (float)rateLimitMotorCommand(m_comms, last_motor_command[i]);
            this->output.thrusters.push_back(CommonFunctions::Clamp(motor_comms[i], -1.0, 1.0));
            // Store the last command so we can ramp it
            last_motor_command[i] = motor_comms[i];
        }
    } else {
        for (size_t i = 0; i < motors.size(); ++i) {
            this->output.thrusters.push_back(output.buttons[i]);
        }
    }

    cmd_pub->publish(this->output);
} // End of run node

void Thruster_manager::shutdown()
{
    for (size_t i = 0; i < motors.size(); i++)
    {
        this->output.thrusters.push_back(0);
    }
    cmd_pub->publish(this->output);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Thruster_manager>();
    rclcpp::spin(node);
    node->shutdown();
    rclcpp::shutdown();

    return 0;
}

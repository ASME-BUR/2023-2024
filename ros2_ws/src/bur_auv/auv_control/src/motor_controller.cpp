#include "motor_controller.hpp"

using std::placeholders::_1;

Motor_controller::Motor_controller() : rclcpp::Node("motor_controller")
{
    // Parameters
    this->declare_parameter("sub_topic", "alloc_cmd");
    this->declare_parameter("pub_topic", "pwm_command_list");
    this->declare_parameter("pi_address", "192.168.8.157");
    this->declare_parameter("pi_port", "8888");
    this->declare_parameter("rate_hz", 20.0);
    this->declare_parameter("enable_priorities", true);
    this->declare_parameter("ramp_time", 1.0);
    this->declare_parameter("num_motors", 6);
    // Parameter Lists
    const std::vector<std::string> &allocation_priorities_param = {"yaw", "roll", "pitch", "surge", "sway", "heave"};
    this->declare_parameter("allocation_priorities", allocation_priorities_param);
    const std::map<std::string, double> &motor = {{"surge", 0.0}, {"sway", 0.0}, {"heave", 0.0}, {"roll", 0.0}, {"pitch", 0.0}, {"yaw", 0.0}};

    for (size_t i = 0; i < this->get_parameter("num_motors").as_int(); i++)
    {
        this->declare_parameters(string("motor" + to_string(i)), motor);
        motor_names.push_back(string("motor" + to_string(i)));
    }

    alloc_sub_ = this->create_subscription<auv_msgs::msg::AllocatorCommand>(
        this->get_parameter("sub_topic").as_string(), 1, std::bind(&Motor_controller::alloc_Callback, this, _1));
    cmd_pub_ = this->create_publisher<auv_msgs::msg::MotorCommandList>(
        this->get_parameter("pub_topic").as_string(), 1);

    setVariables();
}

void Motor_controller::setVariables()
{
    double ramp_time = this->get_parameter("ramp_time").as_double();
    rate_hz = this->get_parameter("rate_hz").as_double();
    enable_priorities = this->get_parameter("enable_priorities").as_bool();
    loop_rate = std::make_unique<rclcpp::Rate>(rate_hz);

    if (ramp_time > 0)
    {
        max_step_per_loop = (1.0 / ramp_time) / (double)rate_hz;
    }
    else
    {
        max_step_per_loop = 10; // Massive number to completely disable ramping
    }

    allocation_priorities = this->get_parameter("allocation_priorities").as_string_array();

    for (int i = 0; i < this->get_parameter("num_motors").as_int(); ++i)
    {
        motors[i]["surge"] = this->get_parameter(string("motor" + to_string(i) + ".surge")).as_double();
        motors[i]["sway"] = this->get_parameter(string("motor" + to_string(i) + ".sway")).as_double();
        motors[i]["heave"] = this->get_parameter(string("motor" + to_string(i) + ".heave")).as_double();
        motors[i]["roll"] = this->get_parameter(string("motor" + to_string(i) + ".roll")).as_double();
        motors[i]["pitch"] = this->get_parameter(string("motor" + to_string(i) + ".pitch")).as_double();
        motors[i]["yaw"] = this->get_parameter(string("motor" + to_string(i) + ".yaw")).as_double();
    }
}

void Motor_controller::alloc_Callback(const auv_msgs::msg::AllocatorCommand::SharedPtr msg)
{
    pwr[0] = msg->axes_command[0]; // surge
    // Flip for frame conversion
    pwr[1] = -msg->axes_command[1]; // sway
    pwr[2] = -msg->axes_command[2]; // heave
    pwr[3] = msg->axes_command[3];  // roll
    // Flip for frame conversion
    pwr[4] = -msg->axes_command[4]; // pitch
    pwr[5] = -msg->axes_command[5]; // yaw
    runNode();
}

// Takes in thrust command in Newtons and returns motor commands in [-1,1] scaled accordingly with deadbands
double Motor_controller::thrust_to_motor_comm(const double thrust_n)
{
    // Returns motor comms
    if (abs(thrust_n) < constants::THRUST_DEADBAND_EPS)
    {
        return 0;
    }
    else if (thrust_n > 0)
    {
        return CommonFunctions::Interpolate(thrust_n, 0, constants::THRUST_MAX_FWD_N, constants::MOTOR_DRIVER_DEADBAND, 1);
    }
    else
    {
        return CommonFunctions::Interpolate(thrust_n, 0, -constants::THRUST_MAX_BWD_N, -constants::MOTOR_DRIVER_DEADBAND, -1);
    }
} // End of thrust_to_motor function

// Allocate thrusts to motors (generic)
void Motor_controller::allocate_generic_motors(std::map<std::string, double> &des_forces, std::vector<double> &des_motor_thrusts)
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

// Allocate thrusts to motors (prioritized)
void Motor_controller::allocate_prioritized_motors(std::map<std::string, double> &des_forces, std::vector<double> &des_motor_thrusts)
{ // NB: the incoming des_motor_thrusts should be all zeros)
    for (size_t i = 0; i < allocation_priorities.size(); ++i)
    {
        // Current allocation priority
        std::string curr_allocation = allocation_priorities[i];

        std::vector<double> des_motor_thrusts_new(motors.size(), 0);

        for (size_t j = 0; j < motors.size(); ++j)
        {
            std::map<std::string, double> motor = motors[j];
            des_motor_thrusts_new[j] = des_forces[curr_allocation] * motor[curr_allocation];
        }

        // If new thrusts are in the same direction as already saturated thrusts, then skip this direction

        std::vector<bool> curr_saturated_fwd(des_motor_thrusts.size(), false);
        std::vector<bool> curr_saturated_bwd(des_motor_thrusts.size(), false);
        std::vector<bool> curr_saturated(curr_saturated_fwd.size(), false);
        for (size_t j = 0; j < des_motor_thrusts.size(); ++j)
        {
            if (des_motor_thrusts[j] > constants::THRUST_MAX_FWD && abs(des_motor_thrusts[j]) > constants::THRUST_DEADBAND_EPS)
            {
                curr_saturated_fwd[j] = true;
            }
            if (des_motor_thrusts[j] < -constants::THRUST_MAX_BWD && abs(des_motor_thrusts[j]) > constants::THRUST_DEADBAND_EPS)
            {
                curr_saturated_bwd[j] = true;
            }
            if (curr_saturated_fwd[j] && curr_saturated_bwd[j])
            {
                curr_saturated[j] = true;
            }
        }

        std::vector<bool> curr_directions(des_motor_thrusts.size(), false);
        std::vector<bool> new_directions(des_motor_thrusts_new.size(), false);
        std::vector<bool> same_directions(curr_directions.size(), false);
        for (size_t j = 0; j < des_motor_thrusts_new.size(); ++j)
        {
            if (des_motor_thrusts[j] > 0)
            {
                curr_directions[j] = true;
            }
            if (des_motor_thrusts_new[j] > 0)
            {
                new_directions[j] = true;
            }
            if (curr_directions[j] == new_directions[j])
            {
                same_directions[j] = true;
            }
        }

        int check = 0;
        for (size_t j = 0; j < curr_saturated.size(); ++j)
        {
            if (curr_saturated[j] == same_directions[j])
            {
                check = check + 1; // Break out of loop
            }
        }

        if (check > 0)
        {
            continue;
        }

        // If adding causes saturation, then scale requested force to only saturate the most saturated motor
        std::vector<double> des_motor_thrusts_tmp(des_motor_thrusts_new.size(), 0);
        for (size_t j = 0; j < des_motor_thrusts.size(); ++j)
        {
            des_motor_thrusts_tmp[j] = des_motor_thrusts[j] + des_motor_thrusts_new[j];
        }

        // TODO : find largest saturation relative to approximate MAX
        std::vector<double> saturations(motors.size(), 0);
        double des_thrust_new = 0;
        for (size_t j = 0; j < motors.size(); ++j)
        {
            des_thrust_new = des_motor_thrusts_tmp[j];
            if (des_thrust_new > 0 && des_thrust_new > constants::THRUST_MAX_FWD_N)
            {
                saturations[j] = abs(des_thrust_new - constants::THRUST_MAX_FWD_N);
            }
            else if (des_thrust_new < 0 && des_thrust_new < -constants::THRUST_MAX_BWD_N)
            {
                saturations[j] = abs(des_thrust_new - (-constants::THRUST_MAX_BWD_N));
            }
            else
            {
                saturations[j] = 0;
            }
        }

        // Argmax of saturations
        long sat_max_i = std::max_element(saturations.begin(), saturations.end()) - saturations.begin();
        double sat_max = *std::max_element(saturations.begin(), saturations.end());

        double scale = 0;

        if (sat_max > 0 && abs(des_motor_thrusts_new[sat_max_i]) > constants::THRUST_DEADBAND_EPS)
        {
            scale = abs((sat_max - des_motor_thrusts_new[sat_max_i]) / des_motor_thrusts_new[sat_max_i]);
        }

        if (scale > 0)
        {
            des_forces[curr_allocation] *= scale;
            for (size_t j = 0; j < motors.size(); ++j)
            {
                std::map<std::string, double> motor = motors[j];
                des_motor_thrusts_new[j] = des_forces[curr_allocation] * motor[curr_allocation];
            }
        }

        for (size_t j = 0; j < des_motor_thrusts.size(); ++j)
        {
            des_motor_thrusts[j] = des_motor_thrusts[j] + des_motor_thrusts_new[j];
        }

    } // End of For Loop
} // End of allocate_prioritized_motors fn

double Motor_controller::rateLimitMotorCommand(double new_command, double last_command) const
{
    if (abs(last_command) < constants::MOTOR_DRIVER_DEADBAND and new_command >= constants::MOTOR_DRIVER_DEADBAND)
    {
        return constants::MOTOR_DRIVER_DEADBAND;
    }
    else if (abs(last_command) < constants::MOTOR_DRIVER_DEADBAND and new_command <= -constants::MOTOR_DRIVER_DEADBAND)
    {
        return -constants::MOTOR_DRIVER_DEADBAND;
    }
    else
    {
        return CommonFunctions::Clamp(new_command, last_command - max_step_per_loop, last_command + max_step_per_loop); // Rate limit
    }
}

void Motor_controller::runNode()
{
    // Assemble desired commands, ensure proper ranges and convert to force/torque requests
    // DOF order: surge, sway, heave, roll, pitch, yaw)
    std::map<std::string, double> des_forces;
    des_forces["surge"] = constants::FORCE_MAX * CommonFunctions::Clamp(pwr[0], -1, 1);
    des_forces["sway"] = constants::FORCE_MAX * CommonFunctions::Clamp(pwr[1], -1, 1);
    des_forces["heave"] = constants::FORCE_MAX * CommonFunctions::Clamp(pwr[2], -1, 1);
    des_forces["roll"] = constants::TORQUE_MAX * CommonFunctions::Clamp(pwr[3], -1, 1);
    des_forces["pitch"] = constants::TORQUE_MAX * CommonFunctions::Clamp(pwr[4], -1, 1);
    des_forces["yaw"] = constants::TORQUE_MAX * CommonFunctions::Clamp(pwr[5], -1, 1);

    // Force direction prioritization to deal with saturation
    // NOTE: there are many corner cases that this logic doesn't handle
    std::vector<double> des_motor_thrusts(motors.size(), 0);
    if (enable_priorities)
    {
        allocate_prioritized_motors(des_forces, des_motor_thrusts);
    }
    else
    {
        allocate_generic_motors(des_forces, des_motor_thrusts);
    }

    // Convert motor thrusts to commands
    std::vector<float> motor_comms(motors.size(), 0);
    for (size_t i = 0; i < des_motor_thrusts.size(); ++i)
    {
        double m_comms = thrust_to_motor_comm(des_motor_thrusts[i]);
        m_comms = CommonFunctions::Clamp(m_comms, -1.0, 1.0); // Clamp just in case
        motor_comms[i] = (float)rateLimitMotorCommand(m_comms, last_motor_command[i]);
    }

    // Publish message
    auto motor_command_msg = auv_msgs::msg::MotorCommandList();
    for (size_t i = 0; i < motors.size(); ++i)
    {
        auto command = auv_msgs::msg::MotorCommand();
        command.name = motor_names[i];
        command.position = motor_comms[i];
        motor_command_msg.motor_commands.push_back(command);
        // Store the last command so we can ramp it
        last_motor_command[i] = motor_comms[i];
    }
    cmd_pub_->publish(motor_command_msg);
} // End of run node

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Motor_controller>());
    rclcpp::shutdown();
    return 0;
}
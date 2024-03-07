#include "pid_component.hpp"

Pid_component::Pid_component(const rclcpp::NodeOptions &options)
    : node_(std::make_shared<rclcpp::Node>("pid", options)), pid_controller(), last_time(0)
{
    // topic parameters
    this->node_->declare_parameter("ctrl_effort_name", "ctrl_effort");
    this->node_->declare_parameter("setpoint_name", "setpoint");
    this->node_->declare_parameter("state_name", "state");

    // pid gain parameters
    this->node_->declare_parameter("P_gain", 1.0);
    this->node_->declare_parameter("I_gain", 1.0);
    this->node_->declare_parameter("D_gain", 1.0);
    this->node_->declare_parameter("I_lim", 5.0);
    this->node_->declare_parameter("Out_lim", 10.0);
    this->node_->declare_parameter("antiwindup", 100.0);
    this->node_->declare_parameter("pid_enable", true);
    this->node_->declare_parameter("angle_wrap_compensation", false);
    this->node_->declare_parameter("cutoff_frequency", 10.0);
    this->node_->declare_parameter("rate", 20);
    this->node_->declare_parameter("enableQOS", false);

    setConstants();
    // RCLCPP_INFO(this->node_->get_logger(), "starttime: '%i'", last_time);

    // Create a callback function for when messages are received.
    // Variations of this function also exist using, for example, UniquePtr for zero-copy transport.
    auto setpoint_callback =
        [this](const typename custom_msg_srv::msg::Float64Stamped::SharedPtr setpoint) -> void
    {
        setpoint_ = setpoint->data;
        new_state_or_setpt_ = true;
    };

    auto state_callback =
        [this](const typename custom_msg_srv::msg::Float64Stamped::SharedPtr state) -> void
    {
        state_ = state->data;
        new_state_or_setpt_ = true;
    };

    // Create a subscription to the "chatter" topic which can be matched with one or more
    // compatible ROS publishers.
    // Note that not all publishers on the same topic with the same type will be compatible:
    // they must have compatible Quality of Service policies.
    setpoint = this->node_->create_subscription<custom_msg_srv::msg::Float64Stamped>(this->node_->get_parameter("setpoint_name").as_string(), 1, setpoint_callback);
    state = this->node_->create_subscription<custom_msg_srv::msg::Float64Stamped>(this->node_->get_parameter("state_name").as_string(), 1, state_callback);
    timer_ = this->node_->create_wall_timer(chrono::milliseconds(1000 / this->node_->get_parameter("rate").as_int()),
                                            bind(&Pid_component::pid_callback, this));
    // Create a publisher of "custom_msg_srv/Float64Stamped" messages on the parameter topic.
    if (this->node_->get_parameter("enableQOS").as_bool() == true)
    {
        // quality of service profile for message filtering
        rclcpp::QoS custom_qos_profile = rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_default))
                                             .history(rmw_qos_history_policy_t::RMW_QOS_POLICY_HISTORY_KEEP_LAST)
                                             .keep_last(1)
                                             .reliability(rmw_qos_reliability_policy_t::RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT)
                                             .durability(rmw_qos_durability_policy_t::RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL)
                                             .avoid_ros_namespace_conventions(false);
        ctrl_effort = this->node_->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->node_->get_parameter("ctrl_effort_name").as_string(),
                                                                                         custom_qos_profile);
    }
    else
    {
        ctrl_effort = this->node_->create_publisher<custom_msg_srv::msg::Float64Stamped>(this->node_->get_parameter("ctrl_effort_name").as_string(),
                                                                                         10);
    }
    last_time = this->node_->now();
}

void Pid_component::setConstants()
{
    double kP = this->node_->get_parameter("P_gain").as_double();
    double kI = this->node_->get_parameter("I_gain").as_double();
    double kD = this->node_->get_parameter("D_gain").as_double();
    double output_limit = this->node_->get_parameter("Out_lim").as_double();
    double integrator_limit = this->node_->get_parameter("I_lim").as_double();
    double antiwindup = this->node_->get_parameter("antiwindup").as_double();
    bool angle_wrap_compensation = this->node_->get_parameter("angle_wrap_compensation").as_bool();
    RCLCPP_INFO(this->node_->get_logger(), "PID state: '%i'", pid_enabled_);
    RCLCPP_INFO(this->node_->get_logger(), "P: '%f' I: '%f' D: '%f' I_lim: '%f' Output_lim: '%f' Antiwindup: '%i'", kP,
                kI, kD, output_limit, integrator_limit, antiwindup);
    pid_controller.setGains(kP, kI, kD, output_limit,
                            integrator_limit, angle_wrap_compensation, antiwindup,
                            this->node_->get_parameter("cutoff_frequency").as_double());

    pid_enabled_ = this->node_->get_parameter("pid_enable").as_bool();
}

void Pid_component::pid_callback()
{
    if (pid_enabled_)
    {
        if (new_state_or_setpt_)
        {
            // calculate delta_t
            rclcpp::Time current_time = this->node_->now();
            rclcpp::Duration diff = current_time - last_time;
            auto diff_ns = diff.to_chrono<chrono::nanoseconds>();
            double delta_time = diff_ns.count() / 1e9;
            // cout << "dt " << delta_time << endl;
            if (delta_time < 0.0001)
            {
                RCLCPP_INFO(this->node_->get_logger(), "delta_t is 0, skipping this loop. Possible overloaded cpu "
                                                       "at time: %f",
                            this->node_->now());
                return;
            }
            // RCLCPP_INFO(this->node_->get_logger(), "dt: '%i'", dt);
            _Float64 cmd = pid_controller.compute(setpoint_, state_, delta_time);
            auto msg = std::make_unique<custom_msg_srv::msg::Float64Stamped>();
            msg->data = cmd;
            msg->header.stamp = this->node_->now();
            ctrl_effort->publish(std::move(msg));
            last_time = this->node_->now();
            new_state_or_setpt_ = false;
        }
    }
}

rclcpp::node_interfaces::NodeBaseInterface::SharedPtr
Pid_component::get_node_base_interface() const
{
    return this->node_->get_node_base_interface();
}

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(Pid_component)
#include <chrono>
#include "rclcpp/time.hpp"
#include "rclcpp/rclcpp.hpp"

#include <message_filters/subscriber.h>
#include "message_filters/sync_policies/approximate_time.h"
#include "message_filters/synchronizer.h"
#include "geometry_msgs/msg/twist.hpp"
#include "custom_msg_srv/msg/float64_stamped.hpp"

using namespace std::chrono_literals;
using StampedFloatMsg = custom_msg_srv::msg::Float64Stamped;
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;
using std::placeholders::_4;
using std::placeholders::_5;
using std::placeholders::_6;

class Pid_recombiner : public rclcpp::Node
{
public:
    Pid_recombiner()
        : Node("pid_recombiner")
    {
        custom_qos_profile.depth = 10;
        custom_qos_profile.reliability = rmw_qos_reliability_policy_t::RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
        custom_qos_profile.history = rmw_qos_history_policy_t::RMW_QOS_POLICY_HISTORY_KEEP_LAST;
        custom_qos_profile.durability = rmw_qos_durability_policy_t::RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL;

        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("target", 10);

        const std::map<std::string, std::string> &ctrl_effort = {
            {"x", "ctrl_effort_x"},
            {"y", "ctrl_effort_y"},
            {"z", "ctrl_effort_z"},
            {"rx", "ctrl_effort_rx"},
            {"ry", "ctrl_effort_ry"},
            {"rz", "ctrl_effort_rz"}};
        this->declare_parameters("ctrl_effort", ctrl_effort);

        // 6 pid controller outputs
        sub_x.subscribe(this, this->get_parameter("ctrl_effort.x").as_string(), custom_qos_profile);
        sub_y.subscribe(this, this->get_parameter("ctrl_effort.y").as_string(), custom_qos_profile);
        sub_z.subscribe(this, this->get_parameter("ctrl_effort.z").as_string(), custom_qos_profile);
        sub_rx.subscribe(this, this->get_parameter("ctrl_effort.rx").as_string(), custom_qos_profile);
        sub_ry.subscribe(this, this->get_parameter("ctrl_effort.ry").as_string(), custom_qos_profile);
        sub_rz.subscribe(this, this->get_parameter("ctrl_effort.rz").as_string(), custom_qos_profile);

        // register the approximate time callback
        syncApproximate = std::make_shared<message_filters::Synchronizer<approximate_policy>>(1);
        syncApproximate->connectInput(sub_x, sub_y, sub_z, sub_rx, sub_ry, sub_rz);
        syncApproximate->setMaxIntervalDuration(rclcpp::Duration(10, 0));
        syncApproximate->registerCallback(std::bind(&Pid_recombiner::ctrl_effort_callback, this, _1, _2, _3, _4, _5, _6));
    }

private:
    void ctrl_effort_callback(const StampedFloatMsg::ConstSharedPtr &msg_x, const StampedFloatMsg::ConstSharedPtr &msg_rx,
                              const StampedFloatMsg::ConstSharedPtr &msg_y, const StampedFloatMsg::ConstSharedPtr &msg_ry,
                              const StampedFloatMsg::ConstSharedPtr &msg_z, const StampedFloatMsg::ConstSharedPtr &msg_rz) const
    {
        RCLCPP_INFO(this->get_logger(), "received");
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = msg_x->data;
        msg.linear.y = msg_y->data;
        msg.linear.z = msg_z->data;
        msg.angular.x = msg_rx->data;
        msg.angular.y = msg_ry->data;
        msg.angular.z = msg_rz->data;
        publisher_->publish(msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    message_filters::Subscriber<StampedFloatMsg> sub_x;
    message_filters::Subscriber<StampedFloatMsg> sub_y;
    message_filters::Subscriber<StampedFloatMsg> sub_z;
    message_filters::Subscriber<StampedFloatMsg> sub_rx;
    message_filters::Subscriber<StampedFloatMsg> sub_ry;
    message_filters::Subscriber<StampedFloatMsg> sub_rz;

    // quality of service (QOS) profile
    rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;

    // approx time policy
    typedef message_filters::sync_policies::ApproximateTime<StampedFloatMsg, StampedFloatMsg,
                                                            StampedFloatMsg, StampedFloatMsg,
                                                            StampedFloatMsg, StampedFloatMsg>
        approximate_policy;

    // Synchronizer must be a class member
    std::shared_ptr<message_filters::Synchronizer<approximate_policy>> syncApproximate;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pid_recombiner>());
    rclcpp::shutdown();
    return 0;
}
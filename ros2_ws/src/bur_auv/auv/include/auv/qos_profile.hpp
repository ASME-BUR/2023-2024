#include "rclcpp/rclcpp.hpp"

rclcpp::QoS custom_qos_profile = rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_default))
                                     .history(rmw_qos_history_policy_t::RMW_QOS_POLICY_HISTORY_KEEP_LAST)
                                     .keep_last(1)
                                     .reliability(rmw_qos_reliability_policy_t::RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT)
                                     .durability(rmw_qos_durability_policy_t::RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL)
                                     .avoid_ros_namespace_conventions(false);


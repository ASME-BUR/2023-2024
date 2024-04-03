// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__BUILDER_HPP_
#define ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zed_interfaces/msg/detail/heartbeat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zed_interfaces
{

namespace msg
{

namespace builder
{

class Init_Heartbeat_simul_mode
{
public:
  explicit Init_Heartbeat_simul_mode(::zed_interfaces::msg::Heartbeat & msg)
  : msg_(msg)
  {}
  ::zed_interfaces::msg::Heartbeat simul_mode(::zed_interfaces::msg::Heartbeat::_simul_mode_type arg)
  {
    msg_.simul_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

class Init_Heartbeat_svo_mode
{
public:
  explicit Init_Heartbeat_svo_mode(::zed_interfaces::msg::Heartbeat & msg)
  : msg_(msg)
  {}
  Init_Heartbeat_simul_mode svo_mode(::zed_interfaces::msg::Heartbeat::_svo_mode_type arg)
  {
    msg_.svo_mode = std::move(arg);
    return Init_Heartbeat_simul_mode(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

class Init_Heartbeat_camera_sn
{
public:
  explicit Init_Heartbeat_camera_sn(::zed_interfaces::msg::Heartbeat & msg)
  : msg_(msg)
  {}
  Init_Heartbeat_svo_mode camera_sn(::zed_interfaces::msg::Heartbeat::_camera_sn_type arg)
  {
    msg_.camera_sn = std::move(arg);
    return Init_Heartbeat_svo_mode(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

class Init_Heartbeat_full_name
{
public:
  explicit Init_Heartbeat_full_name(::zed_interfaces::msg::Heartbeat & msg)
  : msg_(msg)
  {}
  Init_Heartbeat_camera_sn full_name(::zed_interfaces::msg::Heartbeat::_full_name_type arg)
  {
    msg_.full_name = std::move(arg);
    return Init_Heartbeat_camera_sn(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

class Init_Heartbeat_node_name
{
public:
  explicit Init_Heartbeat_node_name(::zed_interfaces::msg::Heartbeat & msg)
  : msg_(msg)
  {}
  Init_Heartbeat_full_name node_name(::zed_interfaces::msg::Heartbeat::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_Heartbeat_full_name(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

class Init_Heartbeat_node_ns
{
public:
  explicit Init_Heartbeat_node_ns(::zed_interfaces::msg::Heartbeat & msg)
  : msg_(msg)
  {}
  Init_Heartbeat_node_name node_ns(::zed_interfaces::msg::Heartbeat::_node_ns_type arg)
  {
    msg_.node_ns = std::move(arg);
    return Init_Heartbeat_node_name(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

class Init_Heartbeat_beat_count
{
public:
  Init_Heartbeat_beat_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Heartbeat_node_ns beat_count(::zed_interfaces::msg::Heartbeat::_beat_count_type arg)
  {
    msg_.beat_count = std::move(arg);
    return Init_Heartbeat_node_ns(msg_);
  }

private:
  ::zed_interfaces::msg::Heartbeat msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zed_interfaces::msg::Heartbeat>()
{
  return zed_interfaces::msg::builder::Init_Heartbeat_beat_count();
}

}  // namespace zed_interfaces

#endif  // ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__BUILDER_HPP_

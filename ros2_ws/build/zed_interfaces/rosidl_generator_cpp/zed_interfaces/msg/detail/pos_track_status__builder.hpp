// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zed_interfaces:msg/PosTrackStatus.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__POS_TRACK_STATUS__BUILDER_HPP_
#define ZED_INTERFACES__MSG__DETAIL__POS_TRACK_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zed_interfaces/msg/detail/pos_track_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zed_interfaces
{

namespace msg
{

namespace builder
{

class Init_PosTrackStatus_status
{
public:
  Init_PosTrackStatus_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zed_interfaces::msg::PosTrackStatus status(::zed_interfaces::msg::PosTrackStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zed_interfaces::msg::PosTrackStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zed_interfaces::msg::PosTrackStatus>()
{
  return zed_interfaces::msg::builder::Init_PosTrackStatus_status();
}

}  // namespace zed_interfaces

#endif  // ZED_INTERFACES__MSG__DETAIL__POS_TRACK_STATUS__BUILDER_HPP_

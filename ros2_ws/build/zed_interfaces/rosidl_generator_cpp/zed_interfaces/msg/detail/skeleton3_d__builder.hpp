// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zed_interfaces:msg/Skeleton3D.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__SKELETON3_D__BUILDER_HPP_
#define ZED_INTERFACES__MSG__DETAIL__SKELETON3_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zed_interfaces/msg/detail/skeleton3_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zed_interfaces
{

namespace msg
{

namespace builder
{

class Init_Skeleton3D_keypoints
{
public:
  Init_Skeleton3D_keypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zed_interfaces::msg::Skeleton3D keypoints(::zed_interfaces::msg::Skeleton3D::_keypoints_type arg)
  {
    msg_.keypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zed_interfaces::msg::Skeleton3D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zed_interfaces::msg::Skeleton3D>()
{
  return zed_interfaces::msg::builder::Init_Skeleton3D_keypoints();
}

}  // namespace zed_interfaces

#endif  // ZED_INTERFACES__MSG__DETAIL__SKELETON3_D__BUILDER_HPP_

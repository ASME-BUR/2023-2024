// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:msg/DepthInfoStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__DEPTH_INFO_STAMPED__TRAITS_HPP_
#define ZED_INTERFACES__MSG__DETAIL__DEPTH_INFO_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/msg/detail/depth_info_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace zed_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DepthInfoStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: min_depth
  {
    out << "min_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.min_depth, out);
    out << ", ";
  }

  // member: max_depth
  {
    out << "max_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.max_depth, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DepthInfoStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: min_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.min_depth, out);
    out << "\n";
  }

  // member: max_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.max_depth, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DepthInfoStamped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace zed_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zed_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_interfaces::msg::DepthInfoStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::msg::DepthInfoStamped & msg)
{
  return zed_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::msg::DepthInfoStamped>()
{
  return "zed_interfaces::msg::DepthInfoStamped";
}

template<>
inline const char * name<zed_interfaces::msg::DepthInfoStamped>()
{
  return "zed_interfaces/msg/DepthInfoStamped";
}

template<>
struct has_fixed_size<zed_interfaces::msg::DepthInfoStamped>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<zed_interfaces::msg::DepthInfoStamped>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<zed_interfaces::msg::DepthInfoStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__MSG__DETAIL__DEPTH_INFO_STAMPED__TRAITS_HPP_

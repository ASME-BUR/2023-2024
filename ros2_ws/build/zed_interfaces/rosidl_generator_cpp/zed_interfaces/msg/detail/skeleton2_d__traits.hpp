// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:msg/Skeleton2D.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__SKELETON2_D__TRAITS_HPP_
#define ZED_INTERFACES__MSG__DETAIL__SKELETON2_D__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/msg/detail/skeleton2_d__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'keypoints'
#include "zed_interfaces/msg/detail/keypoint2_df__traits.hpp"

namespace zed_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Skeleton2D & msg,
  std::ostream & out)
{
  out << "{";
  // member: keypoints
  {
    if (msg.keypoints.size() == 0) {
      out << "keypoints: []";
    } else {
      out << "keypoints: [";
      size_t pending_items = msg.keypoints.size();
      for (auto item : msg.keypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Skeleton2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: keypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.keypoints.size() == 0) {
      out << "keypoints: []\n";
    } else {
      out << "keypoints:\n";
      for (auto item : msg.keypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Skeleton2D & msg, bool use_flow_style = false)
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
  const zed_interfaces::msg::Skeleton2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::msg::Skeleton2D & msg)
{
  return zed_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::msg::Skeleton2D>()
{
  return "zed_interfaces::msg::Skeleton2D";
}

template<>
inline const char * name<zed_interfaces::msg::Skeleton2D>()
{
  return "zed_interfaces/msg/Skeleton2D";
}

template<>
struct has_fixed_size<zed_interfaces::msg::Skeleton2D>
  : std::integral_constant<bool, has_fixed_size<zed_interfaces::msg::Keypoint2Df>::value> {};

template<>
struct has_bounded_size<zed_interfaces::msg::Skeleton2D>
  : std::integral_constant<bool, has_bounded_size<zed_interfaces::msg::Keypoint2Df>::value> {};

template<>
struct is_message<zed_interfaces::msg::Skeleton2D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__MSG__DETAIL__SKELETON2_D__TRAITS_HPP_

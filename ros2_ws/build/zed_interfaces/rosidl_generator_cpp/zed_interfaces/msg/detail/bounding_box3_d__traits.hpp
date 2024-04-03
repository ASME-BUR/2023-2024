// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:msg/BoundingBox3D.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__BOUNDING_BOX3_D__TRAITS_HPP_
#define ZED_INTERFACES__MSG__DETAIL__BOUNDING_BOX3_D__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/msg/detail/bounding_box3_d__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'corners'
#include "zed_interfaces/msg/detail/keypoint3_d__traits.hpp"

namespace zed_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BoundingBox3D & msg,
  std::ostream & out)
{
  out << "{";
  // member: corners
  {
    if (msg.corners.size() == 0) {
      out << "corners: []";
    } else {
      out << "corners: [";
      size_t pending_items = msg.corners.size();
      for (auto item : msg.corners) {
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
  const BoundingBox3D & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: corners
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.corners.size() == 0) {
      out << "corners: []\n";
    } else {
      out << "corners:\n";
      for (auto item : msg.corners) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoundingBox3D & msg, bool use_flow_style = false)
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
  const zed_interfaces::msg::BoundingBox3D & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::msg::BoundingBox3D & msg)
{
  return zed_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::msg::BoundingBox3D>()
{
  return "zed_interfaces::msg::BoundingBox3D";
}

template<>
inline const char * name<zed_interfaces::msg::BoundingBox3D>()
{
  return "zed_interfaces/msg/BoundingBox3D";
}

template<>
struct has_fixed_size<zed_interfaces::msg::BoundingBox3D>
  : std::integral_constant<bool, has_fixed_size<zed_interfaces::msg::Keypoint3D>::value> {};

template<>
struct has_bounded_size<zed_interfaces::msg::BoundingBox3D>
  : std::integral_constant<bool, has_bounded_size<zed_interfaces::msg::Keypoint3D>::value> {};

template<>
struct is_message<zed_interfaces::msg::BoundingBox3D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__MSG__DETAIL__BOUNDING_BOX3_D__TRAITS_HPP_

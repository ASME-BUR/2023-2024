// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:msg/PlaneStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__PLANE_STAMPED__TRAITS_HPP_
#define ZED_INTERFACES__MSG__DETAIL__PLANE_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/msg/detail/plane_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'mesh'
#include "shape_msgs/msg/detail/mesh__traits.hpp"
// Member 'coefficients'
#include "shape_msgs/msg/detail/plane__traits.hpp"
// Member 'normal'
// Member 'center'
#include "geometry_msgs/msg/detail/point32__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/transform__traits.hpp"
// Member 'bounds'
#include "geometry_msgs/msg/detail/polygon__traits.hpp"

namespace zed_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PlaneStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: mesh
  {
    out << "mesh: ";
    to_flow_style_yaml(msg.mesh, out);
    out << ", ";
  }

  // member: coefficients
  {
    out << "coefficients: ";
    to_flow_style_yaml(msg.coefficients, out);
    out << ", ";
  }

  // member: normal
  {
    out << "normal: ";
    to_flow_style_yaml(msg.normal, out);
    out << ", ";
  }

  // member: center
  {
    out << "center: ";
    to_flow_style_yaml(msg.center, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: extents
  {
    if (msg.extents.size() == 0) {
      out << "extents: []";
    } else {
      out << "extents: [";
      size_t pending_items = msg.extents.size();
      for (auto item : msg.extents) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bounds
  {
    out << "bounds: ";
    to_flow_style_yaml(msg.bounds, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlaneStamped & msg,
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

  // member: mesh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mesh:\n";
    to_block_style_yaml(msg.mesh, out, indentation + 2);
  }

  // member: coefficients
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coefficients:\n";
    to_block_style_yaml(msg.coefficients, out, indentation + 2);
  }

  // member: normal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "normal:\n";
    to_block_style_yaml(msg.normal, out, indentation + 2);
  }

  // member: center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center:\n";
    to_block_style_yaml(msg.center, out, indentation + 2);
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: extents
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.extents.size() == 0) {
      out << "extents: []\n";
    } else {
      out << "extents:\n";
      for (auto item : msg.extents) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: bounds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounds:\n";
    to_block_style_yaml(msg.bounds, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlaneStamped & msg, bool use_flow_style = false)
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
  const zed_interfaces::msg::PlaneStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::msg::PlaneStamped & msg)
{
  return zed_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::msg::PlaneStamped>()
{
  return "zed_interfaces::msg::PlaneStamped";
}

template<>
inline const char * name<zed_interfaces::msg::PlaneStamped>()
{
  return "zed_interfaces/msg/PlaneStamped";
}

template<>
struct has_fixed_size<zed_interfaces::msg::PlaneStamped>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point32>::value && has_fixed_size<geometry_msgs::msg::Polygon>::value && has_fixed_size<geometry_msgs::msg::Transform>::value && has_fixed_size<shape_msgs::msg::Mesh>::value && has_fixed_size<shape_msgs::msg::Plane>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<zed_interfaces::msg::PlaneStamped>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point32>::value && has_bounded_size<geometry_msgs::msg::Polygon>::value && has_bounded_size<geometry_msgs::msg::Transform>::value && has_bounded_size<shape_msgs::msg::Mesh>::value && has_bounded_size<shape_msgs::msg::Plane>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<zed_interfaces::msg::PlaneStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__MSG__DETAIL__PLANE_STAMPED__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__TRAITS_HPP_
#define ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/msg/detail/heartbeat__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zed_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Heartbeat & msg,
  std::ostream & out)
{
  out << "{";
  // member: beat_count
  {
    out << "beat_count: ";
    rosidl_generator_traits::value_to_yaml(msg.beat_count, out);
    out << ", ";
  }

  // member: node_ns
  {
    out << "node_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.node_ns, out);
    out << ", ";
  }

  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << ", ";
  }

  // member: full_name
  {
    out << "full_name: ";
    rosidl_generator_traits::value_to_yaml(msg.full_name, out);
    out << ", ";
  }

  // member: camera_sn
  {
    out << "camera_sn: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_sn, out);
    out << ", ";
  }

  // member: svo_mode
  {
    out << "svo_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.svo_mode, out);
    out << ", ";
  }

  // member: simul_mode
  {
    out << "simul_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.simul_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Heartbeat & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: beat_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "beat_count: ";
    rosidl_generator_traits::value_to_yaml(msg.beat_count, out);
    out << "\n";
  }

  // member: node_ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_ns: ";
    rosidl_generator_traits::value_to_yaml(msg.node_ns, out);
    out << "\n";
  }

  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }

  // member: full_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "full_name: ";
    rosidl_generator_traits::value_to_yaml(msg.full_name, out);
    out << "\n";
  }

  // member: camera_sn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_sn: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_sn, out);
    out << "\n";
  }

  // member: svo_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svo_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.svo_mode, out);
    out << "\n";
  }

  // member: simul_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "simul_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.simul_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Heartbeat & msg, bool use_flow_style = false)
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
  const zed_interfaces::msg::Heartbeat & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::msg::Heartbeat & msg)
{
  return zed_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::msg::Heartbeat>()
{
  return "zed_interfaces::msg::Heartbeat";
}

template<>
inline const char * name<zed_interfaces::msg::Heartbeat>()
{
  return "zed_interfaces/msg/Heartbeat";
}

template<>
struct has_fixed_size<zed_interfaces::msg::Heartbeat>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_interfaces::msg::Heartbeat>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zed_interfaces::msg::Heartbeat>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__TRAITS_HPP_

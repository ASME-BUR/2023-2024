// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__OBJECT__TRAITS_HPP_
#define ZED_INTERFACES__MSG__DETAIL__OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/msg/detail/object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'bounding_box_2d'
#include "zed_interfaces/msg/detail/bounding_box2_di__traits.hpp"
// Member 'bounding_box_3d'
// Member 'head_bounding_box_3d'
#include "zed_interfaces/msg/detail/bounding_box3_d__traits.hpp"
// Member 'head_bounding_box_2d'
#include "zed_interfaces/msg/detail/bounding_box2_df__traits.hpp"
// Member 'skeleton_2d'
#include "zed_interfaces/msg/detail/skeleton2_d__traits.hpp"
// Member 'skeleton_3d'
#include "zed_interfaces/msg/detail/skeleton3_d__traits.hpp"

namespace zed_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Object & msg,
  std::ostream & out)
{
  out << "{";
  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << ", ";
  }

  // member: label_id
  {
    out << "label_id: ";
    rosidl_generator_traits::value_to_yaml(msg.label_id, out);
    out << ", ";
  }

  // member: sublabel
  {
    out << "sublabel: ";
    rosidl_generator_traits::value_to_yaml(msg.sublabel, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position_covariance
  {
    if (msg.position_covariance.size() == 0) {
      out << "position_covariance: []";
    } else {
      out << "position_covariance: [";
      size_t pending_items = msg.position_covariance.size();
      for (auto item : msg.position_covariance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: velocity
  {
    if (msg.velocity.size() == 0) {
      out << "velocity: []";
    } else {
      out << "velocity: [";
      size_t pending_items = msg.velocity.size();
      for (auto item : msg.velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tracking_available
  {
    out << "tracking_available: ";
    rosidl_generator_traits::value_to_yaml(msg.tracking_available, out);
    out << ", ";
  }

  // member: tracking_state
  {
    out << "tracking_state: ";
    rosidl_generator_traits::value_to_yaml(msg.tracking_state, out);
    out << ", ";
  }

  // member: action_state
  {
    out << "action_state: ";
    rosidl_generator_traits::value_to_yaml(msg.action_state, out);
    out << ", ";
  }

  // member: bounding_box_2d
  {
    out << "bounding_box_2d: ";
    to_flow_style_yaml(msg.bounding_box_2d, out);
    out << ", ";
  }

  // member: bounding_box_3d
  {
    out << "bounding_box_3d: ";
    to_flow_style_yaml(msg.bounding_box_3d, out);
    out << ", ";
  }

  // member: dimensions_3d
  {
    if (msg.dimensions_3d.size() == 0) {
      out << "dimensions_3d: []";
    } else {
      out << "dimensions_3d: [";
      size_t pending_items = msg.dimensions_3d.size();
      for (auto item : msg.dimensions_3d) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: skeleton_available
  {
    out << "skeleton_available: ";
    rosidl_generator_traits::value_to_yaml(msg.skeleton_available, out);
    out << ", ";
  }

  // member: body_format
  {
    out << "body_format: ";
    rosidl_generator_traits::value_to_yaml(msg.body_format, out);
    out << ", ";
  }

  // member: head_bounding_box_2d
  {
    out << "head_bounding_box_2d: ";
    to_flow_style_yaml(msg.head_bounding_box_2d, out);
    out << ", ";
  }

  // member: head_bounding_box_3d
  {
    out << "head_bounding_box_3d: ";
    to_flow_style_yaml(msg.head_bounding_box_3d, out);
    out << ", ";
  }

  // member: head_position
  {
    if (msg.head_position.size() == 0) {
      out << "head_position: []";
    } else {
      out << "head_position: [";
      size_t pending_items = msg.head_position.size();
      for (auto item : msg.head_position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: skeleton_2d
  {
    out << "skeleton_2d: ";
    to_flow_style_yaml(msg.skeleton_2d, out);
    out << ", ";
  }

  // member: skeleton_3d
  {
    out << "skeleton_3d: ";
    to_flow_style_yaml(msg.skeleton_3d, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Object & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
  }

  // member: label_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label_id: ";
    rosidl_generator_traits::value_to_yaml(msg.label_id, out);
    out << "\n";
  }

  // member: sublabel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sublabel: ";
    rosidl_generator_traits::value_to_yaml(msg.sublabel, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position_covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position_covariance.size() == 0) {
      out << "position_covariance: []\n";
    } else {
      out << "position_covariance:\n";
      for (auto item : msg.position_covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocity.size() == 0) {
      out << "velocity: []\n";
    } else {
      out << "velocity:\n";
      for (auto item : msg.velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tracking_available
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracking_available: ";
    rosidl_generator_traits::value_to_yaml(msg.tracking_available, out);
    out << "\n";
  }

  // member: tracking_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracking_state: ";
    rosidl_generator_traits::value_to_yaml(msg.tracking_state, out);
    out << "\n";
  }

  // member: action_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_state: ";
    rosidl_generator_traits::value_to_yaml(msg.action_state, out);
    out << "\n";
  }

  // member: bounding_box_2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounding_box_2d:\n";
    to_block_style_yaml(msg.bounding_box_2d, out, indentation + 2);
  }

  // member: bounding_box_3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounding_box_3d:\n";
    to_block_style_yaml(msg.bounding_box_3d, out, indentation + 2);
  }

  // member: dimensions_3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dimensions_3d.size() == 0) {
      out << "dimensions_3d: []\n";
    } else {
      out << "dimensions_3d:\n";
      for (auto item : msg.dimensions_3d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: skeleton_available
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "skeleton_available: ";
    rosidl_generator_traits::value_to_yaml(msg.skeleton_available, out);
    out << "\n";
  }

  // member: body_format
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_format: ";
    rosidl_generator_traits::value_to_yaml(msg.body_format, out);
    out << "\n";
  }

  // member: head_bounding_box_2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head_bounding_box_2d:\n";
    to_block_style_yaml(msg.head_bounding_box_2d, out, indentation + 2);
  }

  // member: head_bounding_box_3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head_bounding_box_3d:\n";
    to_block_style_yaml(msg.head_bounding_box_3d, out, indentation + 2);
  }

  // member: head_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.head_position.size() == 0) {
      out << "head_position: []\n";
    } else {
      out << "head_position:\n";
      for (auto item : msg.head_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: skeleton_2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "skeleton_2d:\n";
    to_block_style_yaml(msg.skeleton_2d, out, indentation + 2);
  }

  // member: skeleton_3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "skeleton_3d:\n";
    to_block_style_yaml(msg.skeleton_3d, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Object & msg, bool use_flow_style = false)
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
  const zed_interfaces::msg::Object & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::msg::Object & msg)
{
  return zed_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::msg::Object>()
{
  return "zed_interfaces::msg::Object";
}

template<>
inline const char * name<zed_interfaces::msg::Object>()
{
  return "zed_interfaces/msg/Object";
}

template<>
struct has_fixed_size<zed_interfaces::msg::Object>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_interfaces::msg::Object>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zed_interfaces::msg::Object>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__MSG__DETAIL__OBJECT__TRAITS_HPP_

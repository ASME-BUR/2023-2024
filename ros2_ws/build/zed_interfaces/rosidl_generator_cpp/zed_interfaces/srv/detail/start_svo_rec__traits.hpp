// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_interfaces:srv/StartSvoRec.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__SRV__DETAIL__START_SVO_REC__TRAITS_HPP_
#define ZED_INTERFACES__SRV__DETAIL__START_SVO_REC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_interfaces/srv/detail/start_svo_rec__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zed_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartSvoRec_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: bitrate
  {
    out << "bitrate: ";
    rosidl_generator_traits::value_to_yaml(msg.bitrate, out);
    out << ", ";
  }

  // member: compression_mode
  {
    out << "compression_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.compression_mode, out);
    out << ", ";
  }

  // member: target_framerate
  {
    out << "target_framerate: ";
    rosidl_generator_traits::value_to_yaml(msg.target_framerate, out);
    out << ", ";
  }

  // member: input_transcode
  {
    out << "input_transcode: ";
    rosidl_generator_traits::value_to_yaml(msg.input_transcode, out);
    out << ", ";
  }

  // member: svo_filename
  {
    out << "svo_filename: ";
    rosidl_generator_traits::value_to_yaml(msg.svo_filename, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartSvoRec_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bitrate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bitrate: ";
    rosidl_generator_traits::value_to_yaml(msg.bitrate, out);
    out << "\n";
  }

  // member: compression_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "compression_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.compression_mode, out);
    out << "\n";
  }

  // member: target_framerate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_framerate: ";
    rosidl_generator_traits::value_to_yaml(msg.target_framerate, out);
    out << "\n";
  }

  // member: input_transcode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_transcode: ";
    rosidl_generator_traits::value_to_yaml(msg.input_transcode, out);
    out << "\n";
  }

  // member: svo_filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "svo_filename: ";
    rosidl_generator_traits::value_to_yaml(msg.svo_filename, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartSvoRec_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zed_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zed_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_interfaces::srv::StartSvoRec_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::srv::StartSvoRec_Request & msg)
{
  return zed_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::srv::StartSvoRec_Request>()
{
  return "zed_interfaces::srv::StartSvoRec_Request";
}

template<>
inline const char * name<zed_interfaces::srv::StartSvoRec_Request>()
{
  return "zed_interfaces/srv/StartSvoRec_Request";
}

template<>
struct has_fixed_size<zed_interfaces::srv::StartSvoRec_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_interfaces::srv::StartSvoRec_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zed_interfaces::srv::StartSvoRec_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace zed_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartSvoRec_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartSvoRec_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartSvoRec_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zed_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zed_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_interfaces::srv::StartSvoRec_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const zed_interfaces::srv::StartSvoRec_Response & msg)
{
  return zed_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zed_interfaces::srv::StartSvoRec_Response>()
{
  return "zed_interfaces::srv::StartSvoRec_Response";
}

template<>
inline const char * name<zed_interfaces::srv::StartSvoRec_Response>()
{
  return "zed_interfaces/srv/StartSvoRec_Response";
}

template<>
struct has_fixed_size<zed_interfaces::srv::StartSvoRec_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zed_interfaces::srv::StartSvoRec_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zed_interfaces::srv::StartSvoRec_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<zed_interfaces::srv::StartSvoRec>()
{
  return "zed_interfaces::srv::StartSvoRec";
}

template<>
inline const char * name<zed_interfaces::srv::StartSvoRec>()
{
  return "zed_interfaces/srv/StartSvoRec";
}

template<>
struct has_fixed_size<zed_interfaces::srv::StartSvoRec>
  : std::integral_constant<
    bool,
    has_fixed_size<zed_interfaces::srv::StartSvoRec_Request>::value &&
    has_fixed_size<zed_interfaces::srv::StartSvoRec_Response>::value
  >
{
};

template<>
struct has_bounded_size<zed_interfaces::srv::StartSvoRec>
  : std::integral_constant<
    bool,
    has_bounded_size<zed_interfaces::srv::StartSvoRec_Request>::value &&
    has_bounded_size<zed_interfaces::srv::StartSvoRec_Response>::value
  >
{
};

template<>
struct is_service<zed_interfaces::srv::StartSvoRec>
  : std::true_type
{
};

template<>
struct is_service_request<zed_interfaces::srv::StartSvoRec_Request>
  : std::true_type
{
};

template<>
struct is_service_response<zed_interfaces::srv::StartSvoRec_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ZED_INTERFACES__SRV__DETAIL__START_SVO_REC__TRAITS_HPP_

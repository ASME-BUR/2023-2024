// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/heartbeat__rosidl_typesupport_fastrtps_cpp.hpp"
#include "zed_interfaces/msg/detail/heartbeat__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace zed_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_interfaces
cdr_serialize(
  const zed_interfaces::msg::Heartbeat & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: beat_count
  cdr << ros_message.beat_count;
  // Member: node_ns
  cdr << ros_message.node_ns;
  // Member: node_name
  cdr << ros_message.node_name;
  // Member: full_name
  cdr << ros_message.full_name;
  // Member: camera_sn
  cdr << ros_message.camera_sn;
  // Member: svo_mode
  cdr << (ros_message.svo_mode ? true : false);
  // Member: simul_mode
  cdr << (ros_message.simul_mode ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  zed_interfaces::msg::Heartbeat & ros_message)
{
  // Member: beat_count
  cdr >> ros_message.beat_count;

  // Member: node_ns
  cdr >> ros_message.node_ns;

  // Member: node_name
  cdr >> ros_message.node_name;

  // Member: full_name
  cdr >> ros_message.full_name;

  // Member: camera_sn
  cdr >> ros_message.camera_sn;

  // Member: svo_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.svo_mode = tmp ? true : false;
  }

  // Member: simul_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.simul_mode = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::msg::Heartbeat & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: beat_count
  {
    size_t item_size = sizeof(ros_message.beat_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: node_ns
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.node_ns.size() + 1);
  // Member: node_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.node_name.size() + 1);
  // Member: full_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.full_name.size() + 1);
  // Member: camera_sn
  {
    size_t item_size = sizeof(ros_message.camera_sn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: svo_mode
  {
    size_t item_size = sizeof(ros_message.svo_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: simul_mode
  {
    size_t item_size = sizeof(ros_message.simul_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_interfaces
max_serialized_size_Heartbeat(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: beat_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: node_ns
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: node_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: full_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: camera_sn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: svo_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: simul_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = zed_interfaces::msg::Heartbeat;
    is_plain =
      (
      offsetof(DataType, simul_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Heartbeat__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Heartbeat__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Heartbeat__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Heartbeat__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Heartbeat(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Heartbeat__callbacks = {
  "zed_interfaces::msg",
  "Heartbeat",
  _Heartbeat__cdr_serialize,
  _Heartbeat__cdr_deserialize,
  _Heartbeat__get_serialized_size,
  _Heartbeat__max_serialized_size
};

static rosidl_message_type_support_t _Heartbeat__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Heartbeat__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace zed_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<zed_interfaces::msg::Heartbeat>()
{
  return &zed_interfaces::msg::typesupport_fastrtps_cpp::_Heartbeat__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zed_interfaces, msg, Heartbeat)() {
  return &zed_interfaces::msg::typesupport_fastrtps_cpp::_Heartbeat__handle;
}

#ifdef __cplusplus
}
#endif

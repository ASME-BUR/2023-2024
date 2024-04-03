// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/heartbeat__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "zed_interfaces/msg/detail/heartbeat__struct.h"
#include "zed_interfaces/msg/detail/heartbeat__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // full_name, node_name, node_ns
#include "rosidl_runtime_c/string_functions.h"  // full_name, node_name, node_ns

// forward declare type support functions


using _Heartbeat__ros_msg_type = zed_interfaces__msg__Heartbeat;

static bool _Heartbeat__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Heartbeat__ros_msg_type * ros_message = static_cast<const _Heartbeat__ros_msg_type *>(untyped_ros_message);
  // Field name: beat_count
  {
    cdr << ros_message->beat_count;
  }

  // Field name: node_ns
  {
    const rosidl_runtime_c__String * str = &ros_message->node_ns;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: node_name
  {
    const rosidl_runtime_c__String * str = &ros_message->node_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: full_name
  {
    const rosidl_runtime_c__String * str = &ros_message->full_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: camera_sn
  {
    cdr << ros_message->camera_sn;
  }

  // Field name: svo_mode
  {
    cdr << (ros_message->svo_mode ? true : false);
  }

  // Field name: simul_mode
  {
    cdr << (ros_message->simul_mode ? true : false);
  }

  return true;
}

static bool _Heartbeat__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Heartbeat__ros_msg_type * ros_message = static_cast<_Heartbeat__ros_msg_type *>(untyped_ros_message);
  // Field name: beat_count
  {
    cdr >> ros_message->beat_count;
  }

  // Field name: node_ns
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->node_ns.data) {
      rosidl_runtime_c__String__init(&ros_message->node_ns);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->node_ns,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'node_ns'\n");
      return false;
    }
  }

  // Field name: node_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->node_name.data) {
      rosidl_runtime_c__String__init(&ros_message->node_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->node_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'node_name'\n");
      return false;
    }
  }

  // Field name: full_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->full_name.data) {
      rosidl_runtime_c__String__init(&ros_message->full_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->full_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'full_name'\n");
      return false;
    }
  }

  // Field name: camera_sn
  {
    cdr >> ros_message->camera_sn;
  }

  // Field name: svo_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->svo_mode = tmp ? true : false;
  }

  // Field name: simul_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->simul_mode = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__Heartbeat(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Heartbeat__ros_msg_type * ros_message = static_cast<const _Heartbeat__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name beat_count
  {
    size_t item_size = sizeof(ros_message->beat_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name node_ns
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->node_ns.size + 1);
  // field.name node_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->node_name.size + 1);
  // field.name full_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->full_name.size + 1);
  // field.name camera_sn
  {
    size_t item_size = sizeof(ros_message->camera_sn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name svo_mode
  {
    size_t item_size = sizeof(ros_message->svo_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name simul_mode
  {
    size_t item_size = sizeof(ros_message->simul_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Heartbeat__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_zed_interfaces__msg__Heartbeat(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__Heartbeat(
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

  // member: beat_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: node_ns
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
  // member: node_name
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
  // member: full_name
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
  // member: camera_sn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: svo_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: simul_mode
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
    using DataType = zed_interfaces__msg__Heartbeat;
    is_plain =
      (
      offsetof(DataType, simul_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Heartbeat__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_zed_interfaces__msg__Heartbeat(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Heartbeat = {
  "zed_interfaces::msg",
  "Heartbeat",
  _Heartbeat__cdr_serialize,
  _Heartbeat__cdr_deserialize,
  _Heartbeat__get_serialized_size,
  _Heartbeat__max_serialized_size
};

static rosidl_message_type_support_t _Heartbeat__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Heartbeat,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_interfaces, msg, Heartbeat)() {
  return &_Heartbeat__type_support;
}

#if defined(__cplusplus)
}
#endif

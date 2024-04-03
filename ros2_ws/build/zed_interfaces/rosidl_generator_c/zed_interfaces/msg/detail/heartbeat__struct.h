// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__STRUCT_H_
#define ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'node_ns'
// Member 'node_name'
// Member 'full_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Heartbeat in the package zed_interfaces.
/**
  * Message to notify that the node is alive to other nodes
 */
typedef struct zed_interfaces__msg__Heartbeat
{
  /// idx of the message
  uint64_t beat_count;
  /// namespace of the node
  rosidl_runtime_c__String node_ns;
  /// name of the node
  rosidl_runtime_c__String node_name;
  /// full node name
  rosidl_runtime_c__String full_name;
  /// serial number of the input camera
  uint32_t camera_sn;
  /// data from an svo?
  bool svo_mode;
  /// data from simulation?
  bool simul_mode;
} zed_interfaces__msg__Heartbeat;

// Struct for a sequence of zed_interfaces__msg__Heartbeat.
typedef struct zed_interfaces__msg__Heartbeat__Sequence
{
  zed_interfaces__msg__Heartbeat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_interfaces__msg__Heartbeat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZED_INTERFACES__MSG__DETAIL__HEARTBEAT__STRUCT_H_

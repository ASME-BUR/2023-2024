// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zed_interfaces:msg/PosTrackStatus.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__POS_TRACK_STATUS__STRUCT_H_
#define ZED_INTERFACES__MSG__DETAIL__POS_TRACK_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SEARCHING'.
enum
{
  zed_interfaces__msg__PosTrackStatus__SEARCHING = 0
};

/// Constant 'OK'.
enum
{
  zed_interfaces__msg__PosTrackStatus__OK = 1
};

/// Constant 'OFF'.
enum
{
  zed_interfaces__msg__PosTrackStatus__OFF = 2
};

/// Constant 'FPS_TOO_LOW'.
enum
{
  zed_interfaces__msg__PosTrackStatus__FPS_TOO_LOW = 3
};

/// Constant 'SEARCHING_FLOOR_PLANE'.
enum
{
  zed_interfaces__msg__PosTrackStatus__SEARCHING_FLOOR_PLANE = 3
};

/// Struct defined in msg/PosTrackStatus in the package zed_interfaces.
/**
  * Status constants
  * SEARCHING - The camera is searching for a previously known position to locate itself
  * OK - Positional tracking is working normally
  * OFF - Positional tracking is not enabled.
  * FPS_TOO_LOW - Effective FPS is too low to give proper results for motion tracking. Consider using PERFORMANCES parameters (DEPTH_MODE_PERFORMANCE, low camera resolution (VGA,HD720))
  * SEARCHING_FLOOR_PLANE - The camera is searching for the floor plane to locate itself related to it, the REFERENCE_FRAME::WORLD will be set afterward.
 */
typedef struct zed_interfaces__msg__PosTrackStatus
{
  /// Status
  uint8_t status;
} zed_interfaces__msg__PosTrackStatus;

// Struct for a sequence of zed_interfaces__msg__PosTrackStatus.
typedef struct zed_interfaces__msg__PosTrackStatus__Sequence
{
  zed_interfaces__msg__PosTrackStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_interfaces__msg__PosTrackStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZED_INTERFACES__MSG__DETAIL__POS_TRACK_STATUS__STRUCT_H_

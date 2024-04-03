// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zed_interfaces:msg/PlaneStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_INTERFACES__MSG__DETAIL__PLANE_STAMPED__STRUCT_H_
#define ZED_INTERFACES__MSG__DETAIL__PLANE_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'mesh'
#include "shape_msgs/msg/detail/mesh__struct.h"
// Member 'coefficients'
#include "shape_msgs/msg/detail/plane__struct.h"
// Member 'normal'
// Member 'center'
#include "geometry_msgs/msg/detail/point32__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/transform__struct.h"
// Member 'bounds'
#include "geometry_msgs/msg/detail/polygon__struct.h"

/// Struct defined in msg/PlaneStamped in the package zed_interfaces.
/**
  * Standard Header
 */
typedef struct zed_interfaces__msg__PlaneStamped
{
  std_msgs__msg__Header header;
  /// Mesh of the place
  shape_msgs__msg__Mesh mesh;
  /// Representation of a plane, using the plane equation ax + by + cz + d = 0
  shape_msgs__msg__Plane coefficients;
  /// Normal vector
  geometry_msgs__msg__Point32 normal;
  /// Center point
  geometry_msgs__msg__Point32 center;
  /// Plane pose relative to the global reference frame
  geometry_msgs__msg__Transform pose;
  /// Width and height of the bounding rectangle around the plane contours
  float extents[2];
  /// The polygon bounds of the plane
  geometry_msgs__msg__Polygon bounds;
} zed_interfaces__msg__PlaneStamped;

// Struct for a sequence of zed_interfaces__msg__PlaneStamped.
typedef struct zed_interfaces__msg__PlaneStamped__Sequence
{
  zed_interfaces__msg__PlaneStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_interfaces__msg__PlaneStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZED_INTERFACES__MSG__DETAIL__PLANE_STAMPED__STRUCT_H_

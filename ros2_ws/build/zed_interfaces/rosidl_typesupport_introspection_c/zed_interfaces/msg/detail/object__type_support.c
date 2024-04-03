// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_interfaces:msg/Object.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_interfaces/msg/detail/object__rosidl_typesupport_introspection_c.h"
#include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_interfaces/msg/detail/object__functions.h"
#include "zed_interfaces/msg/detail/object__struct.h"


// Include directives for member types
// Member `label`
// Member `sublabel`
#include "rosidl_runtime_c/string_functions.h"
// Member `bounding_box_2d`
#include "zed_interfaces/msg/bounding_box2_di.h"
// Member `bounding_box_2d`
#include "zed_interfaces/msg/detail/bounding_box2_di__rosidl_typesupport_introspection_c.h"
// Member `bounding_box_3d`
// Member `head_bounding_box_3d`
#include "zed_interfaces/msg/bounding_box3_d.h"
// Member `bounding_box_3d`
// Member `head_bounding_box_3d`
#include "zed_interfaces/msg/detail/bounding_box3_d__rosidl_typesupport_introspection_c.h"
// Member `head_bounding_box_2d`
#include "zed_interfaces/msg/bounding_box2_df.h"
// Member `head_bounding_box_2d`
#include "zed_interfaces/msg/detail/bounding_box2_df__rosidl_typesupport_introspection_c.h"
// Member `skeleton_2d`
#include "zed_interfaces/msg/skeleton2_d.h"
// Member `skeleton_2d`
#include "zed_interfaces/msg/detail/skeleton2_d__rosidl_typesupport_introspection_c.h"
// Member `skeleton_3d`
#include "zed_interfaces/msg/skeleton3_d.h"
// Member `skeleton_3d`
#include "zed_interfaces/msg/detail/skeleton3_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_interfaces__msg__Object__init(message_memory);
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_fini_function(void * message_memory)
{
  zed_interfaces__msg__Object__fini(message_memory);
}

size_t zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__position(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__position(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__position_covariance(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__position_covariance(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__position_covariance(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__position_covariance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__position_covariance(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__position_covariance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__position_covariance(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__velocity(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__velocity(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__dimensions_3d(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__dimensions_3d(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__dimensions_3d(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__dimensions_3d(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__dimensions_3d(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__dimensions_3d(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__dimensions_3d(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__head_position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__head_position(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__head_position(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__head_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__head_position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__head_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__head_position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[20] = {
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "label_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, label_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sublabel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, sublabel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, position),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__position,  // size() function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__position,  // get_const(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__position,  // get(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__position,  // fetch(index, &value) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_covariance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, position_covariance),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__position_covariance,  // size() function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__position_covariance,  // get_const(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__position_covariance,  // get(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__position_covariance,  // fetch(index, &value) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__position_covariance,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, velocity),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__velocity,  // size() function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__velocity,  // get_const(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__velocity,  // get(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__velocity,  // fetch(index, &value) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracking_available",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, tracking_available),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracking_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, tracking_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "action_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, action_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_box_2d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, bounding_box_2d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_box_3d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, bounding_box_3d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dimensions_3d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, dimensions_3d),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__dimensions_3d,  // size() function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__dimensions_3d,  // get_const(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__dimensions_3d,  // get(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__dimensions_3d,  // fetch(index, &value) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__dimensions_3d,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "skeleton_available",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, skeleton_available),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "body_format",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, body_format),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head_bounding_box_2d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, head_bounding_box_2d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head_bounding_box_3d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, head_bounding_box_3d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "head_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, head_position),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__size_function__Object__head_position,  // size() function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_const_function__Object__head_position,  // get_const(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__get_function__Object__head_position,  // get(index) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__fetch_function__Object__head_position,  // fetch(index, &value) function pointer
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__assign_function__Object__head_position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "skeleton_2d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, skeleton_2d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "skeleton_3d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Object, skeleton_3d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_members = {
  "zed_interfaces__msg",  // message namespace
  "Object",  // message name
  20,  // number of fields
  sizeof(zed_interfaces__msg__Object),
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array,  // message members
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle = {
  0,
  &zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, Object)() {
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, BoundingBox2Di)();
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, BoundingBox3D)();
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[15].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, BoundingBox2Df)();
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[16].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, BoundingBox3D)();
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[18].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, Skeleton2D)();
  zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_member_array[19].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, Skeleton3D)();
  if (!zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle.typesupport_identifier) {
    zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_interfaces__msg__Object__rosidl_typesupport_introspection_c__Object_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

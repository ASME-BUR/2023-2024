// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_interfaces:msg/PlaneStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_interfaces/msg/detail/plane_stamped__rosidl_typesupport_introspection_c.h"
#include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_interfaces/msg/detail/plane_stamped__functions.h"
#include "zed_interfaces/msg/detail/plane_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `mesh`
#include "shape_msgs/msg/mesh.h"
// Member `mesh`
#include "shape_msgs/msg/detail/mesh__rosidl_typesupport_introspection_c.h"
// Member `coefficients`
#include "shape_msgs/msg/plane.h"
// Member `coefficients`
#include "shape_msgs/msg/detail/plane__rosidl_typesupport_introspection_c.h"
// Member `normal`
// Member `center`
#include "geometry_msgs/msg/point32.h"
// Member `normal`
// Member `center`
#include "geometry_msgs/msg/detail/point32__rosidl_typesupport_introspection_c.h"
// Member `pose`
#include "geometry_msgs/msg/transform.h"
// Member `pose`
#include "geometry_msgs/msg/detail/transform__rosidl_typesupport_introspection_c.h"
// Member `bounds`
#include "geometry_msgs/msg/polygon.h"
// Member `bounds`
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_interfaces__msg__PlaneStamped__init(message_memory);
}

void zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_fini_function(void * message_memory)
{
  zed_interfaces__msg__PlaneStamped__fini(message_memory);
}

size_t zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__size_function__PlaneStamped__extents(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__get_const_function__PlaneStamped__extents(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__get_function__PlaneStamped__extents(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__fetch_function__PlaneStamped__extents(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__get_const_function__PlaneStamped__extents(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__assign_function__PlaneStamped__extents(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__get_function__PlaneStamped__extents(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mesh",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, mesh),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coefficients",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, coefficients),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "normal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, normal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "extents",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, extents),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__size_function__PlaneStamped__extents,  // size() function pointer
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__get_const_function__PlaneStamped__extents,  // get_const(index) function pointer
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__get_function__PlaneStamped__extents,  // get(index) function pointer
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__fetch_function__PlaneStamped__extents,  // fetch(index, &value) function pointer
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__assign_function__PlaneStamped__extents,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__PlaneStamped, bounds),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_members = {
  "zed_interfaces__msg",  // message namespace
  "PlaneStamped",  // message name
  8,  // number of fields
  sizeof(zed_interfaces__msg__PlaneStamped),
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array,  // message members
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_type_support_handle = {
  0,
  &zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, PlaneStamped)() {
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shape_msgs, msg, Mesh)();
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shape_msgs, msg, Plane)();
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Transform)();
  zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  if (!zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_type_support_handle.typesupport_identifier) {
    zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_interfaces__msg__PlaneStamped__rosidl_typesupport_introspection_c__PlaneStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

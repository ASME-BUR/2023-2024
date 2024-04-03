// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_interfaces:msg/Skeleton2D.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_interfaces/msg/detail/skeleton2_d__rosidl_typesupport_introspection_c.h"
#include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_interfaces/msg/detail/skeleton2_d__functions.h"
#include "zed_interfaces/msg/detail/skeleton2_d__struct.h"


// Include directives for member types
// Member `keypoints`
#include "zed_interfaces/msg/keypoint2_df.h"
// Member `keypoints`
#include "zed_interfaces/msg/detail/keypoint2_df__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_interfaces__msg__Skeleton2D__init(message_memory);
}

void zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_fini_function(void * message_memory)
{
  zed_interfaces__msg__Skeleton2D__fini(message_memory);
}

size_t zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__size_function__Skeleton2D__keypoints(
  const void * untyped_member)
{
  (void)untyped_member;
  return 70;
}

const void * zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__get_const_function__Skeleton2D__keypoints(
  const void * untyped_member, size_t index)
{
  const zed_interfaces__msg__Keypoint2Df * member =
    (const zed_interfaces__msg__Keypoint2Df *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__get_function__Skeleton2D__keypoints(
  void * untyped_member, size_t index)
{
  zed_interfaces__msg__Keypoint2Df * member =
    (zed_interfaces__msg__Keypoint2Df *)(untyped_member);
  return &member[index];
}

void zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__fetch_function__Skeleton2D__keypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const zed_interfaces__msg__Keypoint2Df * item =
    ((const zed_interfaces__msg__Keypoint2Df *)
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__get_const_function__Skeleton2D__keypoints(untyped_member, index));
  zed_interfaces__msg__Keypoint2Df * value =
    (zed_interfaces__msg__Keypoint2Df *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__assign_function__Skeleton2D__keypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  zed_interfaces__msg__Keypoint2Df * item =
    ((zed_interfaces__msg__Keypoint2Df *)
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__get_function__Skeleton2D__keypoints(untyped_member, index));
  const zed_interfaces__msg__Keypoint2Df * value =
    (const zed_interfaces__msg__Keypoint2Df *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_member_array[1] = {
  {
    "keypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    70,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__Skeleton2D, keypoints),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__size_function__Skeleton2D__keypoints,  // size() function pointer
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__get_const_function__Skeleton2D__keypoints,  // get_const(index) function pointer
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__get_function__Skeleton2D__keypoints,  // get(index) function pointer
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__fetch_function__Skeleton2D__keypoints,  // fetch(index, &value) function pointer
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__assign_function__Skeleton2D__keypoints,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_members = {
  "zed_interfaces__msg",  // message namespace
  "Skeleton2D",  // message name
  1,  // number of fields
  sizeof(zed_interfaces__msg__Skeleton2D),
  zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_member_array,  // message members
  zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_type_support_handle = {
  0,
  &zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, Skeleton2D)() {
  zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, Keypoint2Df)();
  if (!zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_type_support_handle.typesupport_identifier) {
    zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_interfaces__msg__Skeleton2D__rosidl_typesupport_introspection_c__Skeleton2D_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

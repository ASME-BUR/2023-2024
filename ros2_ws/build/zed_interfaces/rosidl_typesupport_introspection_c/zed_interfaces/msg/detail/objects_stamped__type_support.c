// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_interfaces:msg/ObjectsStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_interfaces/msg/detail/objects_stamped__rosidl_typesupport_introspection_c.h"
#include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_interfaces/msg/detail/objects_stamped__functions.h"
#include "zed_interfaces/msg/detail/objects_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `objects`
#include "zed_interfaces/msg/object.h"
// Member `objects`
#include "zed_interfaces/msg/detail/object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_interfaces__msg__ObjectsStamped__init(message_memory);
}

void zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_fini_function(void * message_memory)
{
  zed_interfaces__msg__ObjectsStamped__fini(message_memory);
}

size_t zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__size_function__ObjectsStamped__objects(
  const void * untyped_member)
{
  const zed_interfaces__msg__Object__Sequence * member =
    (const zed_interfaces__msg__Object__Sequence *)(untyped_member);
  return member->size;
}

const void * zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__get_const_function__ObjectsStamped__objects(
  const void * untyped_member, size_t index)
{
  const zed_interfaces__msg__Object__Sequence * member =
    (const zed_interfaces__msg__Object__Sequence *)(untyped_member);
  return &member->data[index];
}

void * zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__get_function__ObjectsStamped__objects(
  void * untyped_member, size_t index)
{
  zed_interfaces__msg__Object__Sequence * member =
    (zed_interfaces__msg__Object__Sequence *)(untyped_member);
  return &member->data[index];
}

void zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__fetch_function__ObjectsStamped__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const zed_interfaces__msg__Object * item =
    ((const zed_interfaces__msg__Object *)
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__get_const_function__ObjectsStamped__objects(untyped_member, index));
  zed_interfaces__msg__Object * value =
    (zed_interfaces__msg__Object *)(untyped_value);
  *value = *item;
}

void zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__assign_function__ObjectsStamped__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  zed_interfaces__msg__Object * item =
    ((zed_interfaces__msg__Object *)
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__get_function__ObjectsStamped__objects(untyped_member, index));
  const zed_interfaces__msg__Object * value =
    (const zed_interfaces__msg__Object *)(untyped_value);
  *item = *value;
}

bool zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__resize_function__ObjectsStamped__objects(
  void * untyped_member, size_t size)
{
  zed_interfaces__msg__Object__Sequence * member =
    (zed_interfaces__msg__Object__Sequence *)(untyped_member);
  zed_interfaces__msg__Object__Sequence__fini(member);
  return zed_interfaces__msg__Object__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__ObjectsStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__msg__ObjectsStamped, objects),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__size_function__ObjectsStamped__objects,  // size() function pointer
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__get_const_function__ObjectsStamped__objects,  // get_const(index) function pointer
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__get_function__ObjectsStamped__objects,  // get(index) function pointer
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__fetch_function__ObjectsStamped__objects,  // fetch(index, &value) function pointer
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__assign_function__ObjectsStamped__objects,  // assign(index, value) function pointer
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__resize_function__ObjectsStamped__objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_members = {
  "zed_interfaces__msg",  // message namespace
  "ObjectsStamped",  // message name
  2,  // number of fields
  sizeof(zed_interfaces__msg__ObjectsStamped),
  zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_member_array,  // message members
  zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_type_support_handle = {
  0,
  &zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, ObjectsStamped)() {
  zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, msg, Object)();
  if (!zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_type_support_handle.typesupport_identifier) {
    zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_interfaces__msg__ObjectsStamped__rosidl_typesupport_introspection_c__ObjectsStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

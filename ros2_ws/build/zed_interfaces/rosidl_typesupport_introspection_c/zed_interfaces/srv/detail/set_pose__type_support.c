// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_interfaces:srv/SetPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_interfaces/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
#include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_interfaces/srv/detail/set_pose__functions.h"
#include "zed_interfaces/srv/detail/set_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_interfaces__srv__SetPose_Request__init(message_memory);
}

void zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_fini_function(void * message_memory)
{
  zed_interfaces__srv__SetPose_Request__fini(message_memory);
}

size_t zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__pos(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__pos(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__pos(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__pos(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__orient(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__orient(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__orient(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__orient(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__orient(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__orient(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__orient(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_member_array[2] = {
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__srv__SetPose_Request, pos),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__pos,  // size() function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__pos,  // get_const(index) function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__pos,  // get(index) function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__pos,  // fetch(index, &value) function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orient",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__srv__SetPose_Request, orient),  // bytes offset in struct
    NULL,  // default value
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__size_function__SetPose_Request__orient,  // size() function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_const_function__SetPose_Request__orient,  // get_const(index) function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__get_function__SetPose_Request__orient,  // get(index) function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__fetch_function__SetPose_Request__orient,  // fetch(index, &value) function pointer
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__assign_function__SetPose_Request__orient,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_members = {
  "zed_interfaces__srv",  // message namespace
  "SetPose_Request",  // message name
  2,  // number of fields
  sizeof(zed_interfaces__srv__SetPose_Request),
  zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_member_array,  // message members
  zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle = {
  0,
  &zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose_Request)() {
  if (!zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle.typesupport_identifier) {
    zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_interfaces__srv__SetPose_Request__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "zed_interfaces/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "zed_interfaces/srv/detail/set_pose__functions.h"
// already included above
// #include "zed_interfaces/srv/detail/set_pose__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_interfaces__srv__SetPose_Response__init(message_memory);
}

void zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_fini_function(void * message_memory)
{
  zed_interfaces__srv__SetPose_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__srv__SetPose_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_interfaces__srv__SetPose_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_members = {
  "zed_interfaces__srv",  // message namespace
  "SetPose_Response",  // message name
  2,  // number of fields
  sizeof(zed_interfaces__srv__SetPose_Response),
  zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_member_array,  // message members
  zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle = {
  0,
  &zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose_Response)() {
  if (!zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle.typesupport_identifier) {
    zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_interfaces__srv__SetPose_Response__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "zed_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "zed_interfaces/srv/detail/set_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_members = {
  "zed_interfaces__srv",  // service namespace
  "SetPose",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_Request_message_type_support_handle,
  NULL  // response message
  // zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_Response_message_type_support_handle
};

static rosidl_service_type_support_t zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle = {
  0,
  &zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose)() {
  if (!zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle.typesupport_identifier) {
    zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_interfaces, srv, SetPose_Response)()->data;
  }

  return &zed_interfaces__srv__detail__set_pose__rosidl_typesupport_introspection_c__SetPose_service_type_support_handle;
}

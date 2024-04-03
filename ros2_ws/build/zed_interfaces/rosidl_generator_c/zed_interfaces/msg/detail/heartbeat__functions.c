// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/heartbeat__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `node_ns`
// Member `node_name`
// Member `full_name`
#include "rosidl_runtime_c/string_functions.h"

bool
zed_interfaces__msg__Heartbeat__init(zed_interfaces__msg__Heartbeat * msg)
{
  if (!msg) {
    return false;
  }
  // beat_count
  // node_ns
  if (!rosidl_runtime_c__String__init(&msg->node_ns)) {
    zed_interfaces__msg__Heartbeat__fini(msg);
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__init(&msg->node_name)) {
    zed_interfaces__msg__Heartbeat__fini(msg);
    return false;
  }
  // full_name
  if (!rosidl_runtime_c__String__init(&msg->full_name)) {
    zed_interfaces__msg__Heartbeat__fini(msg);
    return false;
  }
  // camera_sn
  // svo_mode
  // simul_mode
  return true;
}

void
zed_interfaces__msg__Heartbeat__fini(zed_interfaces__msg__Heartbeat * msg)
{
  if (!msg) {
    return;
  }
  // beat_count
  // node_ns
  rosidl_runtime_c__String__fini(&msg->node_ns);
  // node_name
  rosidl_runtime_c__String__fini(&msg->node_name);
  // full_name
  rosidl_runtime_c__String__fini(&msg->full_name);
  // camera_sn
  // svo_mode
  // simul_mode
}

bool
zed_interfaces__msg__Heartbeat__are_equal(const zed_interfaces__msg__Heartbeat * lhs, const zed_interfaces__msg__Heartbeat * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // beat_count
  if (lhs->beat_count != rhs->beat_count) {
    return false;
  }
  // node_ns
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_ns), &(rhs->node_ns)))
  {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_name), &(rhs->node_name)))
  {
    return false;
  }
  // full_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->full_name), &(rhs->full_name)))
  {
    return false;
  }
  // camera_sn
  if (lhs->camera_sn != rhs->camera_sn) {
    return false;
  }
  // svo_mode
  if (lhs->svo_mode != rhs->svo_mode) {
    return false;
  }
  // simul_mode
  if (lhs->simul_mode != rhs->simul_mode) {
    return false;
  }
  return true;
}

bool
zed_interfaces__msg__Heartbeat__copy(
  const zed_interfaces__msg__Heartbeat * input,
  zed_interfaces__msg__Heartbeat * output)
{
  if (!input || !output) {
    return false;
  }
  // beat_count
  output->beat_count = input->beat_count;
  // node_ns
  if (!rosidl_runtime_c__String__copy(
      &(input->node_ns), &(output->node_ns)))
  {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__copy(
      &(input->node_name), &(output->node_name)))
  {
    return false;
  }
  // full_name
  if (!rosidl_runtime_c__String__copy(
      &(input->full_name), &(output->full_name)))
  {
    return false;
  }
  // camera_sn
  output->camera_sn = input->camera_sn;
  // svo_mode
  output->svo_mode = input->svo_mode;
  // simul_mode
  output->simul_mode = input->simul_mode;
  return true;
}

zed_interfaces__msg__Heartbeat *
zed_interfaces__msg__Heartbeat__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_interfaces__msg__Heartbeat * msg = (zed_interfaces__msg__Heartbeat *)allocator.allocate(sizeof(zed_interfaces__msg__Heartbeat), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zed_interfaces__msg__Heartbeat));
  bool success = zed_interfaces__msg__Heartbeat__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zed_interfaces__msg__Heartbeat__destroy(zed_interfaces__msg__Heartbeat * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zed_interfaces__msg__Heartbeat__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zed_interfaces__msg__Heartbeat__Sequence__init(zed_interfaces__msg__Heartbeat__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_interfaces__msg__Heartbeat * data = NULL;

  if (size) {
    data = (zed_interfaces__msg__Heartbeat *)allocator.zero_allocate(size, sizeof(zed_interfaces__msg__Heartbeat), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zed_interfaces__msg__Heartbeat__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zed_interfaces__msg__Heartbeat__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
zed_interfaces__msg__Heartbeat__Sequence__fini(zed_interfaces__msg__Heartbeat__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      zed_interfaces__msg__Heartbeat__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

zed_interfaces__msg__Heartbeat__Sequence *
zed_interfaces__msg__Heartbeat__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_interfaces__msg__Heartbeat__Sequence * array = (zed_interfaces__msg__Heartbeat__Sequence *)allocator.allocate(sizeof(zed_interfaces__msg__Heartbeat__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zed_interfaces__msg__Heartbeat__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zed_interfaces__msg__Heartbeat__Sequence__destroy(zed_interfaces__msg__Heartbeat__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zed_interfaces__msg__Heartbeat__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zed_interfaces__msg__Heartbeat__Sequence__are_equal(const zed_interfaces__msg__Heartbeat__Sequence * lhs, const zed_interfaces__msg__Heartbeat__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zed_interfaces__msg__Heartbeat__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zed_interfaces__msg__Heartbeat__Sequence__copy(
  const zed_interfaces__msg__Heartbeat__Sequence * input,
  zed_interfaces__msg__Heartbeat__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zed_interfaces__msg__Heartbeat);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zed_interfaces__msg__Heartbeat * data =
      (zed_interfaces__msg__Heartbeat *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zed_interfaces__msg__Heartbeat__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zed_interfaces__msg__Heartbeat__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zed_interfaces__msg__Heartbeat__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

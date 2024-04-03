// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zed_interfaces:msg/PosTrackStatus.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/pos_track_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
zed_interfaces__msg__PosTrackStatus__init(zed_interfaces__msg__PosTrackStatus * msg)
{
  if (!msg) {
    return false;
  }
  // status
  return true;
}

void
zed_interfaces__msg__PosTrackStatus__fini(zed_interfaces__msg__PosTrackStatus * msg)
{
  if (!msg) {
    return;
  }
  // status
}

bool
zed_interfaces__msg__PosTrackStatus__are_equal(const zed_interfaces__msg__PosTrackStatus * lhs, const zed_interfaces__msg__PosTrackStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
zed_interfaces__msg__PosTrackStatus__copy(
  const zed_interfaces__msg__PosTrackStatus * input,
  zed_interfaces__msg__PosTrackStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  return true;
}

zed_interfaces__msg__PosTrackStatus *
zed_interfaces__msg__PosTrackStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_interfaces__msg__PosTrackStatus * msg = (zed_interfaces__msg__PosTrackStatus *)allocator.allocate(sizeof(zed_interfaces__msg__PosTrackStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zed_interfaces__msg__PosTrackStatus));
  bool success = zed_interfaces__msg__PosTrackStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zed_interfaces__msg__PosTrackStatus__destroy(zed_interfaces__msg__PosTrackStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zed_interfaces__msg__PosTrackStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zed_interfaces__msg__PosTrackStatus__Sequence__init(zed_interfaces__msg__PosTrackStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_interfaces__msg__PosTrackStatus * data = NULL;

  if (size) {
    data = (zed_interfaces__msg__PosTrackStatus *)allocator.zero_allocate(size, sizeof(zed_interfaces__msg__PosTrackStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zed_interfaces__msg__PosTrackStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zed_interfaces__msg__PosTrackStatus__fini(&data[i - 1]);
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
zed_interfaces__msg__PosTrackStatus__Sequence__fini(zed_interfaces__msg__PosTrackStatus__Sequence * array)
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
      zed_interfaces__msg__PosTrackStatus__fini(&array->data[i]);
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

zed_interfaces__msg__PosTrackStatus__Sequence *
zed_interfaces__msg__PosTrackStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_interfaces__msg__PosTrackStatus__Sequence * array = (zed_interfaces__msg__PosTrackStatus__Sequence *)allocator.allocate(sizeof(zed_interfaces__msg__PosTrackStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zed_interfaces__msg__PosTrackStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zed_interfaces__msg__PosTrackStatus__Sequence__destroy(zed_interfaces__msg__PosTrackStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zed_interfaces__msg__PosTrackStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zed_interfaces__msg__PosTrackStatus__Sequence__are_equal(const zed_interfaces__msg__PosTrackStatus__Sequence * lhs, const zed_interfaces__msg__PosTrackStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zed_interfaces__msg__PosTrackStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zed_interfaces__msg__PosTrackStatus__Sequence__copy(
  const zed_interfaces__msg__PosTrackStatus__Sequence * input,
  zed_interfaces__msg__PosTrackStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zed_interfaces__msg__PosTrackStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zed_interfaces__msg__PosTrackStatus * data =
      (zed_interfaces__msg__PosTrackStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zed_interfaces__msg__PosTrackStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zed_interfaces__msg__PosTrackStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zed_interfaces__msg__PosTrackStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

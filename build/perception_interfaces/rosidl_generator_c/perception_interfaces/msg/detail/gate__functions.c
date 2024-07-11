// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/gate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `red_marker`
// Member `green_marker`
#include "perception_interfaces/msg/detail/prop__functions.h"
// Member `midpoint`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
perception_interfaces__msg__Gate__init(perception_interfaces__msg__Gate * msg)
{
  if (!msg) {
    return false;
  }
  // red_marker
  if (!perception_interfaces__msg__Prop__init(&msg->red_marker)) {
    perception_interfaces__msg__Gate__fini(msg);
    return false;
  }
  // green_marker
  if (!perception_interfaces__msg__Prop__init(&msg->green_marker)) {
    perception_interfaces__msg__Gate__fini(msg);
    return false;
  }
  // midpoint
  if (!geometry_msgs__msg__Point__init(&msg->midpoint)) {
    perception_interfaces__msg__Gate__fini(msg);
    return false;
  }
  return true;
}

void
perception_interfaces__msg__Gate__fini(perception_interfaces__msg__Gate * msg)
{
  if (!msg) {
    return;
  }
  // red_marker
  perception_interfaces__msg__Prop__fini(&msg->red_marker);
  // green_marker
  perception_interfaces__msg__Prop__fini(&msg->green_marker);
  // midpoint
  geometry_msgs__msg__Point__fini(&msg->midpoint);
}

bool
perception_interfaces__msg__Gate__are_equal(const perception_interfaces__msg__Gate * lhs, const perception_interfaces__msg__Gate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // red_marker
  if (!perception_interfaces__msg__Prop__are_equal(
      &(lhs->red_marker), &(rhs->red_marker)))
  {
    return false;
  }
  // green_marker
  if (!perception_interfaces__msg__Prop__are_equal(
      &(lhs->green_marker), &(rhs->green_marker)))
  {
    return false;
  }
  // midpoint
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->midpoint), &(rhs->midpoint)))
  {
    return false;
  }
  return true;
}

bool
perception_interfaces__msg__Gate__copy(
  const perception_interfaces__msg__Gate * input,
  perception_interfaces__msg__Gate * output)
{
  if (!input || !output) {
    return false;
  }
  // red_marker
  if (!perception_interfaces__msg__Prop__copy(
      &(input->red_marker), &(output->red_marker)))
  {
    return false;
  }
  // green_marker
  if (!perception_interfaces__msg__Prop__copy(
      &(input->green_marker), &(output->green_marker)))
  {
    return false;
  }
  // midpoint
  if (!geometry_msgs__msg__Point__copy(
      &(input->midpoint), &(output->midpoint)))
  {
    return false;
  }
  return true;
}

perception_interfaces__msg__Gate *
perception_interfaces__msg__Gate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__Gate * msg = (perception_interfaces__msg__Gate *)allocator.allocate(sizeof(perception_interfaces__msg__Gate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_interfaces__msg__Gate));
  bool success = perception_interfaces__msg__Gate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_interfaces__msg__Gate__destroy(perception_interfaces__msg__Gate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_interfaces__msg__Gate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_interfaces__msg__Gate__Sequence__init(perception_interfaces__msg__Gate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__Gate * data = NULL;

  if (size) {
    data = (perception_interfaces__msg__Gate *)allocator.zero_allocate(size, sizeof(perception_interfaces__msg__Gate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_interfaces__msg__Gate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_interfaces__msg__Gate__fini(&data[i - 1]);
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
perception_interfaces__msg__Gate__Sequence__fini(perception_interfaces__msg__Gate__Sequence * array)
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
      perception_interfaces__msg__Gate__fini(&array->data[i]);
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

perception_interfaces__msg__Gate__Sequence *
perception_interfaces__msg__Gate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__Gate__Sequence * array = (perception_interfaces__msg__Gate__Sequence *)allocator.allocate(sizeof(perception_interfaces__msg__Gate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_interfaces__msg__Gate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_interfaces__msg__Gate__Sequence__destroy(perception_interfaces__msg__Gate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_interfaces__msg__Gate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_interfaces__msg__Gate__Sequence__are_equal(const perception_interfaces__msg__Gate__Sequence * lhs, const perception_interfaces__msg__Gate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_interfaces__msg__Gate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_interfaces__msg__Gate__Sequence__copy(
  const perception_interfaces__msg__Gate__Sequence * input,
  perception_interfaces__msg__Gate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_interfaces__msg__Gate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_interfaces__msg__Gate * data =
      (perception_interfaces__msg__Gate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_interfaces__msg__Gate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_interfaces__msg__Gate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_interfaces__msg__Gate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice
#include "slg_msgs/msg/detail/segment__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `last_point_prior_segment`
// Member `first_point_next_segment`
// Member `points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
slg_msgs__msg__Segment__init(slg_msgs__msg__Segment * msg)
{
  if (!msg) {
    return false;
  }
  // id
  msg->id = 0ull;
  // label
  msg->label = 0ul;
  // angular_distance
  msg->angular_distance = 0.0l;
  // last_point_prior_segment
  if (!geometry_msgs__msg__Point__init(&msg->last_point_prior_segment)) {
    slg_msgs__msg__Segment__fini(msg);
    return false;
  }
  // first_point_next_segment
  if (!geometry_msgs__msg__Point__init(&msg->first_point_next_segment)) {
    slg_msgs__msg__Segment__fini(msg);
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->points, 0)) {
    slg_msgs__msg__Segment__fini(msg);
    return false;
  }
  return true;
}

void
slg_msgs__msg__Segment__fini(slg_msgs__msg__Segment * msg)
{
  if (!msg) {
    return;
  }
  // id
  // label
  // angular_distance
  // last_point_prior_segment
  geometry_msgs__msg__Point__fini(&msg->last_point_prior_segment);
  // first_point_next_segment
  geometry_msgs__msg__Point__fini(&msg->first_point_next_segment);
  // points
  geometry_msgs__msg__Point__Sequence__fini(&msg->points);
}

bool
slg_msgs__msg__Segment__are_equal(const slg_msgs__msg__Segment * lhs, const slg_msgs__msg__Segment * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // label
  if (lhs->label != rhs->label) {
    return false;
  }
  // angular_distance
  if (lhs->angular_distance != rhs->angular_distance) {
    return false;
  }
  // last_point_prior_segment
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->last_point_prior_segment), &(rhs->last_point_prior_segment)))
  {
    return false;
  }
  // first_point_next_segment
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->first_point_next_segment), &(rhs->first_point_next_segment)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
slg_msgs__msg__Segment__copy(
  const slg_msgs__msg__Segment * input,
  slg_msgs__msg__Segment * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // label
  output->label = input->label;
  // angular_distance
  output->angular_distance = input->angular_distance;
  // last_point_prior_segment
  if (!geometry_msgs__msg__Point__copy(
      &(input->last_point_prior_segment), &(output->last_point_prior_segment)))
  {
    return false;
  }
  // first_point_next_segment
  if (!geometry_msgs__msg__Point__copy(
      &(input->first_point_next_segment), &(output->first_point_next_segment)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

slg_msgs__msg__Segment *
slg_msgs__msg__Segment__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slg_msgs__msg__Segment * msg = (slg_msgs__msg__Segment *)allocator.allocate(sizeof(slg_msgs__msg__Segment), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slg_msgs__msg__Segment));
  bool success = slg_msgs__msg__Segment__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slg_msgs__msg__Segment__destroy(slg_msgs__msg__Segment * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slg_msgs__msg__Segment__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slg_msgs__msg__Segment__Sequence__init(slg_msgs__msg__Segment__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slg_msgs__msg__Segment * data = NULL;

  if (size) {
    data = (slg_msgs__msg__Segment *)allocator.zero_allocate(size, sizeof(slg_msgs__msg__Segment), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slg_msgs__msg__Segment__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slg_msgs__msg__Segment__fini(&data[i - 1]);
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
slg_msgs__msg__Segment__Sequence__fini(slg_msgs__msg__Segment__Sequence * array)
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
      slg_msgs__msg__Segment__fini(&array->data[i]);
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

slg_msgs__msg__Segment__Sequence *
slg_msgs__msg__Segment__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slg_msgs__msg__Segment__Sequence * array = (slg_msgs__msg__Segment__Sequence *)allocator.allocate(sizeof(slg_msgs__msg__Segment__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slg_msgs__msg__Segment__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slg_msgs__msg__Segment__Sequence__destroy(slg_msgs__msg__Segment__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slg_msgs__msg__Segment__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slg_msgs__msg__Segment__Sequence__are_equal(const slg_msgs__msg__Segment__Sequence * lhs, const slg_msgs__msg__Segment__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slg_msgs__msg__Segment__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slg_msgs__msg__Segment__Sequence__copy(
  const slg_msgs__msg__Segment__Sequence * input,
  slg_msgs__msg__Segment__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slg_msgs__msg__Segment);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slg_msgs__msg__Segment * data =
      (slg_msgs__msg__Segment *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slg_msgs__msg__Segment__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slg_msgs__msg__Segment__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slg_msgs__msg__Segment__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

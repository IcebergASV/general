// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_interfaces:msg/LidarDetectedProp.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/lidar_detected_prop__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `center`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
perception_interfaces__msg__LidarDetectedProp__init(perception_interfaces__msg__LidarDetectedProp * msg)
{
  if (!msg) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    perception_interfaces__msg__LidarDetectedProp__fini(msg);
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    perception_interfaces__msg__LidarDetectedProp__fini(msg);
    return false;
  }
  // radius
  // radius_diff
  return true;
}

void
perception_interfaces__msg__LidarDetectedProp__fini(perception_interfaces__msg__LidarDetectedProp * msg)
{
  if (!msg) {
    return;
  }
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // radius
  // radius_diff
}

bool
perception_interfaces__msg__LidarDetectedProp__are_equal(const perception_interfaces__msg__LidarDetectedProp * lhs, const perception_interfaces__msg__LidarDetectedProp * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center), &(rhs->center)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  // radius_diff
  if (lhs->radius_diff != rhs->radius_diff) {
    return false;
  }
  return true;
}

bool
perception_interfaces__msg__LidarDetectedProp__copy(
  const perception_interfaces__msg__LidarDetectedProp * input,
  perception_interfaces__msg__LidarDetectedProp * output)
{
  if (!input || !output) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__copy(
      &(input->center), &(output->center)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  // radius_diff
  output->radius_diff = input->radius_diff;
  return true;
}

perception_interfaces__msg__LidarDetectedProp *
perception_interfaces__msg__LidarDetectedProp__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__LidarDetectedProp * msg = (perception_interfaces__msg__LidarDetectedProp *)allocator.allocate(sizeof(perception_interfaces__msg__LidarDetectedProp), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_interfaces__msg__LidarDetectedProp));
  bool success = perception_interfaces__msg__LidarDetectedProp__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_interfaces__msg__LidarDetectedProp__destroy(perception_interfaces__msg__LidarDetectedProp * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_interfaces__msg__LidarDetectedProp__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_interfaces__msg__LidarDetectedProp__Sequence__init(perception_interfaces__msg__LidarDetectedProp__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__LidarDetectedProp * data = NULL;

  if (size) {
    data = (perception_interfaces__msg__LidarDetectedProp *)allocator.zero_allocate(size, sizeof(perception_interfaces__msg__LidarDetectedProp), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_interfaces__msg__LidarDetectedProp__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_interfaces__msg__LidarDetectedProp__fini(&data[i - 1]);
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
perception_interfaces__msg__LidarDetectedProp__Sequence__fini(perception_interfaces__msg__LidarDetectedProp__Sequence * array)
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
      perception_interfaces__msg__LidarDetectedProp__fini(&array->data[i]);
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

perception_interfaces__msg__LidarDetectedProp__Sequence *
perception_interfaces__msg__LidarDetectedProp__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__LidarDetectedProp__Sequence * array = (perception_interfaces__msg__LidarDetectedProp__Sequence *)allocator.allocate(sizeof(perception_interfaces__msg__LidarDetectedProp__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_interfaces__msg__LidarDetectedProp__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_interfaces__msg__LidarDetectedProp__Sequence__destroy(perception_interfaces__msg__LidarDetectedProp__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_interfaces__msg__LidarDetectedProp__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_interfaces__msg__LidarDetectedProp__Sequence__are_equal(const perception_interfaces__msg__LidarDetectedProp__Sequence * lhs, const perception_interfaces__msg__LidarDetectedProp__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_interfaces__msg__LidarDetectedProp__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_interfaces__msg__LidarDetectedProp__Sequence__copy(
  const perception_interfaces__msg__LidarDetectedProp__Sequence * input,
  perception_interfaces__msg__LidarDetectedProp__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_interfaces__msg__LidarDetectedProp);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_interfaces__msg__LidarDetectedProp * data =
      (perception_interfaces__msg__LidarDetectedProp *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_interfaces__msg__LidarDetectedProp__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_interfaces__msg__LidarDetectedProp__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_interfaces__msg__LidarDetectedProp__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

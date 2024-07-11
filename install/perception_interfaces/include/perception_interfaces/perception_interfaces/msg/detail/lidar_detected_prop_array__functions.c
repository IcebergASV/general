// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_interfaces:msg/LidarDetectedPropArray.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/lidar_detected_prop_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `lidar_detected_props`
#include "perception_interfaces/msg/detail/lidar_detected_prop__functions.h"

bool
perception_interfaces__msg__LidarDetectedPropArray__init(perception_interfaces__msg__LidarDetectedPropArray * msg)
{
  if (!msg) {
    return false;
  }
  // lidar_detected_props
  if (!perception_interfaces__msg__LidarDetectedProp__Sequence__init(&msg->lidar_detected_props, 0)) {
    perception_interfaces__msg__LidarDetectedPropArray__fini(msg);
    return false;
  }
  return true;
}

void
perception_interfaces__msg__LidarDetectedPropArray__fini(perception_interfaces__msg__LidarDetectedPropArray * msg)
{
  if (!msg) {
    return;
  }
  // lidar_detected_props
  perception_interfaces__msg__LidarDetectedProp__Sequence__fini(&msg->lidar_detected_props);
}

bool
perception_interfaces__msg__LidarDetectedPropArray__are_equal(const perception_interfaces__msg__LidarDetectedPropArray * lhs, const perception_interfaces__msg__LidarDetectedPropArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lidar_detected_props
  if (!perception_interfaces__msg__LidarDetectedProp__Sequence__are_equal(
      &(lhs->lidar_detected_props), &(rhs->lidar_detected_props)))
  {
    return false;
  }
  return true;
}

bool
perception_interfaces__msg__LidarDetectedPropArray__copy(
  const perception_interfaces__msg__LidarDetectedPropArray * input,
  perception_interfaces__msg__LidarDetectedPropArray * output)
{
  if (!input || !output) {
    return false;
  }
  // lidar_detected_props
  if (!perception_interfaces__msg__LidarDetectedProp__Sequence__copy(
      &(input->lidar_detected_props), &(output->lidar_detected_props)))
  {
    return false;
  }
  return true;
}

perception_interfaces__msg__LidarDetectedPropArray *
perception_interfaces__msg__LidarDetectedPropArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__LidarDetectedPropArray * msg = (perception_interfaces__msg__LidarDetectedPropArray *)allocator.allocate(sizeof(perception_interfaces__msg__LidarDetectedPropArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_interfaces__msg__LidarDetectedPropArray));
  bool success = perception_interfaces__msg__LidarDetectedPropArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_interfaces__msg__LidarDetectedPropArray__destroy(perception_interfaces__msg__LidarDetectedPropArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_interfaces__msg__LidarDetectedPropArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_interfaces__msg__LidarDetectedPropArray__Sequence__init(perception_interfaces__msg__LidarDetectedPropArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__LidarDetectedPropArray * data = NULL;

  if (size) {
    data = (perception_interfaces__msg__LidarDetectedPropArray *)allocator.zero_allocate(size, sizeof(perception_interfaces__msg__LidarDetectedPropArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_interfaces__msg__LidarDetectedPropArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_interfaces__msg__LidarDetectedPropArray__fini(&data[i - 1]);
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
perception_interfaces__msg__LidarDetectedPropArray__Sequence__fini(perception_interfaces__msg__LidarDetectedPropArray__Sequence * array)
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
      perception_interfaces__msg__LidarDetectedPropArray__fini(&array->data[i]);
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

perception_interfaces__msg__LidarDetectedPropArray__Sequence *
perception_interfaces__msg__LidarDetectedPropArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__LidarDetectedPropArray__Sequence * array = (perception_interfaces__msg__LidarDetectedPropArray__Sequence *)allocator.allocate(sizeof(perception_interfaces__msg__LidarDetectedPropArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_interfaces__msg__LidarDetectedPropArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_interfaces__msg__LidarDetectedPropArray__Sequence__destroy(perception_interfaces__msg__LidarDetectedPropArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_interfaces__msg__LidarDetectedPropArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_interfaces__msg__LidarDetectedPropArray__Sequence__are_equal(const perception_interfaces__msg__LidarDetectedPropArray__Sequence * lhs, const perception_interfaces__msg__LidarDetectedPropArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_interfaces__msg__LidarDetectedPropArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_interfaces__msg__LidarDetectedPropArray__Sequence__copy(
  const perception_interfaces__msg__LidarDetectedPropArray__Sequence * input,
  perception_interfaces__msg__LidarDetectedPropArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_interfaces__msg__LidarDetectedPropArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_interfaces__msg__LidarDetectedPropArray * data =
      (perception_interfaces__msg__LidarDetectedPropArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_interfaces__msg__LidarDetectedPropArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_interfaces__msg__LidarDetectedPropArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_interfaces__msg__LidarDetectedPropArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

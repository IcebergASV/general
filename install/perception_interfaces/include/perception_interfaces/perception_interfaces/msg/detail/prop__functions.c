// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_interfaces:msg/Prop.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/prop__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
perception_interfaces__msg__Prop__init(perception_interfaces__msg__Prop * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    perception_interfaces__msg__Prop__fini(msg);
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__init(&msg->point)) {
    perception_interfaces__msg__Prop__fini(msg);
    return false;
  }
  // radius
  // probability
  return true;
}

void
perception_interfaces__msg__Prop__fini(perception_interfaces__msg__Prop * msg)
{
  if (!msg) {
    return;
  }
  // id
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // point
  geometry_msgs__msg__Point__fini(&msg->point);
  // radius
  // probability
}

bool
perception_interfaces__msg__Prop__are_equal(const perception_interfaces__msg__Prop * lhs, const perception_interfaces__msg__Prop * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  // probability
  if (lhs->probability != rhs->probability) {
    return false;
  }
  return true;
}

bool
perception_interfaces__msg__Prop__copy(
  const perception_interfaces__msg__Prop * input,
  perception_interfaces__msg__Prop * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  // probability
  output->probability = input->probability;
  return true;
}

perception_interfaces__msg__Prop *
perception_interfaces__msg__Prop__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__Prop * msg = (perception_interfaces__msg__Prop *)allocator.allocate(sizeof(perception_interfaces__msg__Prop), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_interfaces__msg__Prop));
  bool success = perception_interfaces__msg__Prop__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_interfaces__msg__Prop__destroy(perception_interfaces__msg__Prop * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_interfaces__msg__Prop__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_interfaces__msg__Prop__Sequence__init(perception_interfaces__msg__Prop__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__Prop * data = NULL;

  if (size) {
    data = (perception_interfaces__msg__Prop *)allocator.zero_allocate(size, sizeof(perception_interfaces__msg__Prop), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_interfaces__msg__Prop__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_interfaces__msg__Prop__fini(&data[i - 1]);
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
perception_interfaces__msg__Prop__Sequence__fini(perception_interfaces__msg__Prop__Sequence * array)
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
      perception_interfaces__msg__Prop__fini(&array->data[i]);
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

perception_interfaces__msg__Prop__Sequence *
perception_interfaces__msg__Prop__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__Prop__Sequence * array = (perception_interfaces__msg__Prop__Sequence *)allocator.allocate(sizeof(perception_interfaces__msg__Prop__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_interfaces__msg__Prop__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_interfaces__msg__Prop__Sequence__destroy(perception_interfaces__msg__Prop__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_interfaces__msg__Prop__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_interfaces__msg__Prop__Sequence__are_equal(const perception_interfaces__msg__Prop__Sequence * lhs, const perception_interfaces__msg__Prop__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_interfaces__msg__Prop__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_interfaces__msg__Prop__Sequence__copy(
  const perception_interfaces__msg__Prop__Sequence * input,
  perception_interfaces__msg__Prop__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_interfaces__msg__Prop);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_interfaces__msg__Prop * data =
      (perception_interfaces__msg__Prop *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_interfaces__msg__Prop__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_interfaces__msg__Prop__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_interfaces__msg__Prop__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

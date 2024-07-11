// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_id`
#include "rosidl_runtime_c/string_functions.h"

bool
perception_interfaces__msg__BoundingBox__init(perception_interfaces__msg__BoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // xmin
  // ymin
  // xmax
  // ymax
  // id
  // probability
  // class_id
  if (!rosidl_runtime_c__String__init(&msg->class_id)) {
    perception_interfaces__msg__BoundingBox__fini(msg);
    return false;
  }
  return true;
}

void
perception_interfaces__msg__BoundingBox__fini(perception_interfaces__msg__BoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // xmin
  // ymin
  // xmax
  // ymax
  // id
  // probability
  // class_id
  rosidl_runtime_c__String__fini(&msg->class_id);
}

bool
perception_interfaces__msg__BoundingBox__are_equal(const perception_interfaces__msg__BoundingBox * lhs, const perception_interfaces__msg__BoundingBox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // xmin
  if (lhs->xmin != rhs->xmin) {
    return false;
  }
  // ymin
  if (lhs->ymin != rhs->ymin) {
    return false;
  }
  // xmax
  if (lhs->xmax != rhs->xmax) {
    return false;
  }
  // ymax
  if (lhs->ymax != rhs->ymax) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // probability
  if (lhs->probability != rhs->probability) {
    return false;
  }
  // class_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_id), &(rhs->class_id)))
  {
    return false;
  }
  return true;
}

bool
perception_interfaces__msg__BoundingBox__copy(
  const perception_interfaces__msg__BoundingBox * input,
  perception_interfaces__msg__BoundingBox * output)
{
  if (!input || !output) {
    return false;
  }
  // xmin
  output->xmin = input->xmin;
  // ymin
  output->ymin = input->ymin;
  // xmax
  output->xmax = input->xmax;
  // ymax
  output->ymax = input->ymax;
  // id
  output->id = input->id;
  // probability
  output->probability = input->probability;
  // class_id
  if (!rosidl_runtime_c__String__copy(
      &(input->class_id), &(output->class_id)))
  {
    return false;
  }
  return true;
}

perception_interfaces__msg__BoundingBox *
perception_interfaces__msg__BoundingBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__BoundingBox * msg = (perception_interfaces__msg__BoundingBox *)allocator.allocate(sizeof(perception_interfaces__msg__BoundingBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_interfaces__msg__BoundingBox));
  bool success = perception_interfaces__msg__BoundingBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_interfaces__msg__BoundingBox__destroy(perception_interfaces__msg__BoundingBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_interfaces__msg__BoundingBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_interfaces__msg__BoundingBox__Sequence__init(perception_interfaces__msg__BoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__BoundingBox * data = NULL;

  if (size) {
    data = (perception_interfaces__msg__BoundingBox *)allocator.zero_allocate(size, sizeof(perception_interfaces__msg__BoundingBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_interfaces__msg__BoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_interfaces__msg__BoundingBox__fini(&data[i - 1]);
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
perception_interfaces__msg__BoundingBox__Sequence__fini(perception_interfaces__msg__BoundingBox__Sequence * array)
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
      perception_interfaces__msg__BoundingBox__fini(&array->data[i]);
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

perception_interfaces__msg__BoundingBox__Sequence *
perception_interfaces__msg__BoundingBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_interfaces__msg__BoundingBox__Sequence * array = (perception_interfaces__msg__BoundingBox__Sequence *)allocator.allocate(sizeof(perception_interfaces__msg__BoundingBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_interfaces__msg__BoundingBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_interfaces__msg__BoundingBox__Sequence__destroy(perception_interfaces__msg__BoundingBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_interfaces__msg__BoundingBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_interfaces__msg__BoundingBox__Sequence__are_equal(const perception_interfaces__msg__BoundingBox__Sequence * lhs, const perception_interfaces__msg__BoundingBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_interfaces__msg__BoundingBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_interfaces__msg__BoundingBox__Sequence__copy(
  const perception_interfaces__msg__BoundingBox__Sequence * input,
  perception_interfaces__msg__BoundingBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_interfaces__msg__BoundingBox);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_interfaces__msg__BoundingBox * data =
      (perception_interfaces__msg__BoundingBox *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_interfaces__msg__BoundingBox__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_interfaces__msg__BoundingBox__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_interfaces__msg__BoundingBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

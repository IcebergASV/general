// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolov8_msgs:msg/KeyPoint2DArray.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/key_point2_d_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "yolov8_msgs/msg/detail/key_point2_d__functions.h"

bool
yolov8_msgs__msg__KeyPoint2DArray__init(yolov8_msgs__msg__KeyPoint2DArray * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!yolov8_msgs__msg__KeyPoint2D__Sequence__init(&msg->data, 0)) {
    yolov8_msgs__msg__KeyPoint2DArray__fini(msg);
    return false;
  }
  return true;
}

void
yolov8_msgs__msg__KeyPoint2DArray__fini(yolov8_msgs__msg__KeyPoint2DArray * msg)
{
  if (!msg) {
    return;
  }
  // data
  yolov8_msgs__msg__KeyPoint2D__Sequence__fini(&msg->data);
}

bool
yolov8_msgs__msg__KeyPoint2DArray__are_equal(const yolov8_msgs__msg__KeyPoint2DArray * lhs, const yolov8_msgs__msg__KeyPoint2DArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!yolov8_msgs__msg__KeyPoint2D__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
yolov8_msgs__msg__KeyPoint2DArray__copy(
  const yolov8_msgs__msg__KeyPoint2DArray * input,
  yolov8_msgs__msg__KeyPoint2DArray * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!yolov8_msgs__msg__KeyPoint2D__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

yolov8_msgs__msg__KeyPoint2DArray *
yolov8_msgs__msg__KeyPoint2DArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__KeyPoint2DArray * msg = (yolov8_msgs__msg__KeyPoint2DArray *)allocator.allocate(sizeof(yolov8_msgs__msg__KeyPoint2DArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolov8_msgs__msg__KeyPoint2DArray));
  bool success = yolov8_msgs__msg__KeyPoint2DArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolov8_msgs__msg__KeyPoint2DArray__destroy(yolov8_msgs__msg__KeyPoint2DArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolov8_msgs__msg__KeyPoint2DArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolov8_msgs__msg__KeyPoint2DArray__Sequence__init(yolov8_msgs__msg__KeyPoint2DArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__KeyPoint2DArray * data = NULL;

  if (size) {
    data = (yolov8_msgs__msg__KeyPoint2DArray *)allocator.zero_allocate(size, sizeof(yolov8_msgs__msg__KeyPoint2DArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolov8_msgs__msg__KeyPoint2DArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolov8_msgs__msg__KeyPoint2DArray__fini(&data[i - 1]);
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
yolov8_msgs__msg__KeyPoint2DArray__Sequence__fini(yolov8_msgs__msg__KeyPoint2DArray__Sequence * array)
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
      yolov8_msgs__msg__KeyPoint2DArray__fini(&array->data[i]);
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

yolov8_msgs__msg__KeyPoint2DArray__Sequence *
yolov8_msgs__msg__KeyPoint2DArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__KeyPoint2DArray__Sequence * array = (yolov8_msgs__msg__KeyPoint2DArray__Sequence *)allocator.allocate(sizeof(yolov8_msgs__msg__KeyPoint2DArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolov8_msgs__msg__KeyPoint2DArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolov8_msgs__msg__KeyPoint2DArray__Sequence__destroy(yolov8_msgs__msg__KeyPoint2DArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolov8_msgs__msg__KeyPoint2DArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolov8_msgs__msg__KeyPoint2DArray__Sequence__are_equal(const yolov8_msgs__msg__KeyPoint2DArray__Sequence * lhs, const yolov8_msgs__msg__KeyPoint2DArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolov8_msgs__msg__KeyPoint2DArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolov8_msgs__msg__KeyPoint2DArray__Sequence__copy(
  const yolov8_msgs__msg__KeyPoint2DArray__Sequence * input,
  yolov8_msgs__msg__KeyPoint2DArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolov8_msgs__msg__KeyPoint2DArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yolov8_msgs__msg__KeyPoint2DArray * data =
      (yolov8_msgs__msg__KeyPoint2DArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolov8_msgs__msg__KeyPoint2DArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yolov8_msgs__msg__KeyPoint2DArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolov8_msgs__msg__KeyPoint2DArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

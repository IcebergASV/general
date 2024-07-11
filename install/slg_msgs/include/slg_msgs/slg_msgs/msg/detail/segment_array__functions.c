// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice
#include "slg_msgs/msg/detail/segment_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `segments`
#include "slg_msgs/msg/detail/segment__functions.h"

bool
slg_msgs__msg__SegmentArray__init(slg_msgs__msg__SegmentArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    slg_msgs__msg__SegmentArray__fini(msg);
    return false;
  }
  // segments
  if (!slg_msgs__msg__Segment__Sequence__init(&msg->segments, 0)) {
    slg_msgs__msg__SegmentArray__fini(msg);
    return false;
  }
  return true;
}

void
slg_msgs__msg__SegmentArray__fini(slg_msgs__msg__SegmentArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // segments
  slg_msgs__msg__Segment__Sequence__fini(&msg->segments);
}

bool
slg_msgs__msg__SegmentArray__are_equal(const slg_msgs__msg__SegmentArray * lhs, const slg_msgs__msg__SegmentArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // segments
  if (!slg_msgs__msg__Segment__Sequence__are_equal(
      &(lhs->segments), &(rhs->segments)))
  {
    return false;
  }
  return true;
}

bool
slg_msgs__msg__SegmentArray__copy(
  const slg_msgs__msg__SegmentArray * input,
  slg_msgs__msg__SegmentArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // segments
  if (!slg_msgs__msg__Segment__Sequence__copy(
      &(input->segments), &(output->segments)))
  {
    return false;
  }
  return true;
}

slg_msgs__msg__SegmentArray *
slg_msgs__msg__SegmentArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slg_msgs__msg__SegmentArray * msg = (slg_msgs__msg__SegmentArray *)allocator.allocate(sizeof(slg_msgs__msg__SegmentArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slg_msgs__msg__SegmentArray));
  bool success = slg_msgs__msg__SegmentArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slg_msgs__msg__SegmentArray__destroy(slg_msgs__msg__SegmentArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slg_msgs__msg__SegmentArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slg_msgs__msg__SegmentArray__Sequence__init(slg_msgs__msg__SegmentArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slg_msgs__msg__SegmentArray * data = NULL;

  if (size) {
    data = (slg_msgs__msg__SegmentArray *)allocator.zero_allocate(size, sizeof(slg_msgs__msg__SegmentArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slg_msgs__msg__SegmentArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slg_msgs__msg__SegmentArray__fini(&data[i - 1]);
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
slg_msgs__msg__SegmentArray__Sequence__fini(slg_msgs__msg__SegmentArray__Sequence * array)
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
      slg_msgs__msg__SegmentArray__fini(&array->data[i]);
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

slg_msgs__msg__SegmentArray__Sequence *
slg_msgs__msg__SegmentArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slg_msgs__msg__SegmentArray__Sequence * array = (slg_msgs__msg__SegmentArray__Sequence *)allocator.allocate(sizeof(slg_msgs__msg__SegmentArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slg_msgs__msg__SegmentArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slg_msgs__msg__SegmentArray__Sequence__destroy(slg_msgs__msg__SegmentArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slg_msgs__msg__SegmentArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slg_msgs__msg__SegmentArray__Sequence__are_equal(const slg_msgs__msg__SegmentArray__Sequence * lhs, const slg_msgs__msg__SegmentArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slg_msgs__msg__SegmentArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slg_msgs__msg__SegmentArray__Sequence__copy(
  const slg_msgs__msg__SegmentArray__Sequence * input,
  slg_msgs__msg__SegmentArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slg_msgs__msg__SegmentArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slg_msgs__msg__SegmentArray * data =
      (slg_msgs__msg__SegmentArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slg_msgs__msg__SegmentArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slg_msgs__msg__SegmentArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slg_msgs__msg__SegmentArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

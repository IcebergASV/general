// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `detections`
#include "comp_tasks_interfaces/msg/detail/simplified_detection__functions.h"

bool
comp_tasks_interfaces__msg__SimplifiedDetectionArray__init(comp_tasks_interfaces__msg__SimplifiedDetectionArray * msg)
{
  if (!msg) {
    return false;
  }
  // detections
  if (!comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__init(&msg->detections, 0)) {
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(comp_tasks_interfaces__msg__SimplifiedDetectionArray * msg)
{
  if (!msg) {
    return;
  }
  // detections
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__fini(&msg->detections);
}

bool
comp_tasks_interfaces__msg__SimplifiedDetectionArray__are_equal(const comp_tasks_interfaces__msg__SimplifiedDetectionArray * lhs, const comp_tasks_interfaces__msg__SimplifiedDetectionArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detections
  if (!comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__msg__SimplifiedDetectionArray__copy(
  const comp_tasks_interfaces__msg__SimplifiedDetectionArray * input,
  comp_tasks_interfaces__msg__SimplifiedDetectionArray * output)
{
  if (!input || !output) {
    return false;
  }
  // detections
  if (!comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__msg__SimplifiedDetectionArray *
comp_tasks_interfaces__msg__SimplifiedDetectionArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__SimplifiedDetectionArray * msg = (comp_tasks_interfaces__msg__SimplifiedDetectionArray *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__SimplifiedDetectionArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__msg__SimplifiedDetectionArray));
  bool success = comp_tasks_interfaces__msg__SimplifiedDetectionArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__msg__SimplifiedDetectionArray__destroy(comp_tasks_interfaces__msg__SimplifiedDetectionArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__init(comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__SimplifiedDetectionArray * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__msg__SimplifiedDetectionArray *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__msg__SimplifiedDetectionArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__msg__SimplifiedDetectionArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(&data[i - 1]);
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
comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__fini(comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * array)
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
      comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(&array->data[i]);
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

comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence *
comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * array = (comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__destroy(comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__are_equal(const comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * lhs, const comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__msg__SimplifiedDetectionArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence__copy(
  const comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * input,
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__msg__SimplifiedDetectionArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__msg__SimplifiedDetectionArray * data =
      (comp_tasks_interfaces__msg__SimplifiedDetectionArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__msg__SimplifiedDetectionArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__msg__SimplifiedDetectionArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetection.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/msg/detail/simplified_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_name`
// Member `id`
#include "rosidl_runtime_c/string_functions.h"

bool
comp_tasks_interfaces__msg__SimplifiedDetection__init(comp_tasks_interfaces__msg__SimplifiedDetection * msg)
{
  if (!msg) {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__init(&msg->class_name)) {
    comp_tasks_interfaces__msg__SimplifiedDetection__fini(msg);
    return false;
  }
  // score
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    comp_tasks_interfaces__msg__SimplifiedDetection__fini(msg);
    return false;
  }
  // x
  return true;
}

void
comp_tasks_interfaces__msg__SimplifiedDetection__fini(comp_tasks_interfaces__msg__SimplifiedDetection * msg)
{
  if (!msg) {
    return;
  }
  // class_name
  rosidl_runtime_c__String__fini(&msg->class_name);
  // score
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // x
}

bool
comp_tasks_interfaces__msg__SimplifiedDetection__are_equal(const comp_tasks_interfaces__msg__SimplifiedDetection * lhs, const comp_tasks_interfaces__msg__SimplifiedDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_name), &(rhs->class_name)))
  {
    return false;
  }
  // score
  if (lhs->score != rhs->score) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__msg__SimplifiedDetection__copy(
  const comp_tasks_interfaces__msg__SimplifiedDetection * input,
  comp_tasks_interfaces__msg__SimplifiedDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__copy(
      &(input->class_name), &(output->class_name)))
  {
    return false;
  }
  // score
  output->score = input->score;
  // id
  if (!rosidl_runtime_c__String__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // x
  output->x = input->x;
  return true;
}

comp_tasks_interfaces__msg__SimplifiedDetection *
comp_tasks_interfaces__msg__SimplifiedDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__SimplifiedDetection * msg = (comp_tasks_interfaces__msg__SimplifiedDetection *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__SimplifiedDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__msg__SimplifiedDetection));
  bool success = comp_tasks_interfaces__msg__SimplifiedDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__msg__SimplifiedDetection__destroy(comp_tasks_interfaces__msg__SimplifiedDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__msg__SimplifiedDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__init(comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__SimplifiedDetection * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__msg__SimplifiedDetection *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__msg__SimplifiedDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__msg__SimplifiedDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__msg__SimplifiedDetection__fini(&data[i - 1]);
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
comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__fini(comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * array)
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
      comp_tasks_interfaces__msg__SimplifiedDetection__fini(&array->data[i]);
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

comp_tasks_interfaces__msg__SimplifiedDetection__Sequence *
comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * array = (comp_tasks_interfaces__msg__SimplifiedDetection__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__SimplifiedDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__destroy(comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__are_equal(const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * lhs, const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__msg__SimplifiedDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__copy(
  const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * input,
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__msg__SimplifiedDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__msg__SimplifiedDetection * data =
      (comp_tasks_interfaces__msg__SimplifiedDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__msg__SimplifiedDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__msg__SimplifiedDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__msg__SimplifiedDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

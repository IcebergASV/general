// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/msg/detail/start_task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `task`
#include "comp_tasks_interfaces/msg/detail/task__functions.h"
// Member `start_pnt`
// Member `finish_pnt`
#include "geographic_msgs/msg/detail/geo_point__functions.h"

bool
comp_tasks_interfaces__msg__StartTask__init(comp_tasks_interfaces__msg__StartTask * msg)
{
  if (!msg) {
    return false;
  }
  // task
  if (!comp_tasks_interfaces__msg__Task__init(&msg->task)) {
    comp_tasks_interfaces__msg__StartTask__fini(msg);
    return false;
  }
  // start_pnt
  if (!geographic_msgs__msg__GeoPoint__init(&msg->start_pnt)) {
    comp_tasks_interfaces__msg__StartTask__fini(msg);
    return false;
  }
  // finish_pnt
  if (!geographic_msgs__msg__GeoPoint__init(&msg->finish_pnt)) {
    comp_tasks_interfaces__msg__StartTask__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__msg__StartTask__fini(comp_tasks_interfaces__msg__StartTask * msg)
{
  if (!msg) {
    return;
  }
  // task
  comp_tasks_interfaces__msg__Task__fini(&msg->task);
  // start_pnt
  geographic_msgs__msg__GeoPoint__fini(&msg->start_pnt);
  // finish_pnt
  geographic_msgs__msg__GeoPoint__fini(&msg->finish_pnt);
}

bool
comp_tasks_interfaces__msg__StartTask__are_equal(const comp_tasks_interfaces__msg__StartTask * lhs, const comp_tasks_interfaces__msg__StartTask * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task
  if (!comp_tasks_interfaces__msg__Task__are_equal(
      &(lhs->task), &(rhs->task)))
  {
    return false;
  }
  // start_pnt
  if (!geographic_msgs__msg__GeoPoint__are_equal(
      &(lhs->start_pnt), &(rhs->start_pnt)))
  {
    return false;
  }
  // finish_pnt
  if (!geographic_msgs__msg__GeoPoint__are_equal(
      &(lhs->finish_pnt), &(rhs->finish_pnt)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__msg__StartTask__copy(
  const comp_tasks_interfaces__msg__StartTask * input,
  comp_tasks_interfaces__msg__StartTask * output)
{
  if (!input || !output) {
    return false;
  }
  // task
  if (!comp_tasks_interfaces__msg__Task__copy(
      &(input->task), &(output->task)))
  {
    return false;
  }
  // start_pnt
  if (!geographic_msgs__msg__GeoPoint__copy(
      &(input->start_pnt), &(output->start_pnt)))
  {
    return false;
  }
  // finish_pnt
  if (!geographic_msgs__msg__GeoPoint__copy(
      &(input->finish_pnt), &(output->finish_pnt)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__msg__StartTask *
comp_tasks_interfaces__msg__StartTask__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__StartTask * msg = (comp_tasks_interfaces__msg__StartTask *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__StartTask), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__msg__StartTask));
  bool success = comp_tasks_interfaces__msg__StartTask__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__msg__StartTask__destroy(comp_tasks_interfaces__msg__StartTask * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__msg__StartTask__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__msg__StartTask__Sequence__init(comp_tasks_interfaces__msg__StartTask__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__StartTask * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__msg__StartTask *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__msg__StartTask), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__msg__StartTask__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__msg__StartTask__fini(&data[i - 1]);
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
comp_tasks_interfaces__msg__StartTask__Sequence__fini(comp_tasks_interfaces__msg__StartTask__Sequence * array)
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
      comp_tasks_interfaces__msg__StartTask__fini(&array->data[i]);
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

comp_tasks_interfaces__msg__StartTask__Sequence *
comp_tasks_interfaces__msg__StartTask__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__StartTask__Sequence * array = (comp_tasks_interfaces__msg__StartTask__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__StartTask__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__msg__StartTask__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__msg__StartTask__Sequence__destroy(comp_tasks_interfaces__msg__StartTask__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__msg__StartTask__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__msg__StartTask__Sequence__are_equal(const comp_tasks_interfaces__msg__StartTask__Sequence * lhs, const comp_tasks_interfaces__msg__StartTask__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__msg__StartTask__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__msg__StartTask__Sequence__copy(
  const comp_tasks_interfaces__msg__StartTask__Sequence * input,
  comp_tasks_interfaces__msg__StartTask__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__msg__StartTask);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__msg__StartTask * data =
      (comp_tasks_interfaces__msg__StartTask *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__msg__StartTask__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__msg__StartTask__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__msg__StartTask__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

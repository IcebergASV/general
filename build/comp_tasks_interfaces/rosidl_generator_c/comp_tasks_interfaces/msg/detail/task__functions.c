// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_tasks_interfaces:msg/Task.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/msg/detail/task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
comp_tasks_interfaces__msg__Task__init(comp_tasks_interfaces__msg__Task * msg)
{
  if (!msg) {
    return false;
  }
  // current_task
  return true;
}

void
comp_tasks_interfaces__msg__Task__fini(comp_tasks_interfaces__msg__Task * msg)
{
  if (!msg) {
    return;
  }
  // current_task
}

bool
comp_tasks_interfaces__msg__Task__are_equal(const comp_tasks_interfaces__msg__Task * lhs, const comp_tasks_interfaces__msg__Task * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_task
  if (lhs->current_task != rhs->current_task) {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__msg__Task__copy(
  const comp_tasks_interfaces__msg__Task * input,
  comp_tasks_interfaces__msg__Task * output)
{
  if (!input || !output) {
    return false;
  }
  // current_task
  output->current_task = input->current_task;
  return true;
}

comp_tasks_interfaces__msg__Task *
comp_tasks_interfaces__msg__Task__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__Task * msg = (comp_tasks_interfaces__msg__Task *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__Task), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__msg__Task));
  bool success = comp_tasks_interfaces__msg__Task__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__msg__Task__destroy(comp_tasks_interfaces__msg__Task * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__msg__Task__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__msg__Task__Sequence__init(comp_tasks_interfaces__msg__Task__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__Task * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__msg__Task *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__msg__Task), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__msg__Task__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__msg__Task__fini(&data[i - 1]);
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
comp_tasks_interfaces__msg__Task__Sequence__fini(comp_tasks_interfaces__msg__Task__Sequence * array)
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
      comp_tasks_interfaces__msg__Task__fini(&array->data[i]);
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

comp_tasks_interfaces__msg__Task__Sequence *
comp_tasks_interfaces__msg__Task__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__msg__Task__Sequence * array = (comp_tasks_interfaces__msg__Task__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__msg__Task__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__msg__Task__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__msg__Task__Sequence__destroy(comp_tasks_interfaces__msg__Task__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__msg__Task__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__msg__Task__Sequence__are_equal(const comp_tasks_interfaces__msg__Task__Sequence * lhs, const comp_tasks_interfaces__msg__Task__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__msg__Task__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__msg__Task__Sequence__copy(
  const comp_tasks_interfaces__msg__Task__Sequence * input,
  comp_tasks_interfaces__msg__Task__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__msg__Task);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__msg__Task * data =
      (comp_tasks_interfaces__msg__Task *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__msg__Task__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__msg__Task__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__msg__Task__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

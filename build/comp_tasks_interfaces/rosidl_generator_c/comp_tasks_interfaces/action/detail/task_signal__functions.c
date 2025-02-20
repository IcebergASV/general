// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/action/detail/task_signal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `task`
#include "comp_tasks_interfaces/msg/detail/task__functions.h"

bool
comp_tasks_interfaces__action__TaskSignal_Goal__init(comp_tasks_interfaces__action__TaskSignal_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // task
  if (!comp_tasks_interfaces__msg__Task__init(&msg->task)) {
    comp_tasks_interfaces__action__TaskSignal_Goal__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_Goal__fini(comp_tasks_interfaces__action__TaskSignal_Goal * msg)
{
  if (!msg) {
    return;
  }
  // task
  comp_tasks_interfaces__msg__Task__fini(&msg->task);
}

bool
comp_tasks_interfaces__action__TaskSignal_Goal__are_equal(const comp_tasks_interfaces__action__TaskSignal_Goal * lhs, const comp_tasks_interfaces__action__TaskSignal_Goal * rhs)
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
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_Goal__copy(
  const comp_tasks_interfaces__action__TaskSignal_Goal * input,
  comp_tasks_interfaces__action__TaskSignal_Goal * output)
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
  return true;
}

comp_tasks_interfaces__action__TaskSignal_Goal *
comp_tasks_interfaces__action__TaskSignal_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Goal * msg = (comp_tasks_interfaces__action__TaskSignal_Goal *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_Goal));
  bool success = comp_tasks_interfaces__action__TaskSignal_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_Goal__destroy(comp_tasks_interfaces__action__TaskSignal_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__init(comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Goal * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_Goal *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_Goal__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_Goal__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_Goal__Sequence *
comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_Goal__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_Goal__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_Goal * data =
      (comp_tasks_interfaces__action__TaskSignal_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
comp_tasks_interfaces__action__TaskSignal_Result__init(comp_tasks_interfaces__action__TaskSignal_Result * msg)
{
  if (!msg) {
    return false;
  }
  // status
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_Result__fini(comp_tasks_interfaces__action__TaskSignal_Result * msg)
{
  if (!msg) {
    return;
  }
  // status
}

bool
comp_tasks_interfaces__action__TaskSignal_Result__are_equal(const comp_tasks_interfaces__action__TaskSignal_Result * lhs, const comp_tasks_interfaces__action__TaskSignal_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_Result__copy(
  const comp_tasks_interfaces__action__TaskSignal_Result * input,
  comp_tasks_interfaces__action__TaskSignal_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  return true;
}

comp_tasks_interfaces__action__TaskSignal_Result *
comp_tasks_interfaces__action__TaskSignal_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Result * msg = (comp_tasks_interfaces__action__TaskSignal_Result *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_Result));
  bool success = comp_tasks_interfaces__action__TaskSignal_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_Result__destroy(comp_tasks_interfaces__action__TaskSignal_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_Result__Sequence__init(comp_tasks_interfaces__action__TaskSignal_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Result * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_Result *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_Result__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_Result__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_Result__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_Result__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_Result__Sequence *
comp_tasks_interfaces__action__TaskSignal_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Result__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_Result__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_Result__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_Result__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_Result__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_Result__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_Result__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_Result * data =
      (comp_tasks_interfaces__action__TaskSignal_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
comp_tasks_interfaces__action__TaskSignal_Feedback__init(comp_tasks_interfaces__action__TaskSignal_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // task_complete
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_Feedback__fini(comp_tasks_interfaces__action__TaskSignal_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // task_complete
}

bool
comp_tasks_interfaces__action__TaskSignal_Feedback__are_equal(const comp_tasks_interfaces__action__TaskSignal_Feedback * lhs, const comp_tasks_interfaces__action__TaskSignal_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_complete
  if (lhs->task_complete != rhs->task_complete) {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_Feedback__copy(
  const comp_tasks_interfaces__action__TaskSignal_Feedback * input,
  comp_tasks_interfaces__action__TaskSignal_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // task_complete
  output->task_complete = input->task_complete;
  return true;
}

comp_tasks_interfaces__action__TaskSignal_Feedback *
comp_tasks_interfaces__action__TaskSignal_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Feedback * msg = (comp_tasks_interfaces__action__TaskSignal_Feedback *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_Feedback));
  bool success = comp_tasks_interfaces__action__TaskSignal_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_Feedback__destroy(comp_tasks_interfaces__action__TaskSignal_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__init(comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Feedback * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_Feedback *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_Feedback__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_Feedback__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence *
comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_Feedback * data =
      (comp_tasks_interfaces__action__TaskSignal_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__init(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!comp_tasks_interfaces__action__TaskSignal_Goal__init(&msg->goal)) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  comp_tasks_interfaces__action__TaskSignal_Goal__fini(&msg->goal);
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__are_equal(const comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * lhs, const comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!comp_tasks_interfaces__action__TaskSignal_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__copy(
  const comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * input,
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!comp_tasks_interfaces__action__TaskSignal_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__action__TaskSignal_SendGoal_Request *
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * msg = (comp_tasks_interfaces__action__TaskSignal_SendGoal_Request *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request));
  bool success = comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__destroy(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__init(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_SendGoal_Request *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence *
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * data =
      (comp_tasks_interfaces__action__TaskSignal_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__init(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__are_equal(const comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * lhs, const comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__copy(
  const comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * input,
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__action__TaskSignal_SendGoal_Response *
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * msg = (comp_tasks_interfaces__action__TaskSignal_SendGoal_Response *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response));
  bool success = comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__destroy(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__init(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_SendGoal_Response *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence *
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * data =
      (comp_tasks_interfaces__action__TaskSignal_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__init(comp_tasks_interfaces__action__TaskSignal_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(comp_tasks_interfaces__action__TaskSignal_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__are_equal(const comp_tasks_interfaces__action__TaskSignal_GetResult_Request * lhs, const comp_tasks_interfaces__action__TaskSignal_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__copy(
  const comp_tasks_interfaces__action__TaskSignal_GetResult_Request * input,
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__action__TaskSignal_GetResult_Request *
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request * msg = (comp_tasks_interfaces__action__TaskSignal_GetResult_Request *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request));
  bool success = comp_tasks_interfaces__action__TaskSignal_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__destroy(comp_tasks_interfaces__action__TaskSignal_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__init(comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_GetResult_Request *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence *
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_GetResult_Request * data =
      (comp_tasks_interfaces__action__TaskSignal_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__init(comp_tasks_interfaces__action__TaskSignal_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!comp_tasks_interfaces__action__TaskSignal_Result__init(&msg->result)) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(comp_tasks_interfaces__action__TaskSignal_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  comp_tasks_interfaces__action__TaskSignal_Result__fini(&msg->result);
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__are_equal(const comp_tasks_interfaces__action__TaskSignal_GetResult_Response * lhs, const comp_tasks_interfaces__action__TaskSignal_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!comp_tasks_interfaces__action__TaskSignal_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__copy(
  const comp_tasks_interfaces__action__TaskSignal_GetResult_Response * input,
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!comp_tasks_interfaces__action__TaskSignal_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__action__TaskSignal_GetResult_Response *
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response * msg = (comp_tasks_interfaces__action__TaskSignal_GetResult_Response *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response));
  bool success = comp_tasks_interfaces__action__TaskSignal_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__destroy(comp_tasks_interfaces__action__TaskSignal_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__init(comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_GetResult_Response *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence *
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_GetResult_Response * data =
      (comp_tasks_interfaces__action__TaskSignal_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"

bool
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__init(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!comp_tasks_interfaces__action__TaskSignal_Feedback__init(&msg->feedback)) {
    comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  comp_tasks_interfaces__action__TaskSignal_Feedback__fini(&msg->feedback);
}

bool
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__are_equal(const comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * lhs, const comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!comp_tasks_interfaces__action__TaskSignal_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__copy(
  const comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * input,
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!comp_tasks_interfaces__action__TaskSignal_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

comp_tasks_interfaces__action__TaskSignal_FeedbackMessage *
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * msg = (comp_tasks_interfaces__action__TaskSignal_FeedbackMessage *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage));
  bool success = comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__destroy(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__init(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * data = NULL;

  if (size) {
    data = (comp_tasks_interfaces__action__TaskSignal_FeedbackMessage *)allocator.zero_allocate(size, sizeof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(&data[i - 1]);
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
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__fini(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * array)
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
      comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(&array->data[i]);
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

comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence *
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * array = (comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence *)allocator.allocate(sizeof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__destroy(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__are_equal(const comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * lhs, const comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence__copy(
  const comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * input,
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * data =
      (comp_tasks_interfaces__action__TaskSignal_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

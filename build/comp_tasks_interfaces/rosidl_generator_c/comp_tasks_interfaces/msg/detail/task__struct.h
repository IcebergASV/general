// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_tasks_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TASK_NOT_SET'.
enum
{
  comp_tasks_interfaces__msg__Task__TASK_NOT_SET = 0
};

/// Constant 'MANEUVERING'.
enum
{
  comp_tasks_interfaces__msg__Task__MANEUVERING = 1
};

/// Constant 'NAVIGATION'.
enum
{
  comp_tasks_interfaces__msg__Task__NAVIGATION = 2
};

/// Constant 'COLLISION_AVOIDANCE'.
enum
{
  comp_tasks_interfaces__msg__Task__COLLISION_AVOIDANCE = 3
};

/// Constant 'DOCKING'.
enum
{
  comp_tasks_interfaces__msg__Task__DOCKING = 4
};

/// Struct defined in msg/Task in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__msg__Task
{
  uint8_t current_task;
} comp_tasks_interfaces__msg__Task;

// Struct for a sequence of comp_tasks_interfaces__msg__Task.
typedef struct comp_tasks_interfaces__msg__Task__Sequence
{
  comp_tasks_interfaces__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_

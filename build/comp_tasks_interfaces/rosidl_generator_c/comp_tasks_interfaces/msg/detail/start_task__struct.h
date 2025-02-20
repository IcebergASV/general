// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__STRUCT_H_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task'
#include "comp_tasks_interfaces/msg/detail/task__struct.h"
// Member 'start_pnt'
// Member 'finish_pnt'
#include "geographic_msgs/msg/detail/geo_point__struct.h"

/// Struct defined in msg/StartTask in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__msg__StartTask
{
  comp_tasks_interfaces__msg__Task task;
  geographic_msgs__msg__GeoPoint start_pnt;
  geographic_msgs__msg__GeoPoint finish_pnt;
} comp_tasks_interfaces__msg__StartTask;

// Struct for a sequence of comp_tasks_interfaces__msg__StartTask.
typedef struct comp_tasks_interfaces__msg__StartTask__Sequence
{
  comp_tasks_interfaces__msg__StartTask * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__msg__StartTask__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__START_TASK__STRUCT_H_

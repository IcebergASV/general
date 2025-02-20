// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetection.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__STRUCT_H_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_name'
// Member 'id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SimplifiedDetection in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__msg__SimplifiedDetection
{
  rosidl_runtime_c__String class_name;
  double score;
  rosidl_runtime_c__String id;
  double x;
} comp_tasks_interfaces__msg__SimplifiedDetection;

// Struct for a sequence of comp_tasks_interfaces__msg__SimplifiedDetection.
typedef struct comp_tasks_interfaces__msg__SimplifiedDetection__Sequence
{
  comp_tasks_interfaces__msg__SimplifiedDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__msg__SimplifiedDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION__STRUCT_H_

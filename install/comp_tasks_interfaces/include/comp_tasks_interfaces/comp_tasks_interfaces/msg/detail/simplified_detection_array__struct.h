// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__STRUCT_H_
#define COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'detections'
#include "comp_tasks_interfaces/msg/detail/simplified_detection__struct.h"

/// Struct defined in msg/SimplifiedDetectionArray in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__msg__SimplifiedDetectionArray
{
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence detections;
} comp_tasks_interfaces__msg__SimplifiedDetectionArray;

// Struct for a sequence of comp_tasks_interfaces__msg__SimplifiedDetectionArray.
typedef struct comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence
{
  comp_tasks_interfaces__msg__SimplifiedDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__msg__SimplifiedDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TASKS_INTERFACES__MSG__DETAIL__SIMPLIFIED_DETECTION_ARRAY__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'red_marker'
// Member 'green_marker'
#include "perception_interfaces/msg/detail/prop__struct.h"
// Member 'midpoint'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Gate in the package perception_interfaces.
typedef struct perception_interfaces__msg__Gate
{
  perception_interfaces__msg__Prop red_marker;
  perception_interfaces__msg__Prop green_marker;
  geometry_msgs__msg__Point midpoint;
} perception_interfaces__msg__Gate;

// Struct for a sequence of perception_interfaces__msg__Gate.
typedef struct perception_interfaces__msg__Gate__Sequence
{
  perception_interfaces__msg__Gate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__Gate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE__STRUCT_H_

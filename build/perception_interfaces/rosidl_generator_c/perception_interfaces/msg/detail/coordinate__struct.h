// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'label'
#include "rosidl_runtime_c/string.h"
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Coordinate in the package perception_interfaces.
typedef struct perception_interfaces__msg__Coordinate
{
  int32_t id;
  rosidl_runtime_c__String label;
  geometry_msgs__msg__Point point;
  float radius;
  float probability;
} perception_interfaces__msg__Coordinate;

// Struct for a sequence of perception_interfaces__msg__Coordinate.
typedef struct perception_interfaces__msg__Coordinate__Sequence
{
  perception_interfaces__msg__Coordinate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__Coordinate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__STRUCT_H_

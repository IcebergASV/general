// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'coordinates'
#include "perception_interfaces/msg/detail/coordinates__struct.h"

/// Struct defined in msg/Coordinates in the package perception_interfaces.
typedef struct perception_interfaces__msg__Coordinates
{
  perception_interfaces__msg__Coordinates__Sequence coordinates;
} perception_interfaces__msg__Coordinates;

// Struct for a sequence of perception_interfaces__msg__Coordinates.
typedef struct perception_interfaces__msg__Coordinates__Sequence
{
  perception_interfaces__msg__Coordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__Coordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATES__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BoundingBox in the package perception_interfaces.
typedef struct perception_interfaces__msg__BoundingBox
{
  uint16_t xmin;
  uint16_t ymin;
  uint16_t xmax;
  uint16_t ymax;
  uint16_t id;
  float probability;
  rosidl_runtime_c__String class_id;
} perception_interfaces__msg__BoundingBox;

// Struct for a sequence of perception_interfaces__msg__BoundingBox.
typedef struct perception_interfaces__msg__BoundingBox__Sequence
{
  perception_interfaces__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/PropArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__PROP_ARRAY__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__PROP_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'props'
#include "perception_interfaces/msg/detail/prop__struct.h"

/// Struct defined in msg/PropArray in the package perception_interfaces.
typedef struct perception_interfaces__msg__PropArray
{
  perception_interfaces__msg__Prop__Sequence props;
} perception_interfaces__msg__PropArray;

// Struct for a sequence of perception_interfaces__msg__PropArray.
typedef struct perception_interfaces__msg__PropArray__Sequence
{
  perception_interfaces__msg__PropArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__PropArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__PROP_ARRAY__STRUCT_H_

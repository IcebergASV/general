// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/GateArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'gates'
#include "perception_interfaces/msg/detail/gate__struct.h"

/// Struct defined in msg/GateArray in the package perception_interfaces.
typedef struct perception_interfaces__msg__GateArray
{
  perception_interfaces__msg__Gate__Sequence gates;
} perception_interfaces__msg__GateArray;

// Struct for a sequence of perception_interfaces__msg__GateArray.
typedef struct perception_interfaces__msg__GateArray__Sequence
{
  perception_interfaces__msg__GateArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__GateArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__GATE_ARRAY__STRUCT_H_

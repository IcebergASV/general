// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/LidarDetectedPropArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP_ARRAY__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'lidar_detected_props'
#include "perception_interfaces/msg/detail/lidar_detected_prop__struct.h"

/// Struct defined in msg/LidarDetectedPropArray in the package perception_interfaces.
typedef struct perception_interfaces__msg__LidarDetectedPropArray
{
  perception_interfaces__msg__LidarDetectedProp__Sequence lidar_detected_props;
} perception_interfaces__msg__LidarDetectedPropArray;

// Struct for a sequence of perception_interfaces__msg__LidarDetectedPropArray.
typedef struct perception_interfaces__msg__LidarDetectedPropArray__Sequence
{
  perception_interfaces__msg__LidarDetectedPropArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__LidarDetectedPropArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP_ARRAY__STRUCT_H_

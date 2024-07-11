// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_interfaces:msg/LidarDetectedProp.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__STRUCT_H_
#define PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__STRUCT_H_

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
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/LidarDetectedProp in the package perception_interfaces.
typedef struct perception_interfaces__msg__LidarDetectedProp
{
  rosidl_runtime_c__String label;
  geometry_msgs__msg__Point center;
  float radius;
  float radius_diff;
} perception_interfaces__msg__LidarDetectedProp;

// Struct for a sequence of perception_interfaces__msg__LidarDetectedProp.
typedef struct perception_interfaces__msg__LidarDetectedProp__Sequence
{
  perception_interfaces__msg__LidarDetectedProp * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_interfaces__msg__LidarDetectedProp__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP__STRUCT_H_

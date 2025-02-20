// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/IcebergDetection.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"
// Member 'bbox'
#include "yolov8_msgs/msg/detail/iceberg_bounding_box2_d__struct.h"

/// Struct defined in msg/IcebergDetection in the package yolov8_msgs.
/**
  * defines a YOLOv8 detection result
 */
typedef struct yolov8_msgs__msg__IcebergDetection
{
  /// class probability
  int32_t class_id;
  rosidl_runtime_c__String class_name;
  double score;
  /// 2D bounding box surrounding the object in pixels
  yolov8_msgs__msg__IcebergBoundingBox2D bbox;
} yolov8_msgs__msg__IcebergDetection;

// Struct for a sequence of yolov8_msgs__msg__IcebergDetection.
typedef struct yolov8_msgs__msg__IcebergDetection__Sequence
{
  yolov8_msgs__msg__IcebergDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__IcebergDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/IcebergDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'icebergdetections'
#include "yolov8_msgs/msg/detail/iceberg_detection__struct.h"

/// Struct defined in msg/IcebergDetectionArray in the package yolov8_msgs.
/**
  * represents all YOLOv8 detections in one frame
 */
typedef struct yolov8_msgs__msg__IcebergDetectionArray
{
  std_msgs__msg__Header header;
  yolov8_msgs__msg__IcebergDetection__Sequence icebergdetections;
} yolov8_msgs__msg__IcebergDetectionArray;

// Struct for a sequence of yolov8_msgs__msg__IcebergDetectionArray.
typedef struct yolov8_msgs__msg__IcebergDetectionArray__Sequence
{
  yolov8_msgs__msg__IcebergDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__IcebergDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__ICEBERG_DETECTION_ARRAY__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__STRUCT_H_
#define SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__STRUCT_H_

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
// Member 'segments'
#include "slg_msgs/msg/detail/segment__struct.h"

/// Struct defined in msg/SegmentArray in the package slg_msgs.
/**
  * Message for array of Segment
 */
typedef struct slg_msgs__msg__SegmentArray
{
  /// Standard message header.
  std_msgs__msg__Header header;
  /// List of sorted segments.
  slg_msgs__msg__Segment__Sequence segments;
} slg_msgs__msg__SegmentArray;

// Struct for a sequence of slg_msgs__msg__SegmentArray.
typedef struct slg_msgs__msg__SegmentArray__Sequence
{
  slg_msgs__msg__SegmentArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slg_msgs__msg__SegmentArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__STRUCT_H_

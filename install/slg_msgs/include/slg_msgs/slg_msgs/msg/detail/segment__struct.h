// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT__STRUCT_H_
#define SLG_MSGS__MSG__DETAIL__SEGMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BACKGROUND'.
/**
  * Type of the labels
 */
enum
{
  slg_msgs__msg__Segment__BACKGROUND = 0ul
};

/// Constant 'PERSON'.
enum
{
  slg_msgs__msg__Segment__PERSON = 1ul
};

/// Constant 'PERSON_CANE'.
enum
{
  slg_msgs__msg__Segment__PERSON_CANE = 2ul
};

/// Constant 'PERSON_WHEEL_CHAIR'.
enum
{
  slg_msgs__msg__Segment__PERSON_WHEEL_CHAIR = 3ul
};

// Include directives for member types
// Member 'last_point_prior_segment'
// Member 'first_point_next_segment'
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Segment in the package slg_msgs.
/**
  * Message for sorted segment of points.
 */
typedef struct slg_msgs__msg__Segment
{
  /// Each segment is assigned an id, which uniquely identifies the segment consistently across multiple frames.
  /// The segments can be linked to previous and next segment using lastPointPriorSeg and firstPointNextSeg, respectively.
  /// Segment messages can be used as an input to a classifier such as a person detector, or for annotating
  /// sensor_msgs/Laserscan messages with groundtruth person tracks.
  /// Id of the segment
  uint64_t id;
  /// Label of the segment
  uint32_t label;
  /// Angular distance to the closest boundary (in rads)
  double angular_distance;
  /// Last point of the previous segment
  geometry_msgs__msg__Point last_point_prior_segment;
  /// First point of the next segment
  geometry_msgs__msg__Point first_point_next_segment;
  /// Points per segment
  geometry_msgs__msg__Point__Sequence points;
} slg_msgs__msg__Segment;

// Struct for a sequence of slg_msgs__msg__Segment.
typedef struct slg_msgs__msg__Segment__Sequence
{
  slg_msgs__msg__Segment * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slg_msgs__msg__Segment__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT__STRUCT_H_

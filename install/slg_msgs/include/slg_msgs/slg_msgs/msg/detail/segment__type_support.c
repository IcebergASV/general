// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "slg_msgs/msg/detail/segment__rosidl_typesupport_introspection_c.h"
#include "slg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "slg_msgs/msg/detail/segment__functions.h"
#include "slg_msgs/msg/detail/segment__struct.h"


// Include directives for member types
// Member `last_point_prior_segment`
// Member `first_point_next_segment`
// Member `points`
#include "geometry_msgs/msg/point.h"
// Member `last_point_prior_segment`
// Member `first_point_next_segment`
// Member `points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  slg_msgs__msg__Segment__init(message_memory);
}

void slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_fini_function(void * message_memory)
{
  slg_msgs__msg__Segment__fini(message_memory);
}

size_t slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__size_function__Segment__points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__get_const_function__Segment__points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__get_function__Segment__points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__fetch_function__Segment__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__get_const_function__Segment__points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__assign_function__Segment__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__get_function__Segment__points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__resize_function__Segment__points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_member_array[6] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__Segment, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__Segment, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__Segment, angular_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_point_prior_segment",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__Segment, last_point_prior_segment),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "first_point_next_segment",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__Segment, first_point_next_segment),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__Segment, points),  // bytes offset in struct
    NULL,  // default value
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__size_function__Segment__points,  // size() function pointer
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__get_const_function__Segment__points,  // get_const(index) function pointer
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__get_function__Segment__points,  // get(index) function pointer
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__fetch_function__Segment__points,  // fetch(index, &value) function pointer
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__assign_function__Segment__points,  // assign(index, value) function pointer
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__resize_function__Segment__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_members = {
  "slg_msgs__msg",  // message namespace
  "Segment",  // message name
  6,  // number of fields
  sizeof(slg_msgs__msg__Segment),
  slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_member_array,  // message members
  slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_init_function,  // function to initialize message memory (memory has to be allocated)
  slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_type_support_handle = {
  0,
  &slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_slg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slg_msgs, msg, Segment)() {
  slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_type_support_handle.typesupport_identifier) {
    slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &slg_msgs__msg__Segment__rosidl_typesupport_introspection_c__Segment_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

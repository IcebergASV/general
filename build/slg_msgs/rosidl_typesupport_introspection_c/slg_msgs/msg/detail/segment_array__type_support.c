// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "slg_msgs/msg/detail/segment_array__rosidl_typesupport_introspection_c.h"
#include "slg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "slg_msgs/msg/detail/segment_array__functions.h"
#include "slg_msgs/msg/detail/segment_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `segments`
#include "slg_msgs/msg/segment.h"
// Member `segments`
#include "slg_msgs/msg/detail/segment__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  slg_msgs__msg__SegmentArray__init(message_memory);
}

void slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_fini_function(void * message_memory)
{
  slg_msgs__msg__SegmentArray__fini(message_memory);
}

size_t slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__size_function__SegmentArray__segments(
  const void * untyped_member)
{
  const slg_msgs__msg__Segment__Sequence * member =
    (const slg_msgs__msg__Segment__Sequence *)(untyped_member);
  return member->size;
}

const void * slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__get_const_function__SegmentArray__segments(
  const void * untyped_member, size_t index)
{
  const slg_msgs__msg__Segment__Sequence * member =
    (const slg_msgs__msg__Segment__Sequence *)(untyped_member);
  return &member->data[index];
}

void * slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__get_function__SegmentArray__segments(
  void * untyped_member, size_t index)
{
  slg_msgs__msg__Segment__Sequence * member =
    (slg_msgs__msg__Segment__Sequence *)(untyped_member);
  return &member->data[index];
}

void slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__fetch_function__SegmentArray__segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const slg_msgs__msg__Segment * item =
    ((const slg_msgs__msg__Segment *)
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__get_const_function__SegmentArray__segments(untyped_member, index));
  slg_msgs__msg__Segment * value =
    (slg_msgs__msg__Segment *)(untyped_value);
  *value = *item;
}

void slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__assign_function__SegmentArray__segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  slg_msgs__msg__Segment * item =
    ((slg_msgs__msg__Segment *)
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__get_function__SegmentArray__segments(untyped_member, index));
  const slg_msgs__msg__Segment * value =
    (const slg_msgs__msg__Segment *)(untyped_value);
  *item = *value;
}

bool slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__resize_function__SegmentArray__segments(
  void * untyped_member, size_t size)
{
  slg_msgs__msg__Segment__Sequence * member =
    (slg_msgs__msg__Segment__Sequence *)(untyped_member);
  slg_msgs__msg__Segment__Sequence__fini(member);
  return slg_msgs__msg__Segment__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__SegmentArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "segments",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slg_msgs__msg__SegmentArray, segments),  // bytes offset in struct
    NULL,  // default value
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__size_function__SegmentArray__segments,  // size() function pointer
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__get_const_function__SegmentArray__segments,  // get_const(index) function pointer
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__get_function__SegmentArray__segments,  // get(index) function pointer
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__fetch_function__SegmentArray__segments,  // fetch(index, &value) function pointer
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__assign_function__SegmentArray__segments,  // assign(index, value) function pointer
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__resize_function__SegmentArray__segments  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_members = {
  "slg_msgs__msg",  // message namespace
  "SegmentArray",  // message name
  2,  // number of fields
  sizeof(slg_msgs__msg__SegmentArray),
  slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_member_array,  // message members
  slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_init_function,  // function to initialize message memory (memory has to be allocated)
  slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_type_support_handle = {
  0,
  &slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_slg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slg_msgs, msg, SegmentArray)() {
  slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slg_msgs, msg, Segment)();
  if (!slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_type_support_handle.typesupport_identifier) {
    slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &slg_msgs__msg__SegmentArray__rosidl_typesupport_introspection_c__SegmentArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

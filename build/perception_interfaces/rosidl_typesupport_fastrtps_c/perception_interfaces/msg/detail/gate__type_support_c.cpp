// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/gate__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "perception_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "perception_interfaces/msg/detail/gate__struct.h"
#include "perception_interfaces/msg/detail/gate__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point__functions.h"  // midpoint
#include "perception_interfaces/msg/detail/prop__functions.h"  // green_marker, red_marker

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_perception_interfaces
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_perception_interfaces
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_perception_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();
size_t get_serialized_size_perception_interfaces__msg__Prop(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_perception_interfaces__msg__Prop(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, perception_interfaces, msg, Prop)();


using _Gate__ros_msg_type = perception_interfaces__msg__Gate;

static bool _Gate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Gate__ros_msg_type * ros_message = static_cast<const _Gate__ros_msg_type *>(untyped_ros_message);
  // Field name: red_marker
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, perception_interfaces, msg, Prop
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->red_marker, cdr))
    {
      return false;
    }
  }

  // Field name: green_marker
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, perception_interfaces, msg, Prop
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->green_marker, cdr))
    {
      return false;
    }
  }

  // Field name: midpoint
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->midpoint, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Gate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Gate__ros_msg_type * ros_message = static_cast<_Gate__ros_msg_type *>(untyped_ros_message);
  // Field name: red_marker
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, perception_interfaces, msg, Prop
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->red_marker))
    {
      return false;
    }
  }

  // Field name: green_marker
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, perception_interfaces, msg, Prop
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->green_marker))
    {
      return false;
    }
  }

  // Field name: midpoint
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->midpoint))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_perception_interfaces
size_t get_serialized_size_perception_interfaces__msg__Gate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Gate__ros_msg_type * ros_message = static_cast<const _Gate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name red_marker

  current_alignment += get_serialized_size_perception_interfaces__msg__Prop(
    &(ros_message->red_marker), current_alignment);
  // field.name green_marker

  current_alignment += get_serialized_size_perception_interfaces__msg__Prop(
    &(ros_message->green_marker), current_alignment);
  // field.name midpoint

  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->midpoint), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Gate__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_perception_interfaces__msg__Gate(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_perception_interfaces
size_t max_serialized_size_perception_interfaces__msg__Gate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: red_marker
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_perception_interfaces__msg__Prop(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: green_marker
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_perception_interfaces__msg__Prop(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: midpoint
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = perception_interfaces__msg__Gate;
    is_plain =
      (
      offsetof(DataType, midpoint) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Gate__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_perception_interfaces__msg__Gate(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Gate = {
  "perception_interfaces::msg",
  "Gate",
  _Gate__cdr_serialize,
  _Gate__cdr_deserialize,
  _Gate__get_serialized_size,
  _Gate__max_serialized_size
};

static rosidl_message_type_support_t _Gate__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Gate,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, perception_interfaces, msg, Gate)() {
  return &_Gate__type_support;
}

#if defined(__cplusplus)
}
#endif

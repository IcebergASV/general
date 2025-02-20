// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/msg/detail/start_task__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "comp_tasks_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "comp_tasks_interfaces/msg/detail/start_task__struct.h"
#include "comp_tasks_interfaces/msg/detail/start_task__functions.h"
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

#include "comp_tasks_interfaces/msg/detail/task__functions.h"  // task
#include "geographic_msgs/msg/detail/geo_point__functions.h"  // finish_pnt, start_pnt

// forward declare type support functions
size_t get_serialized_size_comp_tasks_interfaces__msg__Task(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_comp_tasks_interfaces__msg__Task(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, msg, Task)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_comp_tasks_interfaces
size_t get_serialized_size_geographic_msgs__msg__GeoPoint(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_comp_tasks_interfaces
size_t max_serialized_size_geographic_msgs__msg__GeoPoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geographic_msgs, msg, GeoPoint)();


using _StartTask__ros_msg_type = comp_tasks_interfaces__msg__StartTask;

static bool _StartTask__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartTask__ros_msg_type * ros_message = static_cast<const _StartTask__ros_msg_type *>(untyped_ros_message);
  // Field name: task
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, msg, Task
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->task, cdr))
    {
      return false;
    }
  }

  // Field name: start_pnt
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geographic_msgs, msg, GeoPoint
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->start_pnt, cdr))
    {
      return false;
    }
  }

  // Field name: finish_pnt
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geographic_msgs, msg, GeoPoint
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->finish_pnt, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StartTask__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartTask__ros_msg_type * ros_message = static_cast<_StartTask__ros_msg_type *>(untyped_ros_message);
  // Field name: task
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, msg, Task
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->task))
    {
      return false;
    }
  }

  // Field name: start_pnt
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geographic_msgs, msg, GeoPoint
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->start_pnt))
    {
      return false;
    }
  }

  // Field name: finish_pnt
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geographic_msgs, msg, GeoPoint
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->finish_pnt))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_comp_tasks_interfaces
size_t get_serialized_size_comp_tasks_interfaces__msg__StartTask(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartTask__ros_msg_type * ros_message = static_cast<const _StartTask__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name task

  current_alignment += get_serialized_size_comp_tasks_interfaces__msg__Task(
    &(ros_message->task), current_alignment);
  // field.name start_pnt

  current_alignment += get_serialized_size_geographic_msgs__msg__GeoPoint(
    &(ros_message->start_pnt), current_alignment);
  // field.name finish_pnt

  current_alignment += get_serialized_size_geographic_msgs__msg__GeoPoint(
    &(ros_message->finish_pnt), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StartTask__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_comp_tasks_interfaces__msg__StartTask(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_comp_tasks_interfaces
size_t max_serialized_size_comp_tasks_interfaces__msg__StartTask(
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

  // member: task
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_comp_tasks_interfaces__msg__Task(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: start_pnt
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geographic_msgs__msg__GeoPoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: finish_pnt
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geographic_msgs__msg__GeoPoint(
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
    using DataType = comp_tasks_interfaces__msg__StartTask;
    is_plain =
      (
      offsetof(DataType, finish_pnt) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartTask__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_comp_tasks_interfaces__msg__StartTask(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartTask = {
  "comp_tasks_interfaces::msg",
  "StartTask",
  _StartTask__cdr_serialize,
  _StartTask__cdr_deserialize,
  _StartTask__get_serialized_size,
  _StartTask__max_serialized_size
};

static rosidl_message_type_support_t _StartTask__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartTask,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, comp_tasks_interfaces, msg, StartTask)() {
  return &_StartTask__type_support;
}

#if defined(__cplusplus)
}
#endif

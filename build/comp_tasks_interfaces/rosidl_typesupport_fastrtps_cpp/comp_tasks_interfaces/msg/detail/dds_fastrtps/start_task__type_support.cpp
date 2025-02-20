// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice
#include "comp_tasks_interfaces/msg/detail/start_task__rosidl_typesupport_fastrtps_cpp.hpp"
#include "comp_tasks_interfaces/msg/detail/start_task__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace comp_tasks_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const comp_tasks_interfaces::msg::Task &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  comp_tasks_interfaces::msg::Task &);
size_t get_serialized_size(
  const comp_tasks_interfaces::msg::Task &,
  size_t current_alignment);
size_t
max_serialized_size_Task(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace comp_tasks_interfaces

namespace geographic_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geographic_msgs::msg::GeoPoint &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geographic_msgs::msg::GeoPoint &);
size_t get_serialized_size(
  const geographic_msgs::msg::GeoPoint &,
  size_t current_alignment);
size_t
max_serialized_size_GeoPoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geographic_msgs

// functions for geographic_msgs::msg::GeoPoint already declared above


namespace comp_tasks_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_tasks_interfaces
cdr_serialize(
  const comp_tasks_interfaces::msg::StartTask & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: task
  comp_tasks_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.task,
    cdr);
  // Member: start_pnt
  geographic_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.start_pnt,
    cdr);
  // Member: finish_pnt
  geographic_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.finish_pnt,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_tasks_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  comp_tasks_interfaces::msg::StartTask & ros_message)
{
  // Member: task
  comp_tasks_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.task);

  // Member: start_pnt
  geographic_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.start_pnt);

  // Member: finish_pnt
  geographic_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.finish_pnt);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_tasks_interfaces
get_serialized_size(
  const comp_tasks_interfaces::msg::StartTask & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: task

  current_alignment +=
    comp_tasks_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.task, current_alignment);
  // Member: start_pnt

  current_alignment +=
    geographic_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.start_pnt, current_alignment);
  // Member: finish_pnt

  current_alignment +=
    geographic_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.finish_pnt, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_comp_tasks_interfaces
max_serialized_size_StartTask(
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


  // Member: task
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        comp_tasks_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Task(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: start_pnt
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geographic_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_GeoPoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: finish_pnt
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geographic_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_GeoPoint(
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
    using DataType = comp_tasks_interfaces::msg::StartTask;
    is_plain =
      (
      offsetof(DataType, finish_pnt) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _StartTask__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const comp_tasks_interfaces::msg::StartTask *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StartTask__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<comp_tasks_interfaces::msg::StartTask *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StartTask__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const comp_tasks_interfaces::msg::StartTask *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StartTask__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_StartTask(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _StartTask__callbacks = {
  "comp_tasks_interfaces::msg",
  "StartTask",
  _StartTask__cdr_serialize,
  _StartTask__cdr_deserialize,
  _StartTask__get_serialized_size,
  _StartTask__max_serialized_size
};

static rosidl_message_type_support_t _StartTask__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StartTask__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace comp_tasks_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<comp_tasks_interfaces::msg::StartTask>()
{
  return &comp_tasks_interfaces::msg::typesupport_fastrtps_cpp::_StartTask__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, comp_tasks_interfaces, msg, StartTask)() {
  return &comp_tasks_interfaces::msg::typesupport_fastrtps_cpp::_StartTask__handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from yolov8_msgs:msg/KeyPoint3DArray.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/key_point3_d_array__rosidl_typesupport_fastrtps_cpp.hpp"
#include "yolov8_msgs/msg/detail/key_point3_d_array__struct.hpp"

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
namespace yolov8_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const yolov8_msgs::msg::KeyPoint3D &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  yolov8_msgs::msg::KeyPoint3D &);
size_t get_serialized_size(
  const yolov8_msgs::msg::KeyPoint3D &,
  size_t current_alignment);
size_t
max_serialized_size_KeyPoint3D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace yolov8_msgs


namespace yolov8_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolov8_msgs
cdr_serialize(
  const yolov8_msgs::msg::KeyPoint3DArray & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: data
  {
    size_t size = ros_message.data.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      yolov8_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.data[i],
        cdr);
    }
  }
  // Member: frame_id
  cdr << ros_message.frame_id;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolov8_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  yolov8_msgs::msg::KeyPoint3DArray & ros_message)
{
  // Member: data
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.data.resize(size);
    for (size_t i = 0; i < size; i++) {
      yolov8_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.data[i]);
    }
  }

  // Member: frame_id
  cdr >> ros_message.frame_id;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolov8_msgs
get_serialized_size(
  const yolov8_msgs::msg::KeyPoint3DArray & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: data
  {
    size_t array_size = ros_message.data.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        yolov8_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.data[index], current_alignment);
    }
  }
  // Member: frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.frame_id.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolov8_msgs
max_serialized_size_KeyPoint3DArray(
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


  // Member: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        yolov8_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_KeyPoint3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: frame_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yolov8_msgs::msg::KeyPoint3DArray;
    is_plain =
      (
      offsetof(DataType, frame_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _KeyPoint3DArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const yolov8_msgs::msg::KeyPoint3DArray *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _KeyPoint3DArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<yolov8_msgs::msg::KeyPoint3DArray *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _KeyPoint3DArray__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const yolov8_msgs::msg::KeyPoint3DArray *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _KeyPoint3DArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_KeyPoint3DArray(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _KeyPoint3DArray__callbacks = {
  "yolov8_msgs::msg",
  "KeyPoint3DArray",
  _KeyPoint3DArray__cdr_serialize,
  _KeyPoint3DArray__cdr_deserialize,
  _KeyPoint3DArray__get_serialized_size,
  _KeyPoint3DArray__max_serialized_size
};

static rosidl_message_type_support_t _KeyPoint3DArray__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_KeyPoint3DArray__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace yolov8_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_yolov8_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<yolov8_msgs::msg::KeyPoint3DArray>()
{
  return &yolov8_msgs::msg::typesupport_fastrtps_cpp::_KeyPoint3DArray__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yolov8_msgs, msg, KeyPoint3DArray)() {
  return &yolov8_msgs::msg::typesupport_fastrtps_cpp::_KeyPoint3DArray__handle;
}

#ifdef __cplusplus
}
#endif

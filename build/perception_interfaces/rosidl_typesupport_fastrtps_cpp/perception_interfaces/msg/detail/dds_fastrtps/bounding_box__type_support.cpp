// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/bounding_box__rosidl_typesupport_fastrtps_cpp.hpp"
#include "perception_interfaces/msg/detail/bounding_box__struct.hpp"

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

namespace perception_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
cdr_serialize(
  const perception_interfaces::msg::BoundingBox & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: xmin
  cdr << ros_message.xmin;
  // Member: ymin
  cdr << ros_message.ymin;
  // Member: xmax
  cdr << ros_message.xmax;
  // Member: ymax
  cdr << ros_message.ymax;
  // Member: id
  cdr << ros_message.id;
  // Member: probability
  cdr << ros_message.probability;
  // Member: class_id
  cdr << ros_message.class_id;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  perception_interfaces::msg::BoundingBox & ros_message)
{
  // Member: xmin
  cdr >> ros_message.xmin;

  // Member: ymin
  cdr >> ros_message.ymin;

  // Member: xmax
  cdr >> ros_message.xmax;

  // Member: ymax
  cdr >> ros_message.ymax;

  // Member: id
  cdr >> ros_message.id;

  // Member: probability
  cdr >> ros_message.probability;

  // Member: class_id
  cdr >> ros_message.class_id;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
get_serialized_size(
  const perception_interfaces::msg::BoundingBox & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: xmin
  {
    size_t item_size = sizeof(ros_message.xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ymin
  {
    size_t item_size = sizeof(ros_message.ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xmax
  {
    size_t item_size = sizeof(ros_message.xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ymax
  {
    size_t item_size = sizeof(ros_message.ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: probability
  {
    size_t item_size = sizeof(ros_message.probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: class_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.class_id.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
max_serialized_size_BoundingBox(
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


  // Member: xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ymax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: probability
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: class_id
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
    using DataType = perception_interfaces::msg::BoundingBox;
    is_plain =
      (
      offsetof(DataType, class_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BoundingBox__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const perception_interfaces::msg::BoundingBox *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BoundingBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<perception_interfaces::msg::BoundingBox *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BoundingBox__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const perception_interfaces::msg::BoundingBox *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BoundingBox__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BoundingBox(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BoundingBox__callbacks = {
  "perception_interfaces::msg",
  "BoundingBox",
  _BoundingBox__cdr_serialize,
  _BoundingBox__cdr_deserialize,
  _BoundingBox__get_serialized_size,
  _BoundingBox__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBox__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BoundingBox__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace perception_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_perception_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<perception_interfaces::msg::BoundingBox>()
{
  return &perception_interfaces::msg::typesupport_fastrtps_cpp::_BoundingBox__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, perception_interfaces, msg, BoundingBox)() {
  return &perception_interfaces::msg::typesupport_fastrtps_cpp::_BoundingBox__handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from perception_interfaces:msg/PropArray.idl
// generated code does not contain a copyright notice
#include "perception_interfaces/msg/detail/prop_array__rosidl_typesupport_fastrtps_cpp.hpp"
#include "perception_interfaces/msg/detail/prop_array__struct.hpp"

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
bool cdr_serialize(
  const perception_interfaces::msg::Prop &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  perception_interfaces::msg::Prop &);
size_t get_serialized_size(
  const perception_interfaces::msg::Prop &,
  size_t current_alignment);
size_t
max_serialized_size_Prop(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace perception_interfaces


namespace perception_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
cdr_serialize(
  const perception_interfaces::msg::PropArray & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: props
  {
    size_t size = ros_message.props.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      perception_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.props[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  perception_interfaces::msg::PropArray & ros_message)
{
  // Member: props
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.props.resize(size);
    for (size_t i = 0; i < size; i++) {
      perception_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.props[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
get_serialized_size(
  const perception_interfaces::msg::PropArray & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: props
  {
    size_t array_size = ros_message.props.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        perception_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.props[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_perception_interfaces
max_serialized_size_PropArray(
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


  // Member: props
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
        perception_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Prop(
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
    using DataType = perception_interfaces::msg::PropArray;
    is_plain =
      (
      offsetof(DataType, props) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PropArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const perception_interfaces::msg::PropArray *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PropArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<perception_interfaces::msg::PropArray *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PropArray__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const perception_interfaces::msg::PropArray *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PropArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PropArray(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PropArray__callbacks = {
  "perception_interfaces::msg",
  "PropArray",
  _PropArray__cdr_serialize,
  _PropArray__cdr_deserialize,
  _PropArray__get_serialized_size,
  _PropArray__max_serialized_size
};

static rosidl_message_type_support_t _PropArray__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PropArray__callbacks,
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
get_message_type_support_handle<perception_interfaces::msg::PropArray>()
{
  return &perception_interfaces::msg::typesupport_fastrtps_cpp::_PropArray__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, perception_interfaces, msg, PropArray)() {
  return &perception_interfaces::msg::typesupport_fastrtps_cpp::_PropArray__handle;
}

#ifdef __cplusplus
}
#endif

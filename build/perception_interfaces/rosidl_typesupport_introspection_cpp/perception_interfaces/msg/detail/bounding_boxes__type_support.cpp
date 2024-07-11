// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from perception_interfaces:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "perception_interfaces/msg/detail/bounding_boxes__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace perception_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BoundingBoxes_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) perception_interfaces::msg::BoundingBoxes(_init);
}

void BoundingBoxes_fini_function(void * message_memory)
{
  auto typed_message = static_cast<perception_interfaces::msg::BoundingBoxes *>(message_memory);
  typed_message->~BoundingBoxes();
}

size_t size_function__BoundingBoxes__bounding_boxes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<perception_interfaces::msg::BoundingBox> *>(untyped_member);
  return member->size();
}

const void * get_const_function__BoundingBoxes__bounding_boxes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<perception_interfaces::msg::BoundingBox> *>(untyped_member);
  return &member[index];
}

void * get_function__BoundingBoxes__bounding_boxes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<perception_interfaces::msg::BoundingBox> *>(untyped_member);
  return &member[index];
}

void fetch_function__BoundingBoxes__bounding_boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const perception_interfaces::msg::BoundingBox *>(
    get_const_function__BoundingBoxes__bounding_boxes(untyped_member, index));
  auto & value = *reinterpret_cast<perception_interfaces::msg::BoundingBox *>(untyped_value);
  value = item;
}

void assign_function__BoundingBoxes__bounding_boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<perception_interfaces::msg::BoundingBox *>(
    get_function__BoundingBoxes__bounding_boxes(untyped_member, index));
  const auto & value = *reinterpret_cast<const perception_interfaces::msg::BoundingBox *>(untyped_value);
  item = value;
}

void resize_function__BoundingBoxes__bounding_boxes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<perception_interfaces::msg::BoundingBox> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BoundingBoxes_message_member_array[1] = {
  {
    "bounding_boxes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<perception_interfaces::msg::BoundingBox>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces::msg::BoundingBoxes, bounding_boxes),  // bytes offset in struct
    nullptr,  // default value
    size_function__BoundingBoxes__bounding_boxes,  // size() function pointer
    get_const_function__BoundingBoxes__bounding_boxes,  // get_const(index) function pointer
    get_function__BoundingBoxes__bounding_boxes,  // get(index) function pointer
    fetch_function__BoundingBoxes__bounding_boxes,  // fetch(index, &value) function pointer
    assign_function__BoundingBoxes__bounding_boxes,  // assign(index, value) function pointer
    resize_function__BoundingBoxes__bounding_boxes  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BoundingBoxes_message_members = {
  "perception_interfaces::msg",  // message namespace
  "BoundingBoxes",  // message name
  1,  // number of fields
  sizeof(perception_interfaces::msg::BoundingBoxes),
  BoundingBoxes_message_member_array,  // message members
  BoundingBoxes_init_function,  // function to initialize message memory (memory has to be allocated)
  BoundingBoxes_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BoundingBoxes_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BoundingBoxes_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace perception_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<perception_interfaces::msg::BoundingBoxes>()
{
  return &::perception_interfaces::msg::rosidl_typesupport_introspection_cpp::BoundingBoxes_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, perception_interfaces, msg, BoundingBoxes)() {
  return &::perception_interfaces::msg::rosidl_typesupport_introspection_cpp::BoundingBoxes_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

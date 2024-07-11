// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from perception_interfaces:msg/Coordinates.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "perception_interfaces/msg/detail/coordinates__struct.hpp"
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

void Coordinates_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) perception_interfaces::msg::Coordinates(_init);
}

void Coordinates_fini_function(void * message_memory)
{
  auto typed_message = static_cast<perception_interfaces::msg::Coordinates *>(message_memory);
  typed_message->~Coordinates();
}

size_t size_function__Coordinates__coordinates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<perception_interfaces::msg::Coordinates> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Coordinates__coordinates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<perception_interfaces::msg::Coordinates> *>(untyped_member);
  return &member[index];
}

void * get_function__Coordinates__coordinates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<perception_interfaces::msg::Coordinates> *>(untyped_member);
  return &member[index];
}

void fetch_function__Coordinates__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const perception_interfaces::msg::Coordinates *>(
    get_const_function__Coordinates__coordinates(untyped_member, index));
  auto & value = *reinterpret_cast<perception_interfaces::msg::Coordinates *>(untyped_value);
  value = item;
}

void assign_function__Coordinates__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<perception_interfaces::msg::Coordinates *>(
    get_function__Coordinates__coordinates(untyped_member, index));
  const auto & value = *reinterpret_cast<const perception_interfaces::msg::Coordinates *>(untyped_value);
  item = value;
}

void resize_function__Coordinates__coordinates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<perception_interfaces::msg::Coordinates> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Coordinates_message_member_array[1] = {
  {
    "coordinates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<perception_interfaces::msg::Coordinates>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces::msg::Coordinates, coordinates),  // bytes offset in struct
    nullptr,  // default value
    size_function__Coordinates__coordinates,  // size() function pointer
    get_const_function__Coordinates__coordinates,  // get_const(index) function pointer
    get_function__Coordinates__coordinates,  // get(index) function pointer
    fetch_function__Coordinates__coordinates,  // fetch(index, &value) function pointer
    assign_function__Coordinates__coordinates,  // assign(index, value) function pointer
    resize_function__Coordinates__coordinates  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Coordinates_message_members = {
  "perception_interfaces::msg",  // message namespace
  "Coordinates",  // message name
  1,  // number of fields
  sizeof(perception_interfaces::msg::Coordinates),
  Coordinates_message_member_array,  // message members
  Coordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  Coordinates_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Coordinates_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Coordinates_message_members,
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
get_message_type_support_handle<perception_interfaces::msg::Coordinates>()
{
  return &::perception_interfaces::msg::rosidl_typesupport_introspection_cpp::Coordinates_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, perception_interfaces, msg, Coordinates)() {
  return &::perception_interfaces::msg::rosidl_typesupport_introspection_cpp::Coordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

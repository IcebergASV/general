// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from perception_interfaces:msg/Gate.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "perception_interfaces/msg/detail/gate__struct.hpp"
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

void Gate_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) perception_interfaces::msg::Gate(_init);
}

void Gate_fini_function(void * message_memory)
{
  auto typed_message = static_cast<perception_interfaces::msg::Gate *>(message_memory);
  typed_message->~Gate();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Gate_message_member_array[3] = {
  {
    "red_marker",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<perception_interfaces::msg::Prop>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces::msg::Gate, red_marker),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "green_marker",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<perception_interfaces::msg::Prop>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces::msg::Gate, green_marker),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "midpoint",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces::msg::Gate, midpoint),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Gate_message_members = {
  "perception_interfaces::msg",  // message namespace
  "Gate",  // message name
  3,  // number of fields
  sizeof(perception_interfaces::msg::Gate),
  Gate_message_member_array,  // message members
  Gate_init_function,  // function to initialize message memory (memory has to be allocated)
  Gate_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Gate_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Gate_message_members,
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
get_message_type_support_handle<perception_interfaces::msg::Gate>()
{
  return &::perception_interfaces::msg::rosidl_typesupport_introspection_cpp::Gate_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, perception_interfaces, msg, Gate)() {
  return &::perception_interfaces::msg::rosidl_typesupport_introspection_cpp::Gate_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

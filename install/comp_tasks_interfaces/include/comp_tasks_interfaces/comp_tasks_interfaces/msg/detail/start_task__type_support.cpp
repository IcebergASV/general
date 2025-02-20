// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from comp_tasks_interfaces:msg/StartTask.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "comp_tasks_interfaces/msg/detail/start_task__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace comp_tasks_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void StartTask_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) comp_tasks_interfaces::msg::StartTask(_init);
}

void StartTask_fini_function(void * message_memory)
{
  auto typed_message = static_cast<comp_tasks_interfaces::msg::StartTask *>(message_memory);
  typed_message->~StartTask();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember StartTask_message_member_array[3] = {
  {
    "task",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_tasks_interfaces::msg::Task>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces::msg::StartTask, task),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "start_pnt",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geographic_msgs::msg::GeoPoint>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces::msg::StartTask, start_pnt),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "finish_pnt",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geographic_msgs::msg::GeoPoint>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces::msg::StartTask, finish_pnt),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers StartTask_message_members = {
  "comp_tasks_interfaces::msg",  // message namespace
  "StartTask",  // message name
  3,  // number of fields
  sizeof(comp_tasks_interfaces::msg::StartTask),
  StartTask_message_member_array,  // message members
  StartTask_init_function,  // function to initialize message memory (memory has to be allocated)
  StartTask_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t StartTask_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &StartTask_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace comp_tasks_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<comp_tasks_interfaces::msg::StartTask>()
{
  return &::comp_tasks_interfaces::msg::rosidl_typesupport_introspection_cpp::StartTask_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, comp_tasks_interfaces, msg, StartTask)() {
  return &::comp_tasks_interfaces::msg::rosidl_typesupport_introspection_cpp::StartTask_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

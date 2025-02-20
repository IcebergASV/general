// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__struct.hpp"
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

void SimplifiedDetectionArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) comp_tasks_interfaces::msg::SimplifiedDetectionArray(_init);
}

void SimplifiedDetectionArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<comp_tasks_interfaces::msg::SimplifiedDetectionArray *>(message_memory);
  typed_message->~SimplifiedDetectionArray();
}

size_t size_function__SimplifiedDetectionArray__detections(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<comp_tasks_interfaces::msg::SimplifiedDetection> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SimplifiedDetectionArray__detections(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<comp_tasks_interfaces::msg::SimplifiedDetection> *>(untyped_member);
  return &member[index];
}

void * get_function__SimplifiedDetectionArray__detections(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<comp_tasks_interfaces::msg::SimplifiedDetection> *>(untyped_member);
  return &member[index];
}

void fetch_function__SimplifiedDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const comp_tasks_interfaces::msg::SimplifiedDetection *>(
    get_const_function__SimplifiedDetectionArray__detections(untyped_member, index));
  auto & value = *reinterpret_cast<comp_tasks_interfaces::msg::SimplifiedDetection *>(untyped_value);
  value = item;
}

void assign_function__SimplifiedDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<comp_tasks_interfaces::msg::SimplifiedDetection *>(
    get_function__SimplifiedDetectionArray__detections(untyped_member, index));
  const auto & value = *reinterpret_cast<const comp_tasks_interfaces::msg::SimplifiedDetection *>(untyped_value);
  item = value;
}

void resize_function__SimplifiedDetectionArray__detections(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<comp_tasks_interfaces::msg::SimplifiedDetection> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SimplifiedDetectionArray_message_member_array[1] = {
  {
    "detections",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<comp_tasks_interfaces::msg::SimplifiedDetection>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces::msg::SimplifiedDetectionArray, detections),  // bytes offset in struct
    nullptr,  // default value
    size_function__SimplifiedDetectionArray__detections,  // size() function pointer
    get_const_function__SimplifiedDetectionArray__detections,  // get_const(index) function pointer
    get_function__SimplifiedDetectionArray__detections,  // get(index) function pointer
    fetch_function__SimplifiedDetectionArray__detections,  // fetch(index, &value) function pointer
    assign_function__SimplifiedDetectionArray__detections,  // assign(index, value) function pointer
    resize_function__SimplifiedDetectionArray__detections  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SimplifiedDetectionArray_message_members = {
  "comp_tasks_interfaces::msg",  // message namespace
  "SimplifiedDetectionArray",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces::msg::SimplifiedDetectionArray),
  SimplifiedDetectionArray_message_member_array,  // message members
  SimplifiedDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  SimplifiedDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SimplifiedDetectionArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SimplifiedDetectionArray_message_members,
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
get_message_type_support_handle<comp_tasks_interfaces::msg::SimplifiedDetectionArray>()
{
  return &::comp_tasks_interfaces::msg::rosidl_typesupport_introspection_cpp::SimplifiedDetectionArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, comp_tasks_interfaces, msg, SimplifiedDetectionArray)() {
  return &::comp_tasks_interfaces::msg::rosidl_typesupport_introspection_cpp::SimplifiedDetectionArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

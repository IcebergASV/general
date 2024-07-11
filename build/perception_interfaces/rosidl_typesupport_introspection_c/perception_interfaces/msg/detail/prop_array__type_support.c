// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from perception_interfaces:msg/PropArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "perception_interfaces/msg/detail/prop_array__rosidl_typesupport_introspection_c.h"
#include "perception_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "perception_interfaces/msg/detail/prop_array__functions.h"
#include "perception_interfaces/msg/detail/prop_array__struct.h"


// Include directives for member types
// Member `props`
#include "perception_interfaces/msg/prop.h"
// Member `props`
#include "perception_interfaces/msg/detail/prop__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  perception_interfaces__msg__PropArray__init(message_memory);
}

void perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_fini_function(void * message_memory)
{
  perception_interfaces__msg__PropArray__fini(message_memory);
}

size_t perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__size_function__PropArray__props(
  const void * untyped_member)
{
  const perception_interfaces__msg__Prop__Sequence * member =
    (const perception_interfaces__msg__Prop__Sequence *)(untyped_member);
  return member->size;
}

const void * perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__get_const_function__PropArray__props(
  const void * untyped_member, size_t index)
{
  const perception_interfaces__msg__Prop__Sequence * member =
    (const perception_interfaces__msg__Prop__Sequence *)(untyped_member);
  return &member->data[index];
}

void * perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__get_function__PropArray__props(
  void * untyped_member, size_t index)
{
  perception_interfaces__msg__Prop__Sequence * member =
    (perception_interfaces__msg__Prop__Sequence *)(untyped_member);
  return &member->data[index];
}

void perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__fetch_function__PropArray__props(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const perception_interfaces__msg__Prop * item =
    ((const perception_interfaces__msg__Prop *)
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__get_const_function__PropArray__props(untyped_member, index));
  perception_interfaces__msg__Prop * value =
    (perception_interfaces__msg__Prop *)(untyped_value);
  *value = *item;
}

void perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__assign_function__PropArray__props(
  void * untyped_member, size_t index, const void * untyped_value)
{
  perception_interfaces__msg__Prop * item =
    ((perception_interfaces__msg__Prop *)
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__get_function__PropArray__props(untyped_member, index));
  const perception_interfaces__msg__Prop * value =
    (const perception_interfaces__msg__Prop *)(untyped_value);
  *item = *value;
}

bool perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__resize_function__PropArray__props(
  void * untyped_member, size_t size)
{
  perception_interfaces__msg__Prop__Sequence * member =
    (perception_interfaces__msg__Prop__Sequence *)(untyped_member);
  perception_interfaces__msg__Prop__Sequence__fini(member);
  return perception_interfaces__msg__Prop__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_member_array[1] = {
  {
    "props",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces__msg__PropArray, props),  // bytes offset in struct
    NULL,  // default value
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__size_function__PropArray__props,  // size() function pointer
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__get_const_function__PropArray__props,  // get_const(index) function pointer
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__get_function__PropArray__props,  // get(index) function pointer
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__fetch_function__PropArray__props,  // fetch(index, &value) function pointer
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__assign_function__PropArray__props,  // assign(index, value) function pointer
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__resize_function__PropArray__props  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_members = {
  "perception_interfaces__msg",  // message namespace
  "PropArray",  // message name
  1,  // number of fields
  sizeof(perception_interfaces__msg__PropArray),
  perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_member_array,  // message members
  perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_init_function,  // function to initialize message memory (memory has to be allocated)
  perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_type_support_handle = {
  0,
  &perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_interfaces, msg, PropArray)() {
  perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_interfaces, msg, Prop)();
  if (!perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_type_support_handle.typesupport_identifier) {
    perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &perception_interfaces__msg__PropArray__rosidl_typesupport_introspection_c__PropArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

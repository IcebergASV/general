// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from comp_tasks_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "comp_tasks_interfaces/msg/detail/task__rosidl_typesupport_introspection_c.h"
#include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "comp_tasks_interfaces/msg/detail/task__functions.h"
#include "comp_tasks_interfaces/msg/detail/task__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__msg__Task__init(message_memory);
}

void comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_fini_function(void * message_memory)
{
  comp_tasks_interfaces__msg__Task__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_member_array[1] = {
  {
    "current_task",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__msg__Task, current_task),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_members = {
  "comp_tasks_interfaces__msg",  // message namespace
  "Task",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces__msg__Task),
  comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_member_array,  // message members
  comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, msg, Task)() {
  if (!comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__msg__Task__rosidl_typesupport_introspection_c__Task_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

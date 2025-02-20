// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from comp_tasks_interfaces:msg/SimplifiedDetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__rosidl_typesupport_introspection_c.h"
#include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__functions.h"
#include "comp_tasks_interfaces/msg/detail/simplified_detection_array__struct.h"


// Include directives for member types
// Member `detections`
#include "comp_tasks_interfaces/msg/simplified_detection.h"
// Member `detections`
#include "comp_tasks_interfaces/msg/detail/simplified_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__init(message_memory);
}

void comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_fini_function(void * message_memory)
{
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__fini(message_memory);
}

size_t comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__size_function__SimplifiedDetectionArray__detections(
  const void * untyped_member)
{
  const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * member =
    (const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__get_const_function__SimplifiedDetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * member =
    (const comp_tasks_interfaces__msg__SimplifiedDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__get_function__SimplifiedDetectionArray__detections(
  void * untyped_member, size_t index)
{
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * member =
    (comp_tasks_interfaces__msg__SimplifiedDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__fetch_function__SimplifiedDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const comp_tasks_interfaces__msg__SimplifiedDetection * item =
    ((const comp_tasks_interfaces__msg__SimplifiedDetection *)
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__get_const_function__SimplifiedDetectionArray__detections(untyped_member, index));
  comp_tasks_interfaces__msg__SimplifiedDetection * value =
    (comp_tasks_interfaces__msg__SimplifiedDetection *)(untyped_value);
  *value = *item;
}

void comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__assign_function__SimplifiedDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  comp_tasks_interfaces__msg__SimplifiedDetection * item =
    ((comp_tasks_interfaces__msg__SimplifiedDetection *)
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__get_function__SimplifiedDetectionArray__detections(untyped_member, index));
  const comp_tasks_interfaces__msg__SimplifiedDetection * value =
    (const comp_tasks_interfaces__msg__SimplifiedDetection *)(untyped_value);
  *item = *value;
}

bool comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__resize_function__SimplifiedDetectionArray__detections(
  void * untyped_member, size_t size)
{
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence * member =
    (comp_tasks_interfaces__msg__SimplifiedDetection__Sequence *)(untyped_member);
  comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__fini(member);
  return comp_tasks_interfaces__msg__SimplifiedDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_member_array[1] = {
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__msg__SimplifiedDetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__size_function__SimplifiedDetectionArray__detections,  // size() function pointer
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__get_const_function__SimplifiedDetectionArray__detections,  // get_const(index) function pointer
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__get_function__SimplifiedDetectionArray__detections,  // get(index) function pointer
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__fetch_function__SimplifiedDetectionArray__detections,  // fetch(index, &value) function pointer
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__assign_function__SimplifiedDetectionArray__detections,  // assign(index, value) function pointer
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__resize_function__SimplifiedDetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_members = {
  "comp_tasks_interfaces__msg",  // message namespace
  "SimplifiedDetectionArray",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces__msg__SimplifiedDetectionArray),
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_member_array,  // message members
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, msg, SimplifiedDetectionArray)() {
  comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, msg, SimplifiedDetection)();
  if (!comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__msg__SimplifiedDetectionArray__rosidl_typesupport_introspection_c__SimplifiedDetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

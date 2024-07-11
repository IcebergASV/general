// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from perception_interfaces:msg/LidarDetectedProp.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "perception_interfaces/msg/detail/lidar_detected_prop__rosidl_typesupport_introspection_c.h"
#include "perception_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "perception_interfaces/msg/detail/lidar_detected_prop__functions.h"
#include "perception_interfaces/msg/detail/lidar_detected_prop__struct.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `center`
#include "geometry_msgs/msg/point.h"
// Member `center`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  perception_interfaces__msg__LidarDetectedProp__init(message_memory);
}

void perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_fini_function(void * message_memory)
{
  perception_interfaces__msg__LidarDetectedProp__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_member_array[4] = {
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces__msg__LidarDetectedProp, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces__msg__LidarDetectedProp, center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces__msg__LidarDetectedProp, radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radius_diff",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_interfaces__msg__LidarDetectedProp, radius_diff),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_members = {
  "perception_interfaces__msg",  // message namespace
  "LidarDetectedProp",  // message name
  4,  // number of fields
  sizeof(perception_interfaces__msg__LidarDetectedProp),
  perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_member_array,  // message members
  perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_init_function,  // function to initialize message memory (memory has to be allocated)
  perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_type_support_handle = {
  0,
  &perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_interfaces, msg, LidarDetectedProp)() {
  perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_type_support_handle.typesupport_identifier) {
    perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &perception_interfaces__msg__LidarDetectedProp__rosidl_typesupport_introspection_c__LidarDetectedProp_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

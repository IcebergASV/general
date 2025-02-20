// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
#include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
#include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


// Include directives for member types
// Member `task`
#include "comp_tasks_interfaces/msg/task.h"
// Member `task`
#include "comp_tasks_interfaces/msg/detail/task__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_Goal__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_member_array[1] = {
  {
    "task",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_Goal, task),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_Goal",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_Goal),
  comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Goal)() {
  comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, msg, Task)();
  if (!comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_Goal__rosidl_typesupport_introspection_c__TaskSignal_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_Result__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_Result, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_Result",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_Result),
  comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Result)() {
  if (!comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_Result__rosidl_typesupport_introspection_c__TaskSignal_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_Feedback__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_member_array[1] = {
  {
    "task_complete",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_Feedback, task_complete),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_Feedback",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_Feedback),
  comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Feedback)() {
  if (!comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_Feedback__rosidl_typesupport_introspection_c__TaskSignal_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "comp_tasks_interfaces/action/task_signal.h"
// Member `goal`
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Request),
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Request)() {
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Goal)();
  if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_SendGoal_Response),
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Response)() {
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_members = {
  "comp_tasks_interfaces__action",  // service namespace
  "TaskSignal_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal)() {
  if (!comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_SendGoal_Response)()->data;
  }

  return &comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Request),
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Request)() {
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_GetResult_Request__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "comp_tasks_interfaces/action/task_signal.h"
// Member `result`
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_GetResult_Response),
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Response)() {
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Result)();
  if (!comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_GetResult_Response__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_members = {
  "comp_tasks_interfaces__action",  // service namespace
  "TaskSignal_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult)() {
  if (!comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_GetResult_Response)()->data;
  }

  return &comp_tasks_interfaces__action__detail__task_signal__rosidl_typesupport_introspection_c__TaskSignal_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "comp_tasks_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__functions.h"
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "comp_tasks_interfaces/action/task_signal.h"
// Member `feedback`
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__init(message_memory);
}

void comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_fini_function(void * message_memory)
{
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_members = {
  "comp_tasks_interfaces__action",  // message namespace
  "TaskSignal_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(comp_tasks_interfaces__action__TaskSignal_FeedbackMessage),
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_member_array,  // message members
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_type_support_handle = {
  0,
  &comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_comp_tasks_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_FeedbackMessage)() {
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, comp_tasks_interfaces, action, TaskSignal_Feedback)();
  if (!comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__rosidl_typesupport_introspection_c__TaskSignal_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

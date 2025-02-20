// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__STRUCT_H_
#define COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task'
#include "comp_tasks_interfaces/msg/detail/task__struct.h"

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_Goal
{
  comp_tasks_interfaces__msg__Task task;
} comp_tasks_interfaces__action__TaskSignal_Goal;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_Goal.
typedef struct comp_tasks_interfaces__action__TaskSignal_Goal__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_Result
{
  int32_t status;
} comp_tasks_interfaces__action__TaskSignal_Result;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_Result.
typedef struct comp_tasks_interfaces__action__TaskSignal_Result__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_Feedback
{
  bool task_complete;
} comp_tasks_interfaces__action__TaskSignal_Feedback;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_Feedback.
typedef struct comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "comp_tasks_interfaces/action/detail/task_signal__struct.h"

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  comp_tasks_interfaces__action__TaskSignal_Goal goal;
} comp_tasks_interfaces__action__TaskSignal_SendGoal_Request;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_SendGoal_Request.
typedef struct comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} comp_tasks_interfaces__action__TaskSignal_SendGoal_Response;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_SendGoal_Response.
typedef struct comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} comp_tasks_interfaces__action__TaskSignal_GetResult_Request;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_GetResult_Request.
typedef struct comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_GetResult_Response
{
  int8_t status;
  comp_tasks_interfaces__action__TaskSignal_Result result;
} comp_tasks_interfaces__action__TaskSignal_GetResult_Response;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_GetResult_Response.
typedef struct comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.h"

/// Struct defined in action/TaskSignal in the package comp_tasks_interfaces.
typedef struct comp_tasks_interfaces__action__TaskSignal_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  comp_tasks_interfaces__action__TaskSignal_Feedback feedback;
} comp_tasks_interfaces__action__TaskSignal_FeedbackMessage;

// Struct for a sequence of comp_tasks_interfaces__action__TaskSignal_FeedbackMessage.
typedef struct comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence
{
  comp_tasks_interfaces__action__TaskSignal_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} comp_tasks_interfaces__action__TaskSignal_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__STRUCT_H_

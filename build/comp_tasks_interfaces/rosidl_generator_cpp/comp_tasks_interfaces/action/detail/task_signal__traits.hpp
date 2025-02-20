// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__TRAITS_HPP_
#define COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "comp_tasks_interfaces/action/detail/task_signal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'task'
#include "comp_tasks_interfaces/msg/detail/task__traits.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: task
  {
    out << "task: ";
    to_flow_style_yaml(msg.task, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task:\n";
    to_block_style_yaml(msg.task, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_Goal & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_Goal>()
{
  return "comp_tasks_interfaces::action::TaskSignal_Goal";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_Goal>()
{
  return "comp_tasks_interfaces/action/TaskSignal_Goal";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_Goal>
  : std::integral_constant<bool, has_fixed_size<comp_tasks_interfaces::msg::Task>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_Goal>
  : std::integral_constant<bool, has_bounded_size<comp_tasks_interfaces::msg::Task>::value> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_Result & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_Result>()
{
  return "comp_tasks_interfaces::action::TaskSignal_Result";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_Result>()
{
  return "comp_tasks_interfaces/action/TaskSignal_Result";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_complete
  {
    out << "task_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.task_complete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.task_complete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_Feedback & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_Feedback>()
{
  return "comp_tasks_interfaces::action::TaskSignal_Feedback";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_Feedback>()
{
  return "comp_tasks_interfaces/action/TaskSignal_Feedback";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "comp_tasks_interfaces/action/detail/task_signal__traits.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_SendGoal_Request & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>()
{
  return "comp_tasks_interfaces::action::TaskSignal_SendGoal_Request";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>()
{
  return "comp_tasks_interfaces/action/TaskSignal_SendGoal_Request";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<comp_tasks_interfaces::action::TaskSignal_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<comp_tasks_interfaces::action::TaskSignal_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_SendGoal_Response & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>()
{
  return "comp_tasks_interfaces::action::TaskSignal_SendGoal_Response";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>()
{
  return "comp_tasks_interfaces/action/TaskSignal_SendGoal_Response";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_SendGoal>()
{
  return "comp_tasks_interfaces::action::TaskSignal_SendGoal";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_SendGoal>()
{
  return "comp_tasks_interfaces/action/TaskSignal_SendGoal";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>::value &&
    has_fixed_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>::value &&
    has_bounded_size<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<comp_tasks_interfaces::action::TaskSignal_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_GetResult_Request & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>()
{
  return "comp_tasks_interfaces::action::TaskSignal_GetResult_Request";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>()
{
  return "comp_tasks_interfaces/action/TaskSignal_GetResult_Request";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__traits.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_GetResult_Response & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>()
{
  return "comp_tasks_interfaces::action::TaskSignal_GetResult_Response";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>()
{
  return "comp_tasks_interfaces/action/TaskSignal_GetResult_Response";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<comp_tasks_interfaces::action::TaskSignal_Result>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<comp_tasks_interfaces::action::TaskSignal_Result>::value> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_GetResult>()
{
  return "comp_tasks_interfaces::action::TaskSignal_GetResult";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_GetResult>()
{
  return "comp_tasks_interfaces/action/TaskSignal_GetResult";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>::value &&
    has_fixed_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>::value &&
    has_bounded_size<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>::value
  >
{
};

template<>
struct is_service<comp_tasks_interfaces::action::TaskSignal_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<comp_tasks_interfaces::action::TaskSignal_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<comp_tasks_interfaces::action::TaskSignal_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__traits.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskSignal_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSignal_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSignal_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use comp_tasks_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const comp_tasks_interfaces::action::TaskSignal_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  comp_tasks_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use comp_tasks_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const comp_tasks_interfaces::action::TaskSignal_FeedbackMessage & msg)
{
  return comp_tasks_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage>()
{
  return "comp_tasks_interfaces::action::TaskSignal_FeedbackMessage";
}

template<>
inline const char * name<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage>()
{
  return "comp_tasks_interfaces/action/TaskSignal_FeedbackMessage";
}

template<>
struct has_fixed_size<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<comp_tasks_interfaces::action::TaskSignal_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<comp_tasks_interfaces::action::TaskSignal_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<comp_tasks_interfaces::action::TaskSignal>
  : std::true_type
{
};

template<>
struct is_action_goal<comp_tasks_interfaces::action::TaskSignal_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<comp_tasks_interfaces::action::TaskSignal_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<comp_tasks_interfaces::action::TaskSignal_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__BUILDER_HPP_
#define COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "comp_tasks_interfaces/action/detail/task_signal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_Goal_task
{
public:
  Init_TaskSignal_Goal_task()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_Goal task(::comp_tasks_interfaces::action::TaskSignal_Goal::_task_type arg)
  {
    msg_.task = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_Goal>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_Goal_task();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_Result_status
{
public:
  Init_TaskSignal_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_Result status(::comp_tasks_interfaces::action::TaskSignal_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_Result>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_Result_status();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_Feedback_task_complete
{
public:
  Init_TaskSignal_Feedback_task_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_Feedback task_complete(::comp_tasks_interfaces::action::TaskSignal_Feedback::_task_complete_type arg)
  {
    msg_.task_complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_Feedback>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_Feedback_task_complete();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_SendGoal_Request_goal
{
public:
  explicit Init_TaskSignal_SendGoal_Request_goal(::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request goal(::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request msg_;
};

class Init_TaskSignal_SendGoal_Request_goal_id
{
public:
  Init_TaskSignal_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskSignal_SendGoal_Request_goal goal_id(::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TaskSignal_SendGoal_Request_goal(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_SendGoal_Request>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_SendGoal_Request_goal_id();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_SendGoal_Response_stamp
{
public:
  explicit Init_TaskSignal_SendGoal_Response_stamp(::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response stamp(::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response msg_;
};

class Init_TaskSignal_SendGoal_Response_accepted
{
public:
  Init_TaskSignal_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskSignal_SendGoal_Response_stamp accepted(::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_TaskSignal_SendGoal_Response_stamp(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_SendGoal_Response>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_SendGoal_Response_accepted();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_GetResult_Request_goal_id
{
public:
  Init_TaskSignal_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_GetResult_Request goal_id(::comp_tasks_interfaces::action::TaskSignal_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_GetResult_Request>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_GetResult_Request_goal_id();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_GetResult_Response_result
{
public:
  explicit Init_TaskSignal_GetResult_Response_result(::comp_tasks_interfaces::action::TaskSignal_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_GetResult_Response result(::comp_tasks_interfaces::action::TaskSignal_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_GetResult_Response msg_;
};

class Init_TaskSignal_GetResult_Response_status
{
public:
  Init_TaskSignal_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskSignal_GetResult_Response_result status(::comp_tasks_interfaces::action::TaskSignal_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TaskSignal_GetResult_Response_result(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_GetResult_Response>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_GetResult_Response_status();
}

}  // namespace comp_tasks_interfaces


namespace comp_tasks_interfaces
{

namespace action
{

namespace builder
{

class Init_TaskSignal_FeedbackMessage_feedback
{
public:
  explicit Init_TaskSignal_FeedbackMessage_feedback(::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage feedback(::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage msg_;
};

class Init_TaskSignal_FeedbackMessage_goal_id
{
public:
  Init_TaskSignal_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskSignal_FeedbackMessage_feedback goal_id(::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TaskSignal_FeedbackMessage_feedback(msg_);
  }

private:
  ::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::comp_tasks_interfaces::action::TaskSignal_FeedbackMessage>()
{
  return comp_tasks_interfaces::action::builder::Init_TaskSignal_FeedbackMessage_goal_id();
}

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__BUILDER_HPP_

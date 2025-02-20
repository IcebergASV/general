// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from comp_tasks_interfaces:action/TaskSignal.idl
// generated code does not contain a copyright notice

#ifndef COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__STRUCT_HPP_
#define COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'task'
#include "comp_tasks_interfaces/msg/detail/task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Goal __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Goal __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_Goal_
{
  using Type = TaskSignal_Goal_<ContainerAllocator>;

  explicit TaskSignal_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task(_init)
  {
    (void)_init;
  }

  explicit TaskSignal_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _task_type =
    comp_tasks_interfaces::msg::Task_<ContainerAllocator>;
  _task_type task;

  // setters for named parameter idiom
  Type & set__task(
    const comp_tasks_interfaces::msg::Task_<ContainerAllocator> & _arg)
  {
    this->task = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Goal
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Goal
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_Goal_ & other) const
  {
    if (this->task != other.task) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_Goal_

// alias to use template instance with default allocator
using TaskSignal_Goal =
  comp_tasks_interfaces::action::TaskSignal_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces


#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Result __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Result __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_Result_
{
  using Type = TaskSignal_Result_<ContainerAllocator>;

  explicit TaskSignal_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
    }
  }

  explicit TaskSignal_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
    }
  }

  // field types and members
  using _status_type =
    int32_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Result
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Result
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_Result_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_Result_

// alias to use template instance with default allocator
using TaskSignal_Result =
  comp_tasks_interfaces::action::TaskSignal_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces


#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Feedback __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_Feedback_
{
  using Type = TaskSignal_Feedback_<ContainerAllocator>;

  explicit TaskSignal_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_complete = false;
    }
  }

  explicit TaskSignal_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_complete = false;
    }
  }

  // field types and members
  using _task_complete_type =
    bool;
  _task_complete_type task_complete;

  // setters for named parameter idiom
  Type & set__task_complete(
    const bool & _arg)
  {
    this->task_complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Feedback
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_Feedback
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_Feedback_ & other) const
  {
    if (this->task_complete != other.task_complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_Feedback_

// alias to use template instance with default allocator
using TaskSignal_Feedback =
  comp_tasks_interfaces::action::TaskSignal_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "comp_tasks_interfaces/action/detail/task_signal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Request __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_SendGoal_Request_
{
  using Type = TaskSignal_SendGoal_Request_<ContainerAllocator>;

  explicit TaskSignal_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit TaskSignal_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const comp_tasks_interfaces::action::TaskSignal_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Request
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Request
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_SendGoal_Request_

// alias to use template instance with default allocator
using TaskSignal_SendGoal_Request =
  comp_tasks_interfaces::action::TaskSignal_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Response __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_SendGoal_Response_
{
  using Type = TaskSignal_SendGoal_Response_<ContainerAllocator>;

  explicit TaskSignal_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit TaskSignal_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Response
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_SendGoal_Response
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_SendGoal_Response_

// alias to use template instance with default allocator
using TaskSignal_SendGoal_Response =
  comp_tasks_interfaces::action::TaskSignal_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace comp_tasks_interfaces
{

namespace action
{

struct TaskSignal_SendGoal
{
  using Request = comp_tasks_interfaces::action::TaskSignal_SendGoal_Request;
  using Response = comp_tasks_interfaces::action::TaskSignal_SendGoal_Response;
};

}  // namespace action

}  // namespace comp_tasks_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Request __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_GetResult_Request_
{
  using Type = TaskSignal_GetResult_Request_<ContainerAllocator>;

  explicit TaskSignal_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit TaskSignal_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Request
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Request
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_GetResult_Request_

// alias to use template instance with default allocator
using TaskSignal_GetResult_Request =
  comp_tasks_interfaces::action::TaskSignal_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Response __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_GetResult_Response_
{
  using Type = TaskSignal_GetResult_Response_<ContainerAllocator>;

  explicit TaskSignal_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit TaskSignal_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const comp_tasks_interfaces::action::TaskSignal_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Response
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_GetResult_Response
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_GetResult_Response_

// alias to use template instance with default allocator
using TaskSignal_GetResult_Response =
  comp_tasks_interfaces::action::TaskSignal_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces

namespace comp_tasks_interfaces
{

namespace action
{

struct TaskSignal_GetResult
{
  using Request = comp_tasks_interfaces::action::TaskSignal_GetResult_Request;
  using Response = comp_tasks_interfaces::action::TaskSignal_GetResult_Response;
};

}  // namespace action

}  // namespace comp_tasks_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "comp_tasks_interfaces/action/detail/task_signal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__comp_tasks_interfaces__action__TaskSignal_FeedbackMessage __declspec(deprecated)
#endif

namespace comp_tasks_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskSignal_FeedbackMessage_
{
  using Type = TaskSignal_FeedbackMessage_<ContainerAllocator>;

  explicit TaskSignal_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit TaskSignal_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const comp_tasks_interfaces::action::TaskSignal_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_FeedbackMessage
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__comp_tasks_interfaces__action__TaskSignal_FeedbackMessage
    std::shared_ptr<comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSignal_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSignal_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSignal_FeedbackMessage_

// alias to use template instance with default allocator
using TaskSignal_FeedbackMessage =
  comp_tasks_interfaces::action::TaskSignal_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace comp_tasks_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace comp_tasks_interfaces
{

namespace action
{

struct TaskSignal
{
  /// The goal message defined in the action definition.
  using Goal = comp_tasks_interfaces::action::TaskSignal_Goal;
  /// The result message defined in the action definition.
  using Result = comp_tasks_interfaces::action::TaskSignal_Result;
  /// The feedback message defined in the action definition.
  using Feedback = comp_tasks_interfaces::action::TaskSignal_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = comp_tasks_interfaces::action::TaskSignal_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = comp_tasks_interfaces::action::TaskSignal_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = comp_tasks_interfaces::action::TaskSignal_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct TaskSignal TaskSignal;

}  // namespace action

}  // namespace comp_tasks_interfaces

#endif  // COMP_TASKS_INTERFACES__ACTION__DETAIL__TASK_SIGNAL__STRUCT_HPP_

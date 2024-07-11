// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coordinate_class_id
{
public:
  explicit Init_Coordinate_class_id(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  ::perception_interfaces::msg::Coordinate class_id(::perception_interfaces::msg::Coordinate::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_probability
{
public:
  explicit Init_Coordinate_probability(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_class_id probability(::perception_interfaces::msg::Coordinate::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return Init_Coordinate_class_id(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_id
{
public:
  explicit Init_Coordinate_id(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_probability id(::perception_interfaces::msg::Coordinate::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Coordinate_probability(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_ymax
{
public:
  explicit Init_Coordinate_ymax(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_id ymax(::perception_interfaces::msg::Coordinate::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_Coordinate_id(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_xmax
{
public:
  explicit Init_Coordinate_xmax(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_ymax xmax(::perception_interfaces::msg::Coordinate::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_Coordinate_ymax(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_ymin
{
public:
  explicit Init_Coordinate_ymin(::perception_interfaces::msg::Coordinate & msg)
  : msg_(msg)
  {}
  Init_Coordinate_xmax ymin(::perception_interfaces::msg::Coordinate::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_Coordinate_xmax(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

class Init_Coordinate_xmin
{
public:
  Init_Coordinate_xmin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinate_ymin xmin(::perception_interfaces::msg::Coordinate::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_Coordinate_ymin(msg_);
  }

private:
  ::perception_interfaces::msg::Coordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::Coordinate>()
{
  return perception_interfaces::msg::builder::Init_Coordinate_xmin();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__COORDINATE__BUILDER_HPP_

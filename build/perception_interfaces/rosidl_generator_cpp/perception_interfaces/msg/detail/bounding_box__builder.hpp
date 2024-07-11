// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_class_id
{
public:
  explicit Init_BoundingBox_class_id(::perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::perception_interfaces::msg::BoundingBox class_id(::perception_interfaces::msg::BoundingBox::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_probability
{
public:
  explicit Init_BoundingBox_probability(::perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_class_id probability(::perception_interfaces::msg::BoundingBox::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return Init_BoundingBox_class_id(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_id
{
public:
  explicit Init_BoundingBox_id(::perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_probability id(::perception_interfaces::msg::BoundingBox::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_BoundingBox_probability(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_ymax
{
public:
  explicit Init_BoundingBox_ymax(::perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_id ymax(::perception_interfaces::msg::BoundingBox::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_BoundingBox_id(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_xmax
{
public:
  explicit Init_BoundingBox_xmax(::perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_ymax xmax(::perception_interfaces::msg::BoundingBox::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_BoundingBox_ymax(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_ymin
{
public:
  explicit Init_BoundingBox_ymin(::perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_xmax ymin(::perception_interfaces::msg::BoundingBox::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_BoundingBox_xmax(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_xmin
{
public:
  Init_BoundingBox_xmin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_ymin xmin(::perception_interfaces::msg::BoundingBox::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_BoundingBox_ymin(msg_);
  }

private:
  ::perception_interfaces::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::BoundingBox>()
{
  return perception_interfaces::msg::builder::Init_BoundingBox_xmin();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

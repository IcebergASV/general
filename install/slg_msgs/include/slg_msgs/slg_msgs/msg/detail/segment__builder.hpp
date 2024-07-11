// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slg_msgs:msg/Segment.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT__BUILDER_HPP_
#define SLG_MSGS__MSG__DETAIL__SEGMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slg_msgs/msg/detail/segment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slg_msgs
{

namespace msg
{

namespace builder
{

class Init_Segment_points
{
public:
  explicit Init_Segment_points(::slg_msgs::msg::Segment & msg)
  : msg_(msg)
  {}
  ::slg_msgs::msg::Segment points(::slg_msgs::msg::Segment::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slg_msgs::msg::Segment msg_;
};

class Init_Segment_first_point_next_segment
{
public:
  explicit Init_Segment_first_point_next_segment(::slg_msgs::msg::Segment & msg)
  : msg_(msg)
  {}
  Init_Segment_points first_point_next_segment(::slg_msgs::msg::Segment::_first_point_next_segment_type arg)
  {
    msg_.first_point_next_segment = std::move(arg);
    return Init_Segment_points(msg_);
  }

private:
  ::slg_msgs::msg::Segment msg_;
};

class Init_Segment_last_point_prior_segment
{
public:
  explicit Init_Segment_last_point_prior_segment(::slg_msgs::msg::Segment & msg)
  : msg_(msg)
  {}
  Init_Segment_first_point_next_segment last_point_prior_segment(::slg_msgs::msg::Segment::_last_point_prior_segment_type arg)
  {
    msg_.last_point_prior_segment = std::move(arg);
    return Init_Segment_first_point_next_segment(msg_);
  }

private:
  ::slg_msgs::msg::Segment msg_;
};

class Init_Segment_angular_distance
{
public:
  explicit Init_Segment_angular_distance(::slg_msgs::msg::Segment & msg)
  : msg_(msg)
  {}
  Init_Segment_last_point_prior_segment angular_distance(::slg_msgs::msg::Segment::_angular_distance_type arg)
  {
    msg_.angular_distance = std::move(arg);
    return Init_Segment_last_point_prior_segment(msg_);
  }

private:
  ::slg_msgs::msg::Segment msg_;
};

class Init_Segment_label
{
public:
  explicit Init_Segment_label(::slg_msgs::msg::Segment & msg)
  : msg_(msg)
  {}
  Init_Segment_angular_distance label(::slg_msgs::msg::Segment::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Segment_angular_distance(msg_);
  }

private:
  ::slg_msgs::msg::Segment msg_;
};

class Init_Segment_id
{
public:
  Init_Segment_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Segment_label id(::slg_msgs::msg::Segment::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Segment_label(msg_);
  }

private:
  ::slg_msgs::msg::Segment msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::slg_msgs::msg::Segment>()
{
  return slg_msgs::msg::builder::Init_Segment_id();
}

}  // namespace slg_msgs

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slg_msgs:msg/SegmentArray.idl
// generated code does not contain a copyright notice

#ifndef SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__BUILDER_HPP_
#define SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slg_msgs/msg/detail/segment_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slg_msgs
{

namespace msg
{

namespace builder
{

class Init_SegmentArray_segments
{
public:
  explicit Init_SegmentArray_segments(::slg_msgs::msg::SegmentArray & msg)
  : msg_(msg)
  {}
  ::slg_msgs::msg::SegmentArray segments(::slg_msgs::msg::SegmentArray::_segments_type arg)
  {
    msg_.segments = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slg_msgs::msg::SegmentArray msg_;
};

class Init_SegmentArray_header
{
public:
  Init_SegmentArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentArray_segments header(::slg_msgs::msg::SegmentArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SegmentArray_segments(msg_);
  }

private:
  ::slg_msgs::msg::SegmentArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::slg_msgs::msg::SegmentArray>()
{
  return slg_msgs::msg::builder::Init_SegmentArray_header();
}

}  // namespace slg_msgs

#endif  // SLG_MSGS__MSG__DETAIL__SEGMENT_ARRAY__BUILDER_HPP_

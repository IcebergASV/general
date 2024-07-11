// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_interfaces:msg/LidarDetectedPropArray.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP_ARRAY__BUILDER_HPP_
#define PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_interfaces/msg/detail/lidar_detected_prop_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_LidarDetectedPropArray_lidar_detected_props
{
public:
  Init_LidarDetectedPropArray_lidar_detected_props()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::perception_interfaces::msg::LidarDetectedPropArray lidar_detected_props(::perception_interfaces::msg::LidarDetectedPropArray::_lidar_detected_props_type arg)
  {
    msg_.lidar_detected_props = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_interfaces::msg::LidarDetectedPropArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_interfaces::msg::LidarDetectedPropArray>()
{
  return perception_interfaces::msg::builder::Init_LidarDetectedPropArray_lidar_detected_props();
}

}  // namespace perception_interfaces

#endif  // PERCEPTION_INTERFACES__MSG__DETAIL__LIDAR_DETECTED_PROP_ARRAY__BUILDER_HPP_

#include "perception/coord_finder_component.h"

namespace perception
{

  CoordFinder::CoordFinder(const rclcpp::NodeOptions & options)
  : Node("coord_finder", options)
  {
    sub_ = this->create_subscription<perception_interfaces::msg::LidarDetectedPropArray>("segments", 10, std::bind(&CoordFinder::scanCallback, this, _1));
   // pub_ = this->create_publisher<perception_interfaces::msg::LidarDetectedPropArray>("perception/lidar_detected_props", 10);

    CoordFinder::getParam<double>("max_lidar_dist", p_max_lidar_dist_, 0.0, "Maximum accepted range of lidar readings in m");
    CoordFinder::getParam<double>("min_lidar_dist", p_min_lidar_dist_, 0.0, "Minimum accepted range of lidar readings in m");
    CoordFinder::getParam<int>("min_points_in_segment", p_min_points_in_segment_, 0, "Minimum accepted points in a laser_segment");
    CoordFinder::getParam<double>("max_radius_diff", p_max_radius_diff_, 0.0, "Maximum difference between measured and expected prop radii to consider a laser_segment a prop, in m");
    CoordFinder::getParam<double>("lidar_fov", p_lidar_fov_, 0.0, "Lidar fov in degrees");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&CoordFinder::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult CoordFinder::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "min_lidar_dist") { p_min_lidar_dist_ = params[0].as_double(); }
    else if (params[0].get_name() == "max_lidar_dist") { p_max_lidar_dist_ = params[0].as_double(); }
    else if (params[0].get_name() == "min_points_in_segment") { p_min_points_in_segment_ = params[0].as_int(); }
    else if (params[0].get_name() == "max_radius_diff") { p_max_radius_diff_ = params[0].as_double(); }
    else if (params[0].get_name() == "lidar_fov") { p_lidar_fov_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void CoordFinder::scanCallback(const perception_interfaces::msg::LidarDetectedPropArray::SharedPtr msg)
  {
    if (msg->lidar_detected_props.size() > 0)
    {
    }
    else
    {
      RCLCPP_WARN(this->get_logger(), "No segments in message");
    }
  }

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::CoordFinder)
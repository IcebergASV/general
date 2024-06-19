#include "perception/lidar_prop_detector_component.hpp"

#include "perception/lib/lidar_calculations.hpp" // TODO figure out why this can't go in header file

namespace perception
{

  LidarPropDetector::LidarPropDetector(const rclcpp::NodeOptions & options)
  : Node("lidar_prop_detector", options)
  {
    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarPropDetector::scanCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::LidarDetectedPropArray>("perception/lidar_detected_props", 10);

    LidarPropDetector::getParam<double>("max_lidar_dist", p_max_lidar_dist_, 0.0, "Maximum accepted range of lidar readings in m");
    LidarPropDetector::getParam<double>("min_lidar_dist", p_min_lidar_dist_, 0.0, "Minimum accepted range of lidar readings in m");
    LidarPropDetector::getParam<int>("min_points_in_segment", p_min_points_in_segment_, 0, "Minimum accepted points in a laser_segment");
    LidarPropDetector::getParam<double>("max_radius_diff", p_max_radius_diff_, 0.0, "Maximum difference between measured and expected prop radii to consider a laser_segment a prop, in m");
    LidarPropDetector::getStringParamConvertToMap<double>("props_radii", p_prop_radii_, "{}", "List of prop radii in m");
    LidarPropDetector::getParam<double>("lidar_fov", p_lidar_fov_, 0.0, "Lidar fov in degrees");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&LidarPropDetector::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult LidarPropDetector::param_callback(const std::vector<rclcpp::Parameter> &params)
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

  void LidarPropDetector::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    if (msg->segments.size() > 0)
    {
      perception_interfaces::msg::LidarDetectedPropArray lidar_detected_prop_array;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        std::vector<geometry_msgs::msg::Point> filtered_points = lidar_calculations::getPointsWithinBounds(segment.points, p_min_lidar_dist_, p_max_lidar_dist_, p_lidar_fov_);

        if (lidar_calculations::hasEnoughPoints(filtered_points.size(), p_min_points_in_segment_))
        {
          attemptToCreateAndAddLidarDetectedProp(filtered_points, lidar_detected_prop_array);
        }
      }
      if (lidar_detected_prop_array.lidar_detected_props.size() > 0)
      {
        pub_->publish(lidar_detected_prop_array);
      }
    }
    else
    {
      RCLCPP_WARN(this->get_logger(), "No segments in message");
    }
  }

  void LidarPropDetector::attemptToCreateAndAddLidarDetectedProp(std::vector<geometry_msgs::msg::Point> points, perception_interfaces::msg::LidarDetectedPropArray& lidar_detected_prop_array)
  {
    perception_interfaces::msg::LidarDetectedProp lidar_detected_prop = createLidarDetectedProp(points);
    if (measuredRadiusIsCloseToExpected(lidar_detected_prop.radius_diff))
    {
      lidar_detected_prop_array.lidar_detected_props.push_back(lidar_detected_prop);
    }
    else
    {
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 10000, "Calculated radius diff of %f is too large, should be less than %f to be considered a prop", lidar_detected_prop.radius_diff, p_max_radius_diff_);
    }
  }

  perception_interfaces::msg::LidarDetectedProp LidarPropDetector::createLidarDetectedProp(std::vector<geometry_msgs::msg::Point> points)
  {
    perception_interfaces::msg::LidarDetectedProp prop;
    lidar_calculations::calculateRadius(points, prop);
    this->findClosestMatchAndSetRadiusDiff(prop);
    return prop;
  }

  bool LidarPropDetector::measuredRadiusIsCloseToExpected(double radius_diff)
  {
    return radius_diff < p_max_radius_diff_;
  }
  
  void LidarPropDetector::findClosestMatchAndSetRadiusDiff(perception_interfaces::msg::LidarDetectedProp& prop)
  {
    double abs_closest_match_diff = std::numeric_limits<double>::max();
    double closest_match_diff = 0;
    std::string closest_match = "";
    for (const auto& pair : this->p_prop_radii_) {
        double diff = std::abs(prop.radius - pair.second);
        if (diff < abs_closest_match_diff){
            abs_closest_match_diff = diff;
            closest_match_diff = prop.radius - pair.second;
            closest_match = pair.first;
        }
    }
    prop.label = closest_match;
    prop.radius_diff = closest_match_diff;
    return;
  }
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarPropDetector)
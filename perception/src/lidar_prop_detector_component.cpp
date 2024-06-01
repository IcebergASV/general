#include "perception/lidar_prop_detector_component.hpp"

#include "perception/lib/lidar_calculations.hpp" // TODO figure out why this can't go in header file

namespace perception
{
  LidarPropDetector::LidarPropDetector(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {
    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarPropDetector::scanCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::LidarDetectedPropArray>("perception/lidar_detected_props", 10);

    LidarPropDetector::getParam<double>("max_lidar_dist", p_max_lidar_dist_, 0.0, "Maximum accepted range of lidar readings in m");
    LidarPropDetector::getParam<double>("min_lidar_dist", p_min_lidar_dist_, 0.0, "Minimum accepted range of lidar readings in m");
    LidarPropDetector::getParam<int>("min_points_in_segment", p_min_points_in_segment_, 0, "Minimum accepted points in a laser_segment");
    LidarPropDetector::getParam<double>("max_radius_diff", p_max_radius_diff_, 0.0, "Maximum difference between measured and expected prop radii to consider a laser_segment a prop, in m");
    LidarPropDetector::getStringParamConvertToMap<double>("props_radii", p_prop_radii_, "{}", "List of prop radii in m");
  }

  void LidarPropDetector::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    if (msg->segments.size() > 0)
    {
      perception_interfaces::msg::LidarDetectedPropArray lidar_detected_prop_array;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          attemptToCreateAndAddLidarDetectedProp(segment.points, lidar_detected_prop_array);
        }
      }
      if (lidar_detected_prop_array.lidar_detected_props.size() > 0)
      {
        pub_->publish(lidar_detected_prop_array);
      }
    }
    else
    {
      RCLCPP_DEBUG(this->get_logger(), "No segments detected");
    }
  }

  bool LidarPropDetector::isSegmentValid(slg_msgs::msg::Segment segment)
  {
    return lidar_calculations::hasEnoughPoints(segment.points.size(), p_min_points_in_segment_) && lidar_calculations::arePointsValidDistanceAway(segment.points, p_min_lidar_dist_, p_max_lidar_dist_);
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
      RCLCPP_ERROR(this->get_logger(), "Calculated radius diff of %f is too large, should be less than %f to be considered a prop", lidar_detected_prop.radius_diff, p_max_radius_diff_);
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
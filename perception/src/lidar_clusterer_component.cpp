#include "perception/lidar_clusterer_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"


using namespace std::chrono_literals;

namespace perception
{
  LidarClusterer::LidarClusterer(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {

    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarClusterer::scanCallback, this, _1));
    pub_ = this->create_publisher<perception::msg::BoundingCircleArray>("lidar_bounding_circles", 10);

    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{}; //todo add callback
    param_desc.description = "Sets the expected radii for props";
    this->declare_parameter<std::map<std::string, double>>("prop_radii", param_desc);

    std::map<std::string, double>> prop_radii;
    this->get_parameter("prop_radii", prop_radii);
  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "help '%f'", msg->segments[0].points[0].x);

    if (msg->segments.length > 0)
    {
      perception::msg::BoundingCircleArray bounding_circles;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          perception::msg::BoundingCircle bounding_circle = createBoundingCircle(segment.points);
          if (bounding_circle.probability > min_bounding_circle_probability) //todo make param
          {
            bounding_circles.push_back(bounding_circle);
          }
        }
      }
      if (bounding_circles.length > 0)
      {
        pub_->publish(bounding_circles);
      }
    }
    else
    {
      RCLCPP_DEBUG(this->get_logger(), "No segments detected");
    }
  }

  bool LidarClusterer::isSegmentValid(Segment segment)
  {
    return hasEnoughPoints(segment.points) && arePointsValidDistanceAway(segment.points);
  }

  perception::msg::BoundingCircle createBoundingCircle(std::vector<geometrymsgs::point> points)
  {
    perception::msg::BoundingCircle circle;
    circle.radius = calculateRadius(points);
    circle.center = calculateCenter(points);
    circle.label = findLabel(circle.radius);
    circle.probability = calculateProbability(circle.radius);
    return circle;
  }

  float calculateRadius(std::vector<geometrymsgs::point> points)
  {
    // todo
    return 1;
  }

  geometry_msgs::msg::point calculateRadius(std::vector<geometrymsgs::point> points)
  {
    // todo
    geometry_msgs::msg::point p;
    p.x = 1;
    p.y = 2;
    p.z = 3;
    return 
  }

  std::string findLabel(float radius)
  {
    double closest_radius_diff = std::numeric_limits<double>::max();
    std::string closest_prop;
    for (const auto& pair : props_radii_) {
        double diff = std::abs(radius - pair.second);
        if (diff < closest_radius_diff) {
            closest_radius_diff = diff;
            closest_option = pair.first;
        }
    }
  }


  bool LidarClusterer::hasEnoughPoints(Point[] points)
  {
    int min_points = 5; //make a param later
    return segment.point.length > min_points;
    // TODO add debugging if false
  }

  bool arePointsValidDistanceAway(Points[] points)
  {
    //TODO - add debugging if false
    return true;
  }

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarClusterer)
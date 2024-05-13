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
   // pub_ = this->create_publisher<perception::msg::BoundingCircleArray>("lidar_bounding_circles", 10);

    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{}; //todo add callback
    param_desc.description = "Sets the expected radii for props";
    this->declare_parameter<std::map<std::string, double>>("prop_radii", param_desc);

    std::map<std::string, double> prop_radii;
    if (!this->get_parameter("prop_radii", prop_radii)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to retrieve prop_radii parameter");
        // Handle the error case here, such as setting default values
        prop_radii["default_key"] = 0.0;
    }
  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "help '%f'", msg->segments[0].points[0].x);

    if (msg->segments.length > 0)
    {
      //perception::msg::BoundingCircleArray bounding_circles;
      //for (slg_msgs::msg::Segment segment : msg->segments)
      //{
      //  if (isSegmentValid(segment))
      //  {
      //    perception::msg::BoundingCircle bounding_circle = createBoundingCircle(segment.points);
      //    if (bounding_circle.probability > min_bounding_circle_probability) //todo make param
      //    {
      //      bounding_circles.push_back(bounding_circle);
      //    }
      //  }
      //}
      //if (bounding_circles.length > 0)
      //{
      //  pub_->publish(bounding_circles);
      //}
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

  //perception::msg::BoundingCircle createBoundingCircle(std::vector<geometrymsgs::point> points)
  //{
  //  perception::msg::BoundingCircle circle;
  //  calculateRadius(points, circle);
  //  findClosestMatch(circle);
  //  return circle;
  //}

  // Best fit circle equation: (x − k)^2 + (y − m)^2 = r^2
  // Where (k,m) is the center, and r is the radius
  // Based off of https://goodcalculators.com/best-fit-circle-least-squares-calculator/
  //
  // circle is an output param
  //void calculateRadius(std::vector<geometrymsgs::point> points, perception::msg::BoundingCircle& circle)
  //{
  //  std::vector<double> x_coords(points.size()) = extractCoordinates(std::vector<geometry_msgs::msg::Point> points, 'x');
  //  std::vector<double> y_coords(points.size()) = extractCoordinates(std::vector<geometry_msgs::msg::Point> points, 'y');
//
  //  for (size_t i = 0; i < points.size(); i++) {
  //      x_coords[i] = points[i].getDistance() * std::cos(points[i].getAngle());
  //      y_coords[i] = points[i].getDistance() * std::sin(points[i].getAngle());
  //  }const std::vector<geometry_msgs::msg::Point>& points
  //  
  //  // calculate matrix A
  //  Eigen::Matrix<double, 3, 3> matrixA;
  //  double mA_11, mA_12, mA_13, mA_21, mA_22, mA_23, mA_31, mA_32, mA_33 = 0;
  //  for (size_t i = 0; i < points.size(); i++) {
  //      mA_11 = mA_11 + pow(x_coords[i], 2);
  //      mA_12 = mA_12 + (x_coords[i]*y_coords[i]);
  //      mA_13 = mA_13 + x_coords[i];
  //      mA_22 = mA_22 + pow(y_coords[i], 2);
  //      mA_23 = mA_23 + y_coords[i];
  //  }
  //  mA_21 = mA_12;
  //  mA_31 = mA_13;
  //  mA_32 = mA_23;
  //  mA_33 = points.size();
//
  //  matrixA << mA_11, mA_12, mA_13, mA_21, mA_22, mA_23, mA_31, mA_32, mA_33;
//
  //  // calculate vector X
  //  Eigen::Matrix<double, 3, 1> vectorX;
  //  double vX_1, vX_2, vX_3 = 0;
  //  for (size_t i = 0; i < points.size(); i++) {
  //      vX_1 = vX_1 + x_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
  //      vX_2 = vX_2 + y_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
  //      vX_3 = vX_3 + (pow(x_coords[i], 2) + pow(y_coords[i], 2));
  //  }
//
  //  vectorX << vX_1, vX_2, vX_3;
//
  //  Eigen::Matrix<double, 3, 1> result = matrixA.colPivHouseholderQr().solve(vectorX.cast<double>());
//
  //  double a = result[0], b = result[1], c = result[3];
//
  //  double k = a / 2;
  //  double m = b / 2;
//
  //  circle.radius = (sqrt(4*c + pow(a, 2) + pow(b, 2))) / 2;
//
  //  circle.center.x = k;
  //  circle.center.y = m;
//
  //  return;
  //}
//
  std::vector<double> extractCoordinates(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract)
  {
    std::vector<double> x_or_y_coordinates;
    for (const auto& point : points) {
        coords_to_extract == 'x' ? x_or_y_coordinates.push_back(point.x) : x_or_y_coordinates.push_back(point.y);
    }
    return x_or_y_coordinates;
  }

  //void findClosestMatch(&perception::msg::BoundingCircle circle)
  //{
  //  double abs_closest_match_diff = std::numeric_limits<double>::max();
  //  double closest_match_diff = 0;
  //  std::string closest_match = '';
  //  for (const auto& pair : props_radii_) {
  //      double diff = std::abs(circle.radius - pair.second);
  //      if (diff < abs_closest_match_diff){
  //          abs_closest_match_diff = diff;
  //          closest_match_diff = circle.radius = pair.second;
  //          closest_match = pair.first;
  //      }
  //  }
  //  circle.label = closest_match;
  //  circle.radius_diff = closest_match_diff;
  //}


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
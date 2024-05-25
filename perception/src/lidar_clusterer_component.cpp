#include "perception/lidar_clusterer_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>
#include <yaml-cpp/yaml.h>

#include "rclcpp/rclcpp.hpp"

#include "perception/lib/lidar_calculations.hpp"
#include <string>
#include <sstream>

using namespace std::chrono_literals;

namespace perception
{
  std::string vectorToString(const std::vector<double>& vec) {
  std::ostringstream oss;
  oss << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    oss << vec[i];
    if (i != vec.size() - 1) {
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}

  bool LidarClusterer::arePointsValidDistanceAway(std::vector<geometry_msgs::msg::Point> points)
  {
    for (const auto& point : points) {
      double distance = std::sqrt(point.x * point.x + point.y * point.y);
      if (distance < p_min_lidar_dist_ || distance > p_max_lidar_dist_) 
      {
        RCLCPP_ERROR(this->get_logger(), "Points are not within lidar bounds of %f, to %f", p_min_lidar_dist_, p_max_lidar_dist_);
        return false;
      }
    }
    return true;
  }

  bool LidarClusterer::hasEnoughPoints(std::vector<geometry_msgs::msg::Point> points)
  {
    if (!(static_cast<int>(points.size()) >= p_min_points_in_segment_))
    {
      RCLCPP_ERROR(this->get_logger(), "Not enough points in segment. Requires at least %i, but only got %li.", p_min_points_in_segment_, points.size());
      return false;
    }
    return true;
  }
  bool LidarClusterer::isSegmentValid(slg_msgs::msg::Segment segment)
  {
    return hasEnoughPoints(segment.points) && this->arePointsValidDistanceAway(segment.points);
  }
  void LidarClusterer::findClosestMatch(perception_interfaces::msg::BoundingCircle& circle)
  {
    double abs_closest_match_diff = std::numeric_limits<double>::max();
    double closest_match_diff = 0;
    std::string closest_match = "";
    for (const auto& pair : this->p_prop_radii_) {
        double diff = std::abs(circle.radius - pair.second);
        if (diff < abs_closest_match_diff){
            abs_closest_match_diff = diff;
            closest_match_diff = circle.radius - pair.second;
            closest_match = pair.first;
        }
    }
    circle.label = closest_match;
    circle.radius_diff = closest_match_diff;
  }

  std::string matrixToString(const Eigen::Matrix<double, 3, 3>& matrix)
  {
    std::ostringstream oss;
    oss << matrix;
    return oss.str();
  }

  std::string matrixToString(const Eigen::Matrix<double, 3, 1>& matrix)
  {
    std::ostringstream oss;
    oss << matrix;
    return oss.str();
  }
    // Best fit circle equation: (x − k)^2 + (y − m)^2 = r^2
  // Where (k,m) is the center, and r is the radius
  // Based off of https://goodcalculators.com/best-fit-circle-least-squares-calculator/
  //
  // circle is an output param
  void LidarClusterer::calculateRadius(std::vector<geometry_msgs::msg::Point> points, perception_interfaces::msg::BoundingCircle& circle)
  {
    std::vector<double> x_coords = this->extractCoordinates(points, "x");
    std::vector<double> y_coords = this->extractCoordinates(points, "y");

    RCLCPP_INFO(this->get_logger(), " X Vector: %s", vectorToString(x_coords).c_str());
    RCLCPP_INFO(this->get_logger(), " Y Vector: %s", vectorToString(y_coords).c_str()); // same here


    if (!(x_coords.size() == y_coords.size()))
    {
      RCLCPP_ERROR(this->get_logger(), "X and Y coords don't match");
    }
    
    // calculate matrix A
    Eigen::Matrix<double, 3, 3> matrixA;
    double mA_11 = 0, mA_12 = 0, mA_13 = 0, mA_21 = 0, mA_22 = 0, mA_23 = 0, mA_31 = 0, mA_32 = 0, mA_33 = 0;
    for (size_t i = 0; i < x_coords.size(); i++) {
        mA_11 = mA_11 + pow(x_coords[i], 2);
        mA_12 = mA_12 + (x_coords[i]*y_coords[i]);
        mA_13 = mA_13 + x_coords[i];
        mA_22 = mA_22 + pow(y_coords[i], 2);
        mA_23 = mA_23 + y_coords[i];
    }

    mA_21 = mA_12;
    mA_31 = mA_13;
    mA_32 = mA_23;
    mA_33 = x_coords.size();

    matrixA << mA_11, mA_12, mA_13, mA_21, mA_22, mA_23, mA_31, mA_32, mA_33;

    std::string matrix_str = matrixToString(matrixA);
    RCLCPP_INFO(this->get_logger(), "matrixA:\n%s", matrix_str.c_str());

    // calculate vector X
    Eigen::Matrix<double, 3, 1> vectorX;
    double vX_1 = 0, vX_2 = 0, vX_3 = 0;
    for (size_t i = 0; i < x_coords.size(); i++) {
        vX_1 = vX_1 + x_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
        vX_2 = vX_2 + y_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
        vX_3 = vX_3 + (pow(x_coords[i], 2) + pow(y_coords[i], 2));
    }



    vectorX << vX_1, vX_2, vX_3;

    std::string matrix_str2 = matrixToString(vectorX);
    RCLCPP_INFO(this->get_logger(), "matrixX:\n%s", matrix_str2.c_str());

    Eigen::Matrix<double, 3, 1> result = matrixA.colPivHouseholderQr().solve(vectorX.cast<double>());

    //RCLCPP_INFO(this->get_logger(), "calced result");

    double a = result[0], b = result[1], c = result[2];

    double k = a / 2;
    double m = b / 2;

    circle.radius = (sqrt(4*c + pow(a, 2) + pow(b, 2))) / 2;

    circle.center.x = k;
    circle.center.y = m;

    RCLCPP_INFO(this->get_logger(), "Center: %f, %f, %f", result[0],  result[1], result[2]);

    return;
  }
  LidarClusterer::LidarClusterer(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {

    RCLCPP_ERROR(this->get_logger(), "ERROR message");
    RCLCPP_WARN(this->get_logger(), "WARN message");
    RCLCPP_INFO(this->get_logger(), "INFO message");
    RCLCPP_DEBUG(this->get_logger(), "DEBUG message");

    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarClusterer::scanCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::BoundingCircleArray>("lidar_bounding_circles", 10);

    // Declare and get the parameter as a string
    this->declare_parameter<double>("max_lidar_dist", 0.0);
    this->get_parameter("max_lidar_dist", p_max_lidar_dist_);
    RCLCPP_INFO(this->get_logger(), "max_lidar_dist: %f", p_max_lidar_dist_); 

    this->declare_parameter<double>("min_lidar_dist", 0.0);
    this->get_parameter("min_lidar_dist", p_min_lidar_dist_);
    RCLCPP_INFO(this->get_logger(), "min_lidar_dist: %f", p_min_lidar_dist_); 

    this->declare_parameter<int>("min_points_in_segment", 0);
    this->get_parameter("min_points_in_segment", p_min_points_in_segment_);
    RCLCPP_INFO(this->get_logger(), "min_points_in_segment: %i", p_min_points_in_segment_); 
    
    this->declare_parameter<double>("max_radius_diff", 0.0);
    this->get_parameter("max_radius_diff", p_max_radius_diff_);
    RCLCPP_INFO(this->get_logger(), "max_radius_diff: %f", p_max_radius_diff_); 

    this->declare_parameter<std::string>("props_radii", "{}");
    std::string map_string;
    this->get_parameter("props_radii", map_string);

        // Parse the YAML string into a std::map
    try
    {
      YAML::Node yaml_node = YAML::Load(map_string);
      for (YAML::const_iterator it = yaml_node.begin(); it != yaml_node.end(); ++it)
      {
        p_prop_radii_[it->first.as<std::string>()] = it->second.as<double>();
      }

      // Print the map to verify
      for (const auto &pair : p_prop_radii_)
      {
        RCLCPP_INFO(this->get_logger(), "Key: %s, Value: %f", pair.first.c_str(), pair.second);
      }
    }
    catch (const YAML::ParserException &e)
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to parse YAML: %s", e.what());
    }

    //this->declare_parameter<std::vector<std::string>>("props");
    //this->declare_parameter<std::vector<double>>("radii");
//
    //std::map<std::string, double> prop_radii;
    //std::vector<std::string> props;
    //std::vector<double> radii;
    //this->get_parameter("props", props);
    //this->get_parameter("radii", radii);
    //if (props.size() == radii.size())
    //{
    //  for (size_t i = 0; i < props.size(); ++i)
    //  {
    //    prop_radii[props[i]] = radii[i];
    //  }
    //}
    //else
    //{
    //  RCLCPP_ERROR(this->get_logger(), "Keys and values arrays have different sizes");
    //}
//
    //        p_prop_radii_ = {
    //        {"large_buoy", 1.0},
    //        {"small_buoy", 0.5},
    //        {"marker", 0.3}
    //    };
    //auto param_desc = rcl_interfaces::msg::ParameterDescriptor{}; //todo add callback
    //param_desc.description = "Sets the expected radii for props";
    //this->declare_parameter<std::map<std::string, double>>("prop_radii", default_map, param_desc);

    //double prop_radii; // TODO Change to map
    //if (!this->get_parameter("prop_radii", this->p_prop_radii_)) {
      //  RCLCPP_ERROR(this->get_logger(), "Failed to retrieve prop_radii parameter");
        // Handle the error case here, such as setting default values
       // prop_radii["default_key"] = 0.0;
       //this->p_prop_radii_ = default_map;
    //}
  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "help '%f'", msg->segments[0].points[0].x);

    if (msg->segments.size() > 0 && testFunction())
    {
      perception_interfaces::msg::BoundingCircleArray bounding_circle_array;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          perception_interfaces::msg::BoundingCircle bounding_circle = createBoundingCircle(segment.points);
          if (bounding_circle.radius_diff < p_max_radius_diff_)
          {
            bounding_circle_array.bounding_circles.push_back(bounding_circle);
          }
          else
          {
            RCLCPP_ERROR(this->get_logger(), "Calculated radius diff of %f is too large, should be less than %f to be considered a prop", bounding_circle.radius_diff, p_max_radius_diff_);
          }
        }
      }
      if (bounding_circle_array.bounding_circles.size() > 0)
      {
        pub_->publish(bounding_circle_array);
      }
    }
    else
    {
      RCLCPP_DEBUG(this->get_logger(), "No segments detected");
    }
  }



  perception_interfaces::msg::BoundingCircle LidarClusterer::createBoundingCircle(std::vector<geometry_msgs::msg::Point> points)
  {
    perception_interfaces::msg::BoundingCircle circle;
    calculateRadius(points, circle);
    this->findClosestMatch(circle);
    return circle;
  }



  std::vector<double> LidarClusterer::extractCoordinates(std::vector<geometry_msgs::msg::Point> points, std::string coords_to_extract)
  {
    std::vector<double> x_or_y_coordinates;
    for (const auto& point : points) {
        coords_to_extract == "x" ? x_or_y_coordinates.push_back(point.x) : x_or_y_coordinates.push_back(point.y);
    }
    return x_or_y_coordinates;
  }







}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::LidarClusterer)
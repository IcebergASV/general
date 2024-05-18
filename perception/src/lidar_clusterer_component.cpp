#include "perception/lidar_clusterer_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>
#include <yaml-cpp/yaml.h>

#include "rclcpp/rclcpp.hpp"


using namespace std::chrono_literals;

namespace perception
{

  bool LidarClusterer::arePointsValidDistanceAway(std::vector<geometry_msgs::msg::Point> points)
  {
    //TODO - add debugging if false
    RCLCPP_DEBUG(this->get_logger(), "hi %f",points[0].x);
    return true;
  }
  bool hasEnoughPoints(std::vector<geometry_msgs::msg::Point> points)
  {
    unsigned long min_points = 5; //make a param later
    return points.size() > min_points;
    // TODO add debugging if false
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
    for (const auto& pair : this->prop_radii_) {
        double diff = std::abs(circle.radius - pair.second);
        if (diff < abs_closest_match_diff){
            abs_closest_match_diff = diff;
            closest_match_diff = circle.radius = pair.second;
            closest_match = pair.first;
        }
    }
    circle.label = closest_match;
    circle.radius_diff = closest_match_diff;
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

    if (!(x_coords.size() == y_coords.size()))
    {
      RCLCPP_ERROR(this->get_logger(), "X and Y coords don't match");
    }
    
    // calculate matrix A
    Eigen::Matrix<double, 3, 3> matrixA;
    double mA_11, mA_12, mA_13, mA_21, mA_22, mA_23, mA_31, mA_32, mA_33 = 0;
    for (size_t i = 0; i < x_coords.size(); i++) {
        mA_11 = mA_11 + pow(x_coords[i], 2);
        mA_12 = mA_12 + (x_coords[i]*y_coords[i]);
        mA_13 = mA_13 + x_coords[i];
        mA_22 = mA_22 + pow(y_coords[i], 2);
        mA_23 = mA_23 + y_coords[i];
    }
    RCLCPP_INFO(this->get_logger(), "Done calculating A");
    mA_21 = mA_12;
    mA_31 = mA_13;
    mA_32 = mA_23;
    mA_33 = x_coords.size();

    matrixA << mA_11, mA_12, mA_13, mA_21, mA_22, mA_23, mA_31, mA_32, mA_33;

    // calculate vector X
    Eigen::Matrix<double, 3, 1> vectorX;
    double vX_1, vX_2, vX_3 = 0;
    for (size_t i = 0; i < x_coords.size(); i++) {
        vX_1 = vX_1 + x_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
        vX_2 = vX_2 + y_coords[i]*(pow(x_coords[i], 2) + pow(y_coords[i], 2));
        vX_3 = vX_3 + (pow(x_coords[i], 2) + pow(y_coords[i], 2));
    }

    RCLCPP_INFO(this->get_logger(), "Done with Vector X");

    vectorX << vX_1, vX_2, vX_3;

    Eigen::Matrix<double, 3, 1> result = matrixA.colPivHouseholderQr().solve(vectorX.cast<double>());

    RCLCPP_INFO(this->get_logger(), "calced result");

    double a = result[0], b = result[1], c = result[2];

    double k = a / 2;
    double m = b / 2;

    circle.radius = (sqrt(4*c + pow(a, 2) + pow(b, 2))) / 2;

    circle.center.x = k;
    circle.center.y = m;

    return;
  }
  LidarClusterer::LidarClusterer(const rclcpp::NodeOptions & options)
  : Node("lidar_clusterer", options)
  {

    sub_ = this->create_subscription<slg_msgs::msg::SegmentArray>("segments", 10, std::bind(&LidarClusterer::scanCallback, this, _1));
    pub_ = this->create_publisher<perception_interfaces::msg::BoundingCircleArray>("lidar_bounding_circles", 10);

    // Declare and get the parameter as a string
    this->declare_parameter<std::string>("props_radii", "{}");
    std::string map_string;
    this->get_parameter("props_radii", map_string);

        // Parse the YAML string into a std::map
    try
    {
      YAML::Node yaml_node = YAML::Load(map_string);
      for (YAML::const_iterator it = yaml_node.begin(); it != yaml_node.end(); ++it)
      {
        prop_radii_[it->first.as<std::string>()] = it->second.as<double>();
      }

      // Print the map to verify
      for (const auto &pair : prop_radii_)
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
    //        prop_radii_ = {
    //        {"large_buoy", 1.0},
    //        {"small_buoy", 0.5},
    //        {"marker", 0.3}
    //    };
    //auto param_desc = rcl_interfaces::msg::ParameterDescriptor{}; //todo add callback
    //param_desc.description = "Sets the expected radii for props";
    //this->declare_parameter<std::map<std::string, double>>("prop_radii", default_map, param_desc);

    //double prop_radii; // TODO Change to map
    //if (!this->get_parameter("prop_radii", this->prop_radii_)) {
      //  RCLCPP_ERROR(this->get_logger(), "Failed to retrieve prop_radii parameter");
        // Handle the error case here, such as setting default values
       // prop_radii["default_key"] = 0.0;
       //this->prop_radii_ = default_map;
    //}
  }

  void LidarClusterer::scanCallback(const slg_msgs::msg::SegmentArray::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "help '%f'", msg->segments[0].points[0].x);

    if (msg->segments.size() > 0)
    {
      perception_interfaces::msg::BoundingCircleArray bounding_circle_array;
      for (slg_msgs::msg::Segment segment : msg->segments)
      {
        if (isSegmentValid(segment))
        {
          perception_interfaces::msg::BoundingCircle bounding_circle = createBoundingCircle(segment.points);
          if (bounding_circle.radius_diff < 4) //todo make param
          {
            bounding_circle_array.bounding_circles.push_back(bounding_circle);
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
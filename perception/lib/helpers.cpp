#include "perception/lib/helpers.hpp"

namespace helpers
{

  std::string vectorToString(const std::vector<double>& vec) 
  {
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

  perception_interfaces::msg::Gate createGate(perception_interfaces::msg::Prop p1, perception_interfaces::msg::Prop p2)
  {
    perception_interfaces::msg::Gate gate;
    if (p1.label == "red_marker")
    {
      gate.red_marker = p1;
      gate.green_marker = p2;
    } 
    else 
    {
      gate.red_marker = p2;
      gate.green_marker = p1;
    }
    return gate;
  }

  double distTwoPoints(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    RCLCPP_INFO(logger, "prop 1: (%f,%f), prop 2: (%f,%f)", x1, y1, x2, y2);
    return std::sqrt(dx * dx + dy * dy);
  }


}

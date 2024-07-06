#include "perception/mock_coord_pub_component.hpp"

namespace perception
{

  MockCoordPub::MockCoordPub(const rclcpp::NodeOptions & options)
  : Node("mock_coord_pub", options)
  {
      timer_ = this->create_wall_timer(100ms, std::bind(&MockCoordPub::timer_callback, this));    
      pub_ = this->create_publisher<perception_interfaces::msg::Coordinates>("perception/mock_coord", 10);


  rcl_interfaces::msg::SetParametersResult MockCoordPub::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "xmin") { p_xmin_ = params[0].as_int(); }
    else if (params[0].get_name() == "xmax") { p_xmax_ = params[0].as_int(); }
    else if (params[0].get_name() == "ymin") { p_ymin_ = params[0].as_int(); }
    else if (params[0].get_name() == "ymax") { p_ymax_ = params[0].as_int(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void MockCoordPub::timer_callback()
  {
    //auto message = std_msgs::msg::String();
    perception_interfaces::msg::Coordinates coords;

    perception_interfaces::msg::Coordinates coords;
    coord.xmin = p_xmin_;
    coord.xmax = p_xmax_;
    coord.ymin = p_ymin_;
    coord.ymax = p_ymax_;
    coord.probability = 0.99;
    coord.class_id = "green_marker";

    coords.coordinates.push_back(coord);

    coord.xmin = 8;
    coord.xmax = 12;
    coord.ymin = 8;
    coord.ymax = 12;
    coord.probability = 0.99;
    coord.class_id = "red_marker";

    coords.coordinates.push_back(coord);


    pub_->publish(coords);
  }
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::MockCoordPub)
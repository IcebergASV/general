#include "perception/mock_bbox_pub_component.hpp"

namespace perception
{

  MockBBoxPub::MockBBoxPub(const rclcpp::NodeOptions & options)
  : Node("mock_bbox_pub", options)
  {
      timer_ = this->create_wall_timer(100ms, std::bind(&MockBBoxPub::timer_callback, this));    
      pub_ = this->create_publisher<perception_interfaces::msg::BoundingBoxes>("perception/mock_bboxes", 10);

    MockBBoxPub::getParam<int>("xmin", p_xmin_, 0, "minimum x value of bounding box");
    MockBBoxPub::getParam<int>("xmax", p_xmax_, 0, "maxiumum x value of bounding box");
    MockBBoxPub::getParam<int>("ymin", p_ymin_, 0, "minimum y value of bounding box");
    MockBBoxPub::getParam<int>("ymax", p_ymax_, 0, "maximum y value of bounding box");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&MockBBoxPub::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult MockBBoxPub::param_callback(const std::vector<rclcpp::Parameter> &params)
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

  void MockBBoxPub::timer_callback()
  {
    //auto message = std_msgs::msg::String();
    perception_interfaces::msg::BoundingBoxes boxes;

    perception_interfaces::msg::BoundingBox box;
    box.xmin = 20;
    box.xmax = 940;
    box.ymin = 30;
    box.ymax = 59;
    box.probability = 0.99;
    box.class_id = "green_marker";

    boxes.bounding_boxes.push_back(box);

    box.xmin = 980;
    box.xmax = 1900;
    box.ymin = 4;
    box.ymax = 10;
    box.probability = 0.99;
    box.class_id = "red_marker";

    boxes.bounding_boxes.push_back(box);


    pub_->publish(boxes);
  }
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(perception::MockBBoxPub)
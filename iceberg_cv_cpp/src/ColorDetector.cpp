#include "iceberg_cv_cpp/ColorDetector.hpp"

ColorDetector::ColorDetector() : Node("configurable_color_filter") {
    //Declare parameters
    this->declare_parameter("input_img_topic", "/camera/camera/color/image_raw");
    this->declare_parameter("output_img_topic", "/icebergcv/filtered_image");
    this->declare_parameter("output_det_topic", "/icebergcv/detections");
    this->declare_parameter("output_class_name", "red");
    this->declare_parameter("min_area", 75);
    this->declare_parameter("lower_hsv_list", std::vector<int64_t>{0, 100, 100, 160, 100, 100}); // Default for red
    this->declare_parameter("upper_hsv_list", std::vector<int64_t>{10, 255, 255, 180, 255, 255});

    //Get params from yaml files?
    this->getStringParam("input_img_topic", input_topic_, "/camera/camera/color/image_raw", "The input image topic to process.");
    this->getStringParam("output_img_topic", output_img_topic_, "/icebergcv/filtered_image", "The output topic for the processed image.");
    this->getStringParam("output_det_topic", output_det_topic_, "/icebergcv/detections", "The output topic for detections in the image.");
    this->getStringParam("output_class_name", class_name_, "red", "Class name the detecions should be output with.");
    this->getParam<int>("min_area", min_area_, 100,
        "The minimum area (amount of contigious pixels in contour) for a blob to be considered a detection");
    this->getParam<std::vector<int64_t>>("lower_hsv_list", p_frame_stack_size_, {0, 100, 100, 160, 100, 100},
        "Number of frames to stack before calculating angle");
    this->getParam<std::vector<int64_t>>("upper_hsv_list", p_frame_stack_size_, {10, 255, 255, 180, 255, 255},
        "Number of frames to stack before calculating angle");

    //Set up callback
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&ColorDetector::param_callback, this, std::placeholders::_1));


    //Get parameters
     = this->get_parameter("input_img_topic").as_string();
     = this->get_parameter("output_img_topic").as_string();
     = this->get_parameter("output_det_topic").as_string();
    class_name_ = this->get_parameter("output_class_name").as_string();
    min_area_ = this->get_parameter("min_area").as_int();

    //Get HSV values, groups of 3 in each
    auto lower_hsv = this->get_parameter("lower_hsv_list").as_integer_array();
    auto upper_hsv = this->get_parameter("upper_hsv_list").as_integer_array();

        //Validate parameters
    if (lower_hsv.size() % 3 != 0 || upper_hsv.size() % 3 != 0) {
        RCLCPP_ERROR(this->get_logger(), "HSV lists must contain triplets (H,S,V)");
        rclcpp::shutdown();
        return;
    }

    if (lower_hsv.size() != upper_hsv.size()) {
        RCLCPP_ERROR(this->get_logger(), "Lower and upper HSV lists must have equal number of elements");
        rclcpp::shutdown();
        return;
    }

    //Create HSV ranges
    for (size_t i = 0; i < lower_hsv.size(); i += 3) {
        cv::Vec3b lower(lower_hsv[i], lower_hsv[i+1], lower_hsv[i+2]);
        cv::Vec3b upper(upper_hsv[i], upper_hsv[i+1], upper_hsv[i+2]);
        hsv_ranges_.emplace_back(lower, upper);
    }

        //Create subscriber and publishers
    sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        input_topic_, 10, std::bind(&ColorDetector::image_callback, this, _1));

    img_pub_ = this->create_publisher<sensor_msgs::msg::Image>(output_img_topic_, 10);
    det_pub_ = this->create_publisher<yolov8_msgs::msg::DetectionArray>(output_det_topic_, 10);

    // Log initialization
    RCLCPP_INFO(this->get_logger(), "Color filter initialized with:\n"
            "Input topic: %s\nOutput topic: %s",
            input_topic_.c_str(), output_img_topic_.c_str());

    for (size_t i = 0; i < hsv_ranges_.size(); ++i) {
        RCLCPP_INFO(this->get_logger(), "HSV Range %zu: [%d,%d,%d] to [%d,%d,%d]", i,
            hsv_ranges_[i].first[0], hsv_ranges_[i].first[1], hsv_ranges_[i].first[2],
            hsv_ranges_[i].second[0], hsv_ranges_[i].second[1], hsv_ranges_[i].second[2]);
    }
}

//Gets string parameters
void getStringParam(std::string param_name, std::string& param, std::string default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<std::string>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      std::string param_log_output = param_name + ": " + param;
      RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 
      return;
}

//Color Detector parameter changing callback
rcl_interfaces::msg::SetParametersResult ColorDetector::param_callback(const std::vector<rclcpp::Parameter> &params) {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "input_img_topic") { p_distance_to_move_ = params[0].as_string(); updateYamlParam("distance_to_move", params[0].as_double());}
    else if (params[0].get_name() == "output_img_topic") { p_angle_from_target_ = params[0].as_string(); updateYamlParam("angle_from_target", params[0].as_double());}
    else if (params[0].get_name() == "output_det_topic") { p_camera_res_x_ = params[0].as_string(); updateYamlParam("camera_res_x", params[0].as_int());}
    else if (params[0].get_name() == "output_class_name") { p_camera_fov_ = params[0].as_string(); updateYamlParam("camera_fov", params[0].as_string());}
    else if (params[0].get_name() == "min_area") { p_finish_lat_ = params[0].as_double(); updateYamlParam("finish_lat", params[0].as_double());}
    else {
        result.successful = false;
        return result;
    }

    result.successful = true;
    return result;
}

//Main function, launches the node
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ColorDetector>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
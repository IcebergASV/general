#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <yolov8_msgs/msg/detection.hpp>
#include <yolov8_msgs/msg/detection_array.hpp>
#include <yolov8_msgs/msg/bounding_box2_d.hpp>
#include <vector>

using std::placeholders::_1;

class ColorDetector : public rclcpp::Node {
public:
    ColorDetector() : Node("configurable_color_filter") {
        
        ColorDetector::getStringParam("class_name", p_class_name_, "", "Class name");
        ColorDetector::getIntParam("min_area", p_min_area_, 1, "Minimum pixel area");
        ColorDetector::getIntParam("lower_hsv1", p_lower_hsv1_, -1, "Lower HSV 1");
        ColorDetector::getIntParam("lower_hsv2", p_lower_hsv2_, -1, "Lower HSV 2");
        ColorDetector::getIntParam("lower_hsv3", p_lower_hsv3_, -1, "Lower HSV 3");
        ColorDetector::getIntParam("lower_hsv4", p_lower_hsv4_, -1, "Lower HSV 4");
        ColorDetector::getIntParam("lower_hsv5", p_lower_hsv5_, -1, "Lower HSV 5");
        ColorDetector::getIntParam("lower_hsv6", p_lower_hsv6_, -1, "Lower HSV 6");
        ColorDetector::getIntParam("upper_hsv1", p_upper_hsv1_, -1, "Upper HSV 1");
        ColorDetector::getIntParam("upper_hsv2", p_upper_hsv2_, -1, "Upper HSV 2");
        ColorDetector::getIntParam("upper_hsv3", p_upper_hsv3_, -1, "Upper HSV 3");
        ColorDetector::getIntParam("upper_hsv4", p_upper_hsv4_, -1, "Upper HSV 4");
        ColorDetector::getIntParam("upper_hsv5", p_upper_hsv5_, -1, "Upper HSV 5");
        ColorDetector::getIntParam("upper_hsv6", p_upper_hsv6_, -1, "Upper HSV 6");
        on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&ColorDetector::param_callback, this, std::placeholders::_1));
        // Get parameters
        input_topic_ = "/camera/camera/color/image_raw";
        output_img_topic_ = "/icebergcv/filtered_image";
        output_det_topic_ = "/icebergcv/detections";

        setHSV();

        // Create subscriber and publishers
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
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params)
    {
      rcl_interfaces::msg::SetParametersResult result;
  
      if (params[0].get_name() == "class_name") { p_class_name_ = params[0].as_string(); } 
      else if (params[0].get_name() == "min_area") { p_min_area_ = params[0].as_int(); }
      else if (params[0].get_name() == "upper_hsv1") {p_upper_hsv1_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "upper_hsv2") {p_upper_hsv2_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "upper_hsv3") {p_upper_hsv3_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "upper_hsv4") {p_upper_hsv4_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "upper_hsv5") {p_upper_hsv5_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "upper_hsv6") {p_upper_hsv6_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "lower_hsv1") {p_lower_hsv1_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "lower_hsv2") {p_lower_hsv2_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "lower_hsv3") {p_lower_hsv3_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "lower_hsv4") {p_lower_hsv4_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "lower_hsv5") {p_lower_hsv5_ = params[0].as_int(); setHSV();}
      else if (params[0].get_name() == "lower_hsv6") {p_lower_hsv6_ = params[0].as_int(); setHSV();}
      else {


        RCLCPP_ERROR(this->get_logger(), "Invalid Param");
        result.successful = false;
        return result;
      }
  
      result.successful = true;
      return result;
    }


private:
    void getIntParam(std::string param_name, int& param, int default_value, std::string desc)
    {
        auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc.description = desc;
        this->declare_parameter<int>(param_name, default_value, param_desc);
        this->get_parameter(param_name, param);
        std::string param_log_output = param_name + ": " + std::to_string(param);
        RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

        return;
    }
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
    void getIntArrayParam(std::string param_name,  std::vector<long int> param, std::vector<long int> default_value, std::string desc)
    {
        auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc.description = desc;
        this->declare_parameter<std::vector<long int>>(param_name, default_value, param_desc);
        this->get_parameter(param_name, param);
        std::string param_log_output = param_name + ": [";
        for (const auto &val : param) {
            param_log_output += std::to_string(val) + ",";
        }
        param_log_output.pop_back(); // Remove the trailing comma
        param_log_output += "]";
        RCLCPP_INFO(this->get_logger(), param_log_output.c_str());
   
        return;
    }

    void populateLists()
    {
        // Clear the lists before populating them
        lower_hsv_list_.clear();
        upper_hsv_list_.clear();

        // Helper lambda function to add valid values
        auto add_if_valid = [](std::vector<int> &list, int value) {
            if (value >= 0) {
                list.emplace_back(value);
            }
        };

        // Populate the lower_hsv_list_
        add_if_valid(lower_hsv_list_, p_lower_hsv1_);
        add_if_valid(lower_hsv_list_, p_lower_hsv2_);
        add_if_valid(lower_hsv_list_, p_lower_hsv3_);
        add_if_valid(lower_hsv_list_, p_lower_hsv4_);
        add_if_valid(lower_hsv_list_, p_lower_hsv5_);
        add_if_valid(lower_hsv_list_, p_lower_hsv6_);

        // Populate the upper_hsv_list_
        add_if_valid(upper_hsv_list_, p_upper_hsv1_);
        add_if_valid(upper_hsv_list_, p_upper_hsv2_);
        add_if_valid(upper_hsv_list_, p_upper_hsv3_);
        add_if_valid(upper_hsv_list_, p_upper_hsv4_);
        add_if_valid(upper_hsv_list_, p_upper_hsv5_);
        add_if_valid(upper_hsv_list_, p_upper_hsv6_);

        RCLCPP_DEBUG(this->get_logger(), "upper size %ld", upper_hsv_list_.size());
        RCLCPP_DEBUG(this->get_logger(), "lower size %ld", lower_hsv_list_.size());
        for (size_t i = 0; i < upper_hsv_list_.size(); ++i) {
            RCLCPP_DEBUG(this->get_logger(), "upper_hsv_list_[%zu]: %d", i, upper_hsv_list_[i]);
        }
        for (size_t i = 0; i < lower_hsv_list_.size(); ++i) {
            RCLCPP_DEBUG(this->get_logger(), "upper_hsv_list_[%zu]: %d", i, lower_hsv_list_[i]);
        }
    }
    void setHSV()
    {
        populateLists();
        RCLCPP_DEBUG(this->get_logger(), "setHSV");
        // Validate parameters

        RCLCPP_DEBUG(this->get_logger(), "lower size %ld", lower_hsv_list_.size());
        RCLCPP_DEBUG(this->get_logger(), "upper size %ld", upper_hsv_list_.size());
        if (lower_hsv_list_.size() % 3 != 0 || upper_hsv_list_.size() % 3 != 0) {
            RCLCPP_ERROR(this->get_logger(), "HSV lists must contain triplets (H,S,V)");
            rclcpp::shutdown();
            return;
        }
        if (lower_hsv_list_.size() != upper_hsv_list_.size()) {
            RCLCPP_ERROR(this->get_logger(), "Lower and upper HSV lists must have equal number of elements");
            rclcpp::shutdown();
            return;
        }
        hsv_ranges_.clear();
        // Create HSV ranges
        for (size_t i = 0; i < lower_hsv_list_.size(); i += 3) {
            cv::Vec3b lower(lower_hsv_list_[i], lower_hsv_list_[i+1], lower_hsv_list_[i+2]);
            cv::Vec3b upper(upper_hsv_list_[i], upper_hsv_list_[i+1], upper_hsv_list_[i+2]);
            hsv_ranges_.emplace_back(lower, upper);
        }

        RCLCPP_DEBUG(this->get_logger(), "ranges size %ld", hsv_ranges_.size());

        for (size_t i=0; i < hsv_ranges_.size(); i++) {
            RCLCPP_INFO(this->get_logger(), "HSV Range %zu: [%d,%d,%d] to [%d,%d,%d]", i,
                        hsv_ranges_[i].first[0], hsv_ranges_[i].first[1], hsv_ranges_[i].first[2],
                        hsv_ranges_[i].second[0], hsv_ranges_[i].second[1], hsv_ranges_[i].second[2]);
        }
    }
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
        cv_bridge::CvImagePtr cv_ptr;
        try {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        } catch (const cv_bridge::Exception& e) {
            RCLCPP_ERROR(this->get_logger(), "CV bridge error: %s", e.what());
            return;
        }

        cv::Mat hsv;
        cv::cvtColor(cv_ptr->image, hsv, cv::COLOR_BGR2HSV);

        // Create combined mask from all HSV ranges
        cv::Mat mask = cv::Mat::zeros(hsv.size(), CV_8UC1);
        for (const auto& range : hsv_ranges_) {
            cv::Mat temp_mask;
            cv::inRange(hsv, range.first, range.second, temp_mask);
            cv::bitwise_or(mask, temp_mask, mask);
        }

        // Create filtered image
        cv::Mat gray, gray_bgr;
        cv::cvtColor(cv_ptr->image, gray, cv::COLOR_BGR2GRAY);
        cv::cvtColor(gray, gray_bgr, cv::COLOR_GRAY2BGR);

        cv::Mat filtered;
        cv::bitwise_and(cv_ptr->image, cv_ptr->image, filtered, mask);
        cv::bitwise_and(gray_bgr, gray_bgr, filtered, ~mask);
        filtered += gray_bgr;

        // Find contours and create detections
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        yolov8_msgs::msg::DetectionArray det_array;
        det_array.header = msg->header;

        for (const auto& contour : contours) {
            if (cv::contourArea(contour) > p_min_area_) {
                cv::Rect rect = cv::boundingRect(contour);

                cv::rectangle(filtered, rect, cv::Scalar(0, 255, 0), 2);
                RCLCPP_DEBUG(this->get_logger(), "Detected object at (%d,%d) with size %d, %d",
                            rect.x, rect.y, rect.width, rect.height);
                yolov8_msgs::msg::BoundingBox2D bbox;
                bbox.center.position.x = rect.x + rect.width / 2.0;  // Center X
                bbox.center.position.y = rect.y + rect.height / 2.0; // Center Y
                bbox.size.x = rect.width;  // Width of the bounding box
                bbox.size.y = rect.height; // Height of the bounding box

                yolov8_msgs::msg::Detection det;
                det.class_id = 100;
                det.class_name = p_class_name_;
                det.score = 1.0;
                det.bbox = bbox;

                det_array.detections.push_back(det);
            }
        }

        // Publish results
        try {
            auto filtered_msg = cv_bridge::CvImage(msg->header, "bgr8", filtered).toImageMsg();
            img_pub_->publish(*filtered_msg);
            det_pub_->publish(det_array);
        } catch (const cv_bridge::Exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Publishing error: %s", e.what());
        }
    }

    // Member variables
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr img_pub_;
    rclcpp::Publisher<yolov8_msgs::msg::DetectionArray>::SharedPtr det_pub_;

    std::vector<std::pair<cv::Vec3b, cv::Vec3b>> hsv_ranges_;
    std::string input_topic_;
    std::string output_img_topic_;
    std::string output_det_topic_;
    int p_min_area_;
    std::string p_class_name_;
    std::vector<int> lower_hsv_list_;
    std::vector<int> upper_hsv_list_;
    int p_lower_hsv1_;
    int p_lower_hsv2_;
    int p_lower_hsv3_;
    int p_lower_hsv4_;
    int p_lower_hsv5_;
    int p_lower_hsv6_;
    int p_upper_hsv1_;
    int p_upper_hsv2_;
    int p_upper_hsv3_;
    int p_upper_hsv4_;
    int p_upper_hsv5_;
    int p_upper_hsv6_;



    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ColorDetector>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
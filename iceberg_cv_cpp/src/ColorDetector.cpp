#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <yolov8_msgs/msg/detection.hpp>
#include <yolov8_msgs/msg/detection_array.hpp>
#include <yolov8_msgs/msg/bounding_box2_d.hpp>

using std::placeholders::_1;

class ColorDetector : public rclcpp::Node {
public:
    ColorDetector() : Node("configurable_color_filter") {
        // Declare parameters
        this->declare_parameter("input_img_topic", "/camera/camera/color/image_raw");
        this->declare_parameter("output_img_topic", "/icebergcv/filtered_image");
        this->declare_parameter("output_det_topic", "/icebergcv/detections");
        this->declare_parameter("output_class_name", "red");
        this->declare_parameter("min_area", 75);
        this->declare_parameter("lower_hsv_list", std::vector<int64_t>{0, 100, 100, 160, 100, 100}); // Default for red
        this->declare_parameter("upper_hsv_list", std::vector<int64_t>{10, 255, 255, 180, 255, 255});

        // Get parameters
        input_topic_ = this->get_parameter("input_img_topic").as_string();
        output_img_topic_ = this->get_parameter("output_img_topic").as_string();
        output_det_topic_ = this->get_parameter("output_det_topic").as_string();
        class_name_ = this->get_parameter("output_class_name").as_string();
        min_area_ = this->get_parameter("min_area").as_int();

        auto lower_hsv = this->get_parameter("lower_hsv_list").as_integer_array();
        auto upper_hsv = this->get_parameter("upper_hsv_list").as_integer_array();

        // Validate parameters
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

        // Create HSV ranges
        for (size_t i = 0; i < lower_hsv.size(); i += 3) {
            cv::Vec3b lower(lower_hsv[i], lower_hsv[i+1], lower_hsv[i+2]);
            cv::Vec3b upper(upper_hsv[i], upper_hsv[i+1], upper_hsv[i+2]);
            hsv_ranges_.emplace_back(lower, upper);
        }

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

private:
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
            if (cv::contourArea(contour) > min_area_) {
                cv::Rect rect = cv::boundingRect(contour);
                RCLCPP_INFO(this->get_logger(), "Detected object at (%d,%d) with size %f, %f",
                            rect.x, rect.y, rect.width, rect.height);
                cv::rectangle(filtered, rect, cv::Scalar(0, 255, 0), 2);

                yolov8_msgs::msg::BoundingBox2D bbox;
                bbox.center.position.x = rect.x + rect.width / 2.0;  // Center X
                bbox.center.position.x = rect.y + rect.height / 2.0; // Center Y
                bbox.size.x = rect.width;  // Width of the bounding box
                bbox.size.y = rect.height; // Height of the bounding box

                yolov8_msgs::msg::Detection det;
                det.class_id = 100;
                det.class_name = class_name_;
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
    std::string class_name_;
    int min_area_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ColorDetector>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
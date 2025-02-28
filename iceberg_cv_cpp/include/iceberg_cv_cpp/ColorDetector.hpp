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


private:
    template <typename T>
    void getParam(std::string param_name, T& param, T default_value, std::string desc) {
        auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
        param_desc.description = desc;
        this->declare_parameter<T>(param_name, default_value, param_desc);
        this->get_parameter(param_name, param);
        std::string param_log_output = param_name + ": " + std::to_string(param);
        RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

        return;
    }

    template <typename T>
    void updateYamlParam(const std::string &paramName, T newValue) {
        if (isActive()){
            try {
                std::string nodeName = "/" + std::string(this->get_name());
                std::filesystem::path current_file(__FILE__); 
                std::filesystem::path package_path = current_file.parent_path().parent_path().parent_path();

                std::string file_path = package_path.string() + "/config/params.yaml";

                //Load the YAML file
                YAML::Node config = YAML::LoadFile(file_path);
      
                //Check if the node and parameter exist
                if (!config[nodeName]) {
                    std::cerr << "Error: Node " << nodeName << " not found in YAML file." << std::endl;
                    return;
                }

                //Check if the node and parameter exist
                if (!config[nodeName] || !config[nodeName]["ros__parameters"] || !config[nodeName]["ros__parameters"][paramName]) {
                    std::cerr << "Error: Parameter " << paramName << " not found in YAML file." << std::endl;
                    return;
                }
      
              //Update the parameter value
                if constexpr (std::is_same_v<T, double>) {
                    std::ostringstream oss;
                    oss << std::fixed << std::setprecision(3) << newValue;
                    config[nodeName]["ros__parameters"][paramName] = oss.str();
                }
                
                else {
                    config[nodeName]["ros__parameters"][paramName] = newValue;
                }
      
                //Write back to file
                std::ofstream outFile(file_path);
                if (!outFile) {
                    std::cerr << "Error: Unable to open file for writing." << std::endl;
                    return;
                }

                outFile << config;
                outFile.close();
      
                std::cout << "Successfully updated " << paramName << " to "<< newValue << std::endl;
            }
            
            catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        }
    }

    // Member variables
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;
    
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr img_pub_;
    rclcpp::Publisher<yolov8_msgs::msg::DetectionArray>::SharedPtr det_pub_;

    std::vector<std::pair<cv::Vec3b, cv::Vec3b>> hsv_ranges_;
    std::string input_topic_;
    std::string output_img_topic_;
    std::string output_det_topic_;
    std::string class_name_;
    int min_area_;

    std::vector<int64_t> lower_hsv_list_;
    std::vector<int64_t> upper_hsv_list_;
};


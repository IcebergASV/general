#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "yolov8_msgs/msg/detection_array.hpp"
#include "comp_tasks_interfaces/msg/simplified_detection_array.hpp"  // Replace with your actual package name

class DetectionFilterNode : public rclcpp::Node
{
public:
    DetectionFilterNode()
    : Node("detection_filter_node")
    {
        // Create a subscriber for the /yolo/detections topic
        subscription_ = this->create_subscription<yolov8_msgs::msg::DetectionArray>(
            "/yolo/detections", 
            10, 
            std::bind(&DetectionFilterNode::detections_callback, this, std::placeholders::_1)
        );

        // Create a publisher for the /yolo/detections/filtered topic
        publisher_ = this->create_publisher<comp_tasks_interfaces::msg::SimplifiedDetectionArray>(
            "/yolo/detections/filtered", 
            10
        );
    }

private:
    void detections_callback(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
    {
        if (msg->detections.empty()) {
            RCLCPP_DEBUG(this->get_logger(), "No detections received.");
            return;
        }

        // Create a new SimplifiedDetectionArray message to publish
        auto filtered_msg = comp_tasks_interfaces::msg::SimplifiedDetectionArray();
        //filtered_msg.header = msg->header; // Copy the header from the incoming message
        
        // Populate the simplified detections
        for (const auto& detection : msg->detections) {
            comp_tasks_interfaces::msg::SimplifiedDetection simplified_detection;
            simplified_detection.class_name = detection.class_name;
            simplified_detection.score = detection.score;
            simplified_detection.id = detection.id;
            simplified_detection.x = detection.bbox.center.position.x;
            
            filtered_msg.detections.push_back(simplified_detection);
        }

        // Publish the simplified message
        publisher_->publish(filtered_msg);

        RCLCPP_INFO(this->get_logger(), "Published %zu simplified detections to /yolo/detections/filtered", filtered_msg.detections.size());
    }

    rclcpp::Subscription<yolov8_msgs::msg::DetectionArray>::SharedPtr subscription_;
    rclcpp::Publisher<comp_tasks_interfaces::msg::SimplifiedDetectionArray>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DetectionFilterNode>());
    rclcpp::shutdown();
    return 0;
}
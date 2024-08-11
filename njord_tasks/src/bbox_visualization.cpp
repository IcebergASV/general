#include <rclcpp/rclcpp.hpp>
#include <yolov8_msgs/msg/detection_array.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <visualization_msgs/msg/marker.hpp>

class BBoxVisualization : public rclcpp::Node
{
public:
    BBoxVisualization() : Node("bbox_visualization")
    {
        // Create a publisher for RViz markers
        marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("visualization_marker_array", 10);

        // Create a subscription to /yolo/detections
        detection_sub_ = this->create_subscription<yolov8_msgs::msg::DetectionArray>(
            "/yolo/detections", 10,
            [this](const yolov8_msgs::msg::DetectionArray::SharedPtr msg) { this->processDetections(msg); });

        RCLCPP_INFO(this->get_logger(), "BBoxVisualization node has been started.");
    }

private:
    void processDetections(const yolov8_msgs::msg::DetectionArray::SharedPtr msg)
    {
        auto marker_array = visualization_msgs::msg::MarkerArray();

        for (const auto &detection : msg->detections)
        {
            if (detection.class_name == "red_buoy" || detection.class_name == "green_buoy")
            {
                // Compute angle
                double angle = pixelToAngle(60.0, 640, detection.bbox.center.position.x); // Assuming 60 degrees FOV and 640 pixels width

                // Create an arrow marker
                visualization_msgs::msg::Marker marker;
                marker.header.frame_id = "base_link"; // Or the appropriate frame
                marker.header.stamp = this->get_clock()->now();
                marker.ns = "detections";
                marker.id = detection.class_id; // Unique ID for each marker
                marker.type = visualization_msgs::msg::Marker::ARROW;
                marker.action = visualization_msgs::msg::Marker::ADD;
                marker.pose.position.x = 0.0;
                marker.pose.position.y = 0.0;
                marker.pose.position.z = 0.0;
                marker.pose.orientation = tf2::toMsg(tf2::Quaternion(tf2::Vector3(0.0, 0.0, 1.0), angle));
                marker.scale.x = 0.1; // Shaft width
                marker.scale.y = 0.2; // Shaft length
                marker.scale.z = 0.2; // Head length
                marker.color.r = (detection.class_name == "red_buoy") ? 1.0 : 0.0;
                marker.color.g = (detection.class_name == "green_buoy") ? 1.0 : 0.0;
                marker.color.b = 0.0;
                marker.color.a = 1.0;

                marker_array.markers.push_back(marker);
            }
        }

        marker_pub_->publish(marker_array);
    }

    double pixelToAngle(double fov_in_degrees, int res, int pixel)
    {
        // Calculate the angle in radians
        double fov_in_radians = fov_in_degrees * M_PI / 180.0;
        double center_pixel = res / 2.0;
        double pixel_angle = ((pixel - center_pixel) / center_pixel) * (fov_in_radians / 2.0);
        return pixel_angle;
    }

    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
    rclcpp::Subscription<yolov8_msgs::msg::DetectionArray>::SharedPtr detection_sub_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BBoxVisualization>());
    rclcpp::shutdown();
    return 0;
}

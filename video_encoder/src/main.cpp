#include <rclcpp/rclcpp.hpp>
#include "include/video_encoder.hpp"

int main(int argc, char** argv) {
    // Initialize the ROS 2 node
    rclcpp::init(argc, argv);

    // Create the VideoEncoder node and spin
    auto node = std::make_shared<VideoEncoder>();
    rclcpp::spin(node);

    // Shutdown ROS 2
    rclcpp::shutdown();
    return 0;
}

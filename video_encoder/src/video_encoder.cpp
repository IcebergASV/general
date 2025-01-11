#include "include/video_encoder.hpp"
#include <cv_bridge/cv_bridge.h>

VideoEncoder::VideoEncoder() : Node("video_encoder") {
    // Initialize the GStreamer pipeline
    gst_pipeline_ = std::make_shared<GStreamerPipeline>("output.mp4");

    // Start the GStreamer pipeline
    if (!gst_pipeline_->start_pipeline()) {
        RCLCPP_ERROR(this->get_logger(), "Failed to start GStreamer pipeline.");
        rclcpp::shutdown();
    }

    // Subscribe to the camera topic
    image_subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/camera/color/image_raw", 10, 
        std::bind(&VideoEncoder::image_callback, this, std::placeholders::_1)
    );
}

void VideoEncoder::image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
    try {
        // Convert the ROS image message to an OpenCV image (RGB8)
        cv::Mat frame = cv_bridge::toCvShare(msg, "rgb8")->image;

        // Push the frame to the GStreamer pipeline
        gst_pipeline_->push_frame(frame);

        RCLCPP_INFO(this->get_logger(), "Frame pushed to pipeline.");
    } catch (cv_bridge::Exception& e) {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
    }
}

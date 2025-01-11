#ifndef VIDEO_ENCODER_HPP
#define VIDEO_ENCODER_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <opencv2/opencv.hpp>
#include "gst_pipeline.hpp"

class VideoEncoder : public rclcpp::Node {
public:
    VideoEncoder();

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;
    std::shared_ptr<GStreamerPipeline> gst_pipeline_;  // GStreamer pipeline
};

#endif  // VIDEO_ENCODER_HPP

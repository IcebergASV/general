#include <gst/gst.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "gst_pipeline.hpp"
#include <thread>

int main(int argc, char *argv[]) {
    // Initialize GStreamer and OpenCV
    gst_init(&argc, &argv);

    // Create GStreamer pipeline object, saving to "output.mp4"
    GStreamerPipeline pipeline("output.mp4");

    // Start the pipeline
    if (!pipeline.start_pipeline()) {
        std::cerr << "Failed to start pipeline." << std::endl;
        return -1;
    }

    // Create synthetic RGB8 data using OpenCV (640x480, 15 FPS)
    const int width = 640;
    const int height = 480;
    const int fps = 15;
    const int num_frames = fps * 5;  // Generate 5 seconds of video

    // Loop to generate and push frames
    for (int i = 0; i < num_frames; ++i) {
        // Create a blank image (e.g., a simple color gradient)
        cv::Mat frame(height, width, CV_8UC3);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                frame.at<cv::Vec3b>(y, x) = cv::Vec3b(x % 255, y % 255, (x + y) % 255);  // Some gradient pattern
            }
        }

        // Push the generated frame to the pipeline
        pipeline.push_frame(frame);

        // Simulate frame delay (to match 15 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    }

    // Stop the pipeline and clean up
    pipeline.stop_pipeline();
    std::cout << "Pipeline stopped, video saved to output.mp4" << std::endl;

    return 0;
}

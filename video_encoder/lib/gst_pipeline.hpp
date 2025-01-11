#include <gst/gst.h>
#include <gst/app/gstappsrc.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

class GStreamerPipeline {
public:
    GStreamerPipeline(const std::string &filename);
    ~GStreamerPipeline();
    
    bool start_pipeline();
    void stop_pipeline();
    void push_frame(const cv::Mat &frame);

private:
    GstElement *pipeline, *appsrc;
    GstBus *bus;
    GMainLoop *loop;
    guint64 frame_count;
    std::string output_file;

    static gboolean bus_callback(GstBus *bus, GstMessage *msg, gpointer data);
};
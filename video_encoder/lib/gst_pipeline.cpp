#include <gst/gst.h>
#include <gst/app/gstappsrc.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "gst_pipeline.hpp" 


GStreamerPipeline::GStreamerPipeline(const std::string &filename)
    : pipeline(nullptr), appsrc(nullptr), bus(nullptr), loop(nullptr), output_file(filename), frame_count(0) {
    gst_init(nullptr, nullptr);  // Initialize GStreamer
}

GStreamerPipeline::~GStreamerPipeline() {
    if (pipeline) {
        gst_object_unref(pipeline);
    }
    if (bus) {
        gst_object_unref(bus);
    }
    if (loop) {
        g_main_loop_unref(loop);
    }
}

bool GStreamerPipeline::start_pipeline() {
    // Define the GStreamer pipeline string, using appsrc for pushing data
    std::string pipeline_str = 
        "appsrc name=source ! "
        "videoconvert ! "                // Convert RGB to a format supported by nvvconv
        "video/x-raw, format=I420 ! "    // Set the format that nvvconv can handle
        "nvvidconv ! "
        "video/x-raw(memory:NVMM), format=NV12 ! "
        "nvv4l2h265enc ! "
        "h265parse ! qtmux ! "
        "filesink location=" + output_file;

    // Create pipeline from string
    pipeline = gst_parse_launch(pipeline_str.c_str(), nullptr);
    if (!pipeline) {
        std::cerr << "Failed to create pipeline!" << std::endl;
        return false;
    }

    // Get the appsrc element
    appsrc = gst_bin_get_by_name(GST_BIN(pipeline), "source");
    if (!appsrc) {
        std::cerr << "Failed to get appsrc from pipeline." << std::endl;
        return false;
    }

    // Set the appsrc caps (640x480, 15 fps, RGB format)
    GstCaps *caps = gst_caps_new_simple(
        "video/x-raw",
        "format", G_TYPE_STRING, "RGB",  // Input format should be RGB
        "width", G_TYPE_INT, 640,
        "height", G_TYPE_INT, 480,
        "framerate", GST_TYPE_FRACTION, 15, 1,
        nullptr);
    gst_app_src_set_caps(GST_APP_SRC(appsrc), caps);
    gst_caps_unref(caps);

    // Create a loop and set the bus to watch for messages (e.g., errors, EOS)
    loop = g_main_loop_new(nullptr, FALSE);
    bus = gst_element_get_bus(pipeline);
    gst_bus_add_watch(bus, bus_callback, loop);

    // Start the pipeline
    GstStateChangeReturn ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        std::cerr << "Unable to set the pipeline to the playing state!" << std::endl;
        gst_object_unref(pipeline);
        return false;
    }

    std::cout << "Pipeline started, recording to: " << output_file << std::endl;
    return true;
}

void GStreamerPipeline::stop_pipeline() {
    if (pipeline) {
        gst_element_send_event(pipeline, gst_event_new_eos());  // Send EOS event to finish properly
        gst_element_set_state(pipeline, GST_STATE_NULL);        // Set pipeline to NULL state to stop
    }
    if (loop) {
        g_main_loop_quit(loop);  // Quit the main loop
    }
}

void GStreamerPipeline::push_frame(const cv::Mat& frame) {
    if (frame.type() != CV_8UC3) {
        std::cerr << "Frame format is not RGB!" << std::endl;
        return;
    }

    // Create a GstBuffer to hold the frame data
    GstBuffer *buffer = gst_buffer_new_allocate(nullptr, frame.total() * frame.elemSize(), nullptr);
    GstMapInfo map;
    gst_buffer_map(buffer, &map, GST_MAP_WRITE);

    // Copy the OpenCV frame data into the GstBuffer
    memcpy(map.data, frame.data, gst_buffer_get_size(buffer));
    gst_buffer_unmap(buffer, &map);

    // Set PTS and duration
    GstClockTime timestamp = gst_util_uint64_scale(frame_count, GST_SECOND, 15); // Assuming 15 FPS
    GST_BUFFER_PTS(buffer) = timestamp;
    GST_BUFFER_DURATION(buffer) = gst_util_uint64_scale(1, GST_SECOND, 15); // 1/15 sec per frame

    // Increment frame counter for next frame's timestamp
    frame_count++;

    // Push the buffer into appsrc
    GstFlowReturn ret;
    g_signal_emit_by_name(appsrc, "push-buffer", buffer, &ret);
    if (ret != GST_FLOW_OK) {
        std::cerr << "Error pushing buffer to pipeline!" << std::endl;
    }

    gst_buffer_unref(buffer);
}


gboolean GStreamerPipeline::bus_callback(GstBus *bus, GstMessage *msg, gpointer data) {
    GMainLoop *loop = static_cast<GMainLoop *>(data);
    
    switch (GST_MESSAGE_TYPE(msg)) {
        case GST_MESSAGE_ERROR: {
            GError *err;
            gchar *debug_info;
            gst_message_parse_error(msg, &err, &debug_info);
            std::cerr << "Error received from element " 
                      << GST_OBJECT_NAME(msg->src) << ": " << err->message << std::endl;
            std::cerr << "Debugging information: " 
                      << (debug_info ? debug_info : "none") << std::endl;
            g_clear_error(&err);
            g_free(debug_info);
            g_main_loop_quit(loop);  // Quit loop on error
            break;
        }
        case GST_MESSAGE_EOS:
            std::cout << "End-Of-Stream reached." << std::endl;
            g_main_loop_quit(loop);  // Quit loop on EOS
            break;
        default:
            break;
    }
    
    return TRUE;  // Continue listening to the bus
}

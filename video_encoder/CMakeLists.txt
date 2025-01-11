cmake_minimum_required(VERSION 3.5)
project(video_encoder)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(PkgConfig REQUIRED)

# Find GStreamer libraries
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_APP REQUIRED gstreamer-app-1.0)

# Include directories
include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${GSTREAMER_INCLUDE_DIRS}
  ${GSTREAMER_APP_INCLUDE_DIRS}
)

# Add the executable
#add_executable(gst_pipeline_test
#  lib/gst_pipeline.cpp
#  lib/main.cpp  # Main file for testing the GStreamer pipeline
#)
# Add the executable
add_executable(video_encoder_node
  src/video_encoder.cpp
  src/main.cpp
  lib/gst_pipeline.cpp  # Ensure this points to your GStreamerPipeline implementation
)

# Link libraries
#target_link_libraries(gst_pipeline_test
#  ${OpenCV_LIBRARIES}
#  ${GSTREAMER_LIBRARIES}
#  ${GSTREAMER_APP_LIBRARIES}
#)
target_link_libraries(video_encoder_node
  ${OpenCV_LIBRARIES}
  ${GSTREAMER_LIBRARIES}
  ${GSTREAMER_APP_LIBRARIES}
)

# Dependencies
ament_target_dependencies(video_encoder_node
  rclcpp
  sensor_msgs
  cv_bridge
  OpenCV
)

# Install
install(TARGETS video_encoder_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
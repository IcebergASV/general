# Notes for Maneuvering Task

## Jetson

ros2 launch njord_tasks oct_man_testing.launch.py
ros2 launch njord_tasks record_rosbags.launch.py

## Locally
ros2 launch markers_pkg laptop_vizualization.launch.py
rqt -p manuevering_debug
ros2 launch gui launch.py

If yolo doesn't launch:
ros2 launch yolov8_bringup yolov8.launch.py model:=src/general/yolov8_ros/weights/comp_markI.pt input_image_topic:=/camera/camera/color_image_raw


## Topics

ros2 topic echo /yolo/detections/filtered
ros2 topic echo /mavros/local_position/pose
ros2 topic echo /mavros/setpoint_position/pose

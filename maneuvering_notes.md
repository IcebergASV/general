# Notes for Maneuvering Task

## Stuff to Run

* `pixhawk`
* `camera`
* `ros2 launch njord_tasks master.launch.py`
* `ros2 launch markers_pkg laptop_vizualization.launch.py`
* `rqt`

If yolo doesn't launch:
* `ros2 launch yolov8_bringup yolov8.launch.py model:=src/general/yolov8_ros/weights/comp_markI.pt input_image_topic:=/camera/camera/color_image_raw`

Michael needs mission planner, and LED code.

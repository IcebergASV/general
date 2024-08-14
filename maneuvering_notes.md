# Notes for Maneuvering Task

## Stuff to Run

* `pixhawk`
* `camera`
* `ros2 launch njord_tasks master.launch.py`
* `ros2 launch markers_pkg laptop_vizualization.launch.py` - on my laptop
* `rqt` - on my laptop
* `ros2 run njord_tasks detection_filter`

If yolo doesn't launch:
* `ros2 launch yolov8_bringup yolov8.launch.py model:=src/general/yolov8_ros/weights/comp_markI.pt input_image_topic:=/camera/camera/color_image_raw`


## Topics

`ros2 topic echo /yolo/detections/filtered`
`ros2 topic echo /mavros/local_position/pose`
`ros2 topic echo /mavros/setpoint_position/pose`


Michael needs mission planner, and LED code.


## Testing

`ros2 service call /mavros/set_mode mavros_msgs/srv/SetMode "{base_mode: 0, custom_mode: 'HOLD'}"`

`ros2 topic pub /mavros/setpoint_velocity/cmd_vel_unstamped geometry_msgs/msg/Twist "{linear: {x: 1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}" -r 10`

`ros2 topic pub /mavros/setpoint_velocity/cmd_vel_unstamped geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}" -r 10`

`


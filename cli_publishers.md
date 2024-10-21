# ROS2 Topic Pubs

## wp reached
`ros2 topic pub /mavros/mission/reached mavros_msgs/msg/WaypointReached "{wp_seq: 1}" -r 10`

## /yolo/detections

ros2 topic pub /yolo/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'red_buoy', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 24.1787109375, y: 237.41123962402344}, theta: 0.0}, size: {x: 16.108551025390625, y: 18.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"

ros2 topic pub /yolo/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: []}"

## Velocity SP
`ros2 topic pub /mavros/setpoint_velocity/cmd_vel_unstamped geometry_msgs/msg/Twist "{linear: {x: 1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}" -r 10`

`ros2 topic pub /mavros/setpoint_velocity/cmd_vel_unstamped geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}" -r 10`


## Set Mode
`ros2 service call /mavros/set_mode mavros_msgs/srv/SetMode "{base_mode: 0, custom_mode: 'HOLD'}"`


### set param to reverse throttle
ros2 param set /mavros/setpoint_attitude reverse_throttle true

### set throttle
ros2 topic pub /mavros/setpoint_attitude/thrust std_msgs/msg/Float32 '{data: 0.5}'
`

## Global WPs

ros2 topic pub /mavros/setpoint_position/global sensor_msgs/msg/NavSatFix '{latitude: 63.4412662, longitude: 10.4242176, altitude: 500.0}'

ros2 topic pub /mavros/setpoint_position/global sensor_msgs/msg/NavSatFix '{latitude: 47.397742, longitude: 8.545593, altitude: 500.0}'

ros2 topic pub /mavros/setpoint_position/global sensor_msgs/msg/NavSatFix '{latitude: 47.397742, longitude: 8.545593, altitude: 500.0}'

ros2 topic pub /mavros/setpoint_position/global sensor_msgs/msg/NavSatFix '{latitude: 47.397742, longitude: 8.545593, altitude: 500.0}'

## Local WPs

ros2 topic pub /mavros/setpoint_position/local geometry_msgs/msg/PoseStamped '{header: {stamp: {sec: 0, nanosec: 0}, frame_id: "map"}, pose: {position: {x: 47.397742, y: 8.545593, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}}'

# ROS2 Topic Pubs

## wp reached
`ros2 topic pub /mavros/mission/reached mavros_msgs/msg/WaypointReached "{wp_seq: 1}" -r 10`

## /yolo/detections

ros2 topic pub /yolo/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'red_buoy', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 24.1787109375, y: 237.41123962402344}, theta: 0.0}, size: {x: 16.108551025390625, y: 18.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"

ros2 topic pub /yolo/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'red_buoy', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 100.1787109375, y: 100.23962402344}, theta: 0.0}, size: {x: 20.108551025390625, y: 20.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}},

  {class_id: 7, class_name: 'green_buoy', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 540.1787109375, y: 120.41123962402344}, theta: 0.0}, size: {x: 20.108551025390625, y: 20.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"


ros2 topic pub /icebergcv/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'red', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 100.1787109375, y: 100.23962402344}, theta: 0.0}, size: {x: 20.108551025390625, y: 20.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}},

  {class_id: 7, class_name: 'green', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 540.1787109375, y: 120.41123962402344}, theta: 0.0}, size: {x: 20.108551025390625, y: 20.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"


ros2 topic pub /icebergcv/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'green', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 100.1787109375, y: 100.23962402344}, theta: 0.0}, size: {x: 20.108551025390625, y: 20.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"

ros2 topic pub /icebergcv/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: []}"

ros2 topic pub /icebergcv/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'blue', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 340.1787109375, y: 237.41123962402344}, theta: 0.0}, size: {x: 16.108551025390625, y: 18.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"

ros2 topic pub /yolo/detections yolov8_msgs/DetectionArray "{header: {stamp: {sec: 1728147972, nanosec: 302901855}, frame_id: 'camera_color_optical_frame'}, detections: [{class_id: 7, class_name: 'red_buoy', score: 0.6200227737426758, id: '', bbox: {center: {position: {x: 100.1787109375, y: 237.41123962402344}, theta: 0.0}, size: {x: 16.108551025390625, y: 18.4189453125}}, bbox3d: {center: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, size: {x: 0.0, y: 0.0, z: 0.0}, frame_id: ''}, mask: {height: 0, width: 0, data: []}, keypoints: {data: []}, keypoints3d: {data: [], frame_id: ''}}]}"


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

ros2 topic pub /mavros/setpoint_position/global geographic_msgs/msg/GeoPoseStamped '
header:
  stamp:
    sec: 0
    nanosec: 0
  frame_id: "map"
pose:
  position:
    latitude: 28.5581
    longitude: -81.229037
    altitude: 500.0
  orientation:
    x: 0.0
    y: 0.0
    z: 0.0
    w: 1.0'
## Local WPs

ros2 topic pub /mavros/setpoint_position/local geometry_msgs/msg/PoseStamped '{header: {stamp: {sec: 0, nanosec: 0}, frame_id: "map"}, pose: {position: {x: 10.397742, y: 8.545593, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}}'


## mavros state
ros2 topic pub /mavros/state mavros_msgs/msg/State "header:
  stamp:
    sec: 3253
    nanosec: 1794336
  frame_id: ''
connected: true
armed: true
guided: false
manual_input: true
mode: 'MANUAL'
system_status: 4"

ros2 topic pub /yolo/detections yolov8_msgs/msg/DetectionArray "{detections: [
    {
        class_id: 1,
        class_name: 'green_buoy',
        score: 0.95,
        id: '1',
        bbox: {center: {position: {x: 150, y: 200}}, size: {x: 30, y: 100}},
    },
    {
        class_id: 2,
        class_name: 'green_buoy',
        score: 0.85,
        id: '2',
        bbox: {center: {position: {x: 300, y: 200}}, size: {x: 50, y: 80}},
    }
]}"



ros2 topic pub /yolo/detections yolov8_msgs/msg/DetectionArray "{detections: [
    {
        class_id: 1,
        class_name: 'red_buoy',
        score: 0.95,
        id: '1',
        bbox: {center: {position: {x: 150, y: 200}}, size: {x: 30, y: 100}},
    }
]}"

ros2 topic pub /yolo/detections yolov8_msgs/msg/DetectionArray "{detections: [
    {
        class_id: 1,
        class_name: 'pink_buoy',
        score: 0.95,
        id: '1',
        bbox: {center: {position: {x: 150, y: 200}}, size: {x: 30, y: 100}},
    },
    {
        class_id: 2,
        class_name: 'blue_buoy',
        score: 0.85,
        id: '2',
        bbox: {center: {position: {x: 300, y: 200}}, size: {x: 50, y: 80}},
    }
]}"


# 90 degrees (straight)
ros2 topic pub /yolo/detections yolov8_msgs/msg/DetectionArray "{detections: [
    {
        class_id: 1,
        class_name: 'red_buoy',
        score: 0.95,
        id: '1',
        bbox: {center: {position: {x: 10, y: 200}}, size: {x: 30, y: 100}},
    },
    {
        class_id: 2,
        class_name: 'green_buoy',
        score: 0.85,
        id: '2',
        bbox: {center: {position: {x: 1910, y: 200}}, size: {x: 50, y: 80}},
    }
]}"


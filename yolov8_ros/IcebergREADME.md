# YOLOv8 and ROS2 Iceberg ASV

## Usage
### Launch D435 Camera

```shell
$ ros2 launch realsense2_camera rs_launch.py
```
### YOLOv8 Launch with Defatult Weights

```shell
$ ros2 launch yolov8_bringup yolov8.launch.py input_image_topic:=/camera/camera/color/image_raw
```

### YOLOv8 Launch with Specific Weights

```shell
$ ros2 launch yolov8_bringup yolov8.launch.py input_image_topic:=/camera/camera/color/image_raw model:=/path/to/weights
```

### YOLOv8 Launch with Specific Weights and Threshold

```shell
$ ros2 launch yolov8_bringup yolov8.launch.py input_image_topic:=/camera/camera/color/image_raw model:=/path/to/weights threshold:=0.9
```

#### Topics
- **/yolo/detections**: Objects detected by YOLO using the RGB images. Each object contains a bounding boxes and a class name. It may also include a mak or a list of keypoints.
- **/yolo/iceberg_detections**: Objects detected by YOLO using the RGB images. Each object contains a bounding boxes and a class name tailored specifically for Iceberg ASV.
- **/yolo/tracking**: Objects detected and tracked from YOLO results. Each object is assigned a tracking ID.
- **/yolo/detections_3d**: 3D objects detected. YOLO results are used to crop the depth images to create the 3D bounding boxes and 3D keypoints.
- **/yolo/debug_image**: Debug images showing the detected and tracked objects. They can be visualized with rviz2.


#### Parameters
- **model**: YOLOv8 model (default: yolov8m.pt)
- **tracker**: Tracker file (default: bytetrack.yaml)
- **device**: GPU/CUDA (default: cuda:0)
- **enable**: Wether to start YOLOv8 enabled (default: True)
- **threshold**: Detection threshold (default: 0.5)
- **input_image_topic**: Camera topic of RGB images (default: /camera/rgb/image_raw)
- **image_reliability**: Reliability for the image topic: 0=system default, 1=Reliable, 2=Best Effort (default: 2)


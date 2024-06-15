# YOLOv5 + ROS2 : You can Leverage On ROS2
State-of-the-art object detection technique, [YOLOv5](https://github.com/ultralytics/yolov5) is now compatible with ROS2<br>
![YOLOv5-ROS2-graph](yolov5_ros2/yolov5_ros2_graph.png). The code was taken originally from the [YOLOv5_ROS2-YOu-can-Leverage-On-ROS2](https://github.com/moksh-401-511/YOLOv5_ROS2-YOu-can-Leverage-On-ROS2) repository and has been modified.

**Subscribed Topic**: 
  - Input image-stream ```/camera/color/image_raw```<br>

**Published Topic**: 
  - Image-stream with bounding box around detected objects ```sensor_msgs/msg/Image```<br>
  - Bounding boxes (manually created message type) ```boundingboxes/msg/BoundingBoxes```

**Note:** Published image and boundingbox topics are assigned same time-stamp as that of subscribed image topic, so that input and output can be matched frame-by-frame if required for further processing.

## 1. Installation
### 1.1 Prerequisities
- Install ROS2 from the official
- Strictly necessary YOLOv5 related libraries and packages:<br>
Run the following command in terminal for [yolov5_strict_requirements.txt](yolov5_ros2/yolov5_strict_requirements.txt) file:
```
pip install -r yolov5_strict_requirements.txt
```
- Camera input in this scenario the Intel D435 camera will be used. Click here for [documentation](https://gist.github.com/DavidGuamanDavila/cfad0309e5af1275ba248935eb1daa37) on how to setup.

## 2. Running Object Detection
### 2.1 Video input
Run the following command to initalize the Camera
```
ros2 launch realsense2_camera rs_launch.py
```
**Note:** the above command will start publishing image-stream with topic name '/camera/color/image_raw'

### 2.2 YOLOv5 node
Now we will start our yolov5_ros2 node to perform object detection on input image-stream
Open another shell in terminal and run the following commands:
```
# run launch file to initialize yolov5_ros2 node
# provide the input image-stream topic name as argument (in our case, its '/image')
# also provide the weight file that you want to use (default: yolov5l.pt)
ros2 launch yolov5_ros2 yolov5_ros2_node.launch.py sub_topic:='/camera/color/image_raw' weights:='yolov5s.pt'

```

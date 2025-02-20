import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/robert/Projects/ros_ws/src/general/install/yolov8_ros'

from pathlib import Path

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    yolov8_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("yolov8_bringup"),
                        "launch",
                        "yolov8.launch.py",
                    ]
                )
            ],
            ),
            launch_arguments={
                'input_image_topic': '/camera/camera/color/image_raw',
                'model': '/home/icebergasv/ros2_ws/src/general/yolov8_ros/weights/marine_markers_v3.pt'
            }.items()
    )
    return LaunchDescription(
        [
            yolov8_launch,
        ]
    )



from pathlib import Path

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():


    px4 = IncludeLaunchDescription(
        XMLLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("mavros"),
                        "launch",
                        "px4.launch",
                    ]
                ),
            ]
        )
    )

    camera = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("realsense2_camera"),
                        "launch",
                        "rs_launch.py",
                    ]
                ),
            ]
        )
    )

    njord_tasks = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("njord_tasks"),
                        "launch",
                        "njord_tasks.launch.py",
                    ]
                ),
            ]
        )
    )

    odom_map_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='static_transform_publisher',
        output='screen',
        arguments=['0', '0', '0', '0', '0', '0', '1', 'laser', 'odom']
    )

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
                'model': '/home/icebergasv/ros2_ws/src/general/yolov8_ros/weights/marine_markers_v1.pt'
            }.items()
    )
    return LaunchDescription(
        [
            odom_map_tf,
            yolov8_launch,
            px4,
            camera,
            njord_tasks,
        ]
    )



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

    comp_tasks = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("comp_tasks"),
                        "launch",
                        "comp_tasks.launch.py",
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
                        FindPackageShare("comp_tasks"),
                        "launch",
                        "yolo.launch.py",
                    ]
                )
            ]
        )
    )
    return LaunchDescription(
        [
            odom_map_tf,
            yolov8_launch,
            comp_tasks,
        ]
    )



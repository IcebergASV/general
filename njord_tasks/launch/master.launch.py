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
    pkg_perception = get_package_share_directory("perception")
    pkg_laser_segmentation = get_package_share_directory("laser_segmentation")

    laser_segmentation = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("laser_segmentation"),
                        "launch",
                        "segmentation.launch.py",
                    ]
                ),
            ]
        )
    )

    perception = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("perception"),
                        "launch",
                        "manual_composition.launch.py",
                    ]
                ),
            ]
        )
    )

    return LaunchDescription(
        [
            perception,
            laser_segmentation,
        ]
    )

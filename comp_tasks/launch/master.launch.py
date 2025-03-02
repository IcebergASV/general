import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import LaunchDescriptionSource

def generate_launch_description():

    mavros = IncludeLaunchDescription(
        LaunchDescriptionSource(
            PathJoinSubstitution(
                [
                    FindPackageShare("mavros"),
                    "launch",
                    "apm.launch",
                ]
            )
        )
    )
    realsense = IncludeLaunchDescription(
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

    cv = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("iceberg_cv_cpp"),
                        "launch",
                        "launch.py",
                    ]
                ),
            ]
        )
    )

    return LaunchDescription(
        [
            mavros,
            realsense,
            cv,
        ]
    )



import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('comp_tasks'),
        'config',
        'params.yaml'
        )
    gps_points = os.path.join(
        get_package_share_directory('comp_tasks'),
        'config',
        'gps_points.yaml'
        )

    log_level_launch_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info'
    )

    return LaunchDescription([
        log_level_launch_arg,
        Node(
            package='comp_tasks',
            executable='maneuvering_composition',
            namespace='',
            output='screen',
            parameters=[config, gps_points],
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='comp_tasks',
            executable='task_controller_composition',
            namespace='',
            output='screen',
            parameters=[config, gps_points],
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])

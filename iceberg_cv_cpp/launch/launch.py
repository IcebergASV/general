import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    red_config = os.path.join(
        get_package_share_directory('comp_tasks'),
        'config',
        'red_params.yaml'
        )
    blue_config = os.path.join(
        get_package_share_directory('comp_tasks'),
        'config',
        'green_params.yaml'
        )
    green_config = os.path.join(
        get_package_share_directory('comp_tasks'),
        'config',
        'blue_params.yaml'
        )

    log_level_launch_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info'
    )

    return LaunchDescription([
        log_level_launch_arg,
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            output='screen',
            parameters=[red_config],
            name='red',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            name='blue',
            output='screen',
            parameters=[blue_config],
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            name='green',
            output='screen',
            parameters=[green_config],
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])
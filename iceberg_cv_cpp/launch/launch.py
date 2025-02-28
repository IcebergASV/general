import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('iceberg_cv_cpp'),
        'config',
        'params.yaml'
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
            parameters=[config],
            name='red',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            output='screen',
            parameters=[config],
            name='blue',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            output='screen',
            parameters=[config],
            name='green',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])
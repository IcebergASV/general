import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution

def generate_launch_description():

    log_level_launch_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info'
    )

    lighting_launch_arg = DeclareLaunchArgument(
        'lighting',
        default_value='sunny.yaml'
    )

    config_file = LaunchConfiguration('lighting')

    config_path = PathJoinSubstitution([
        get_package_share_directory('iceberg_cv_cpp'),
        'config',
        config_file
    ])

    return LaunchDescription([
        log_level_launch_arg,
        lighting_launch_arg,
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            output='screen',
            parameters=[config_path, {'lighting': config_file}],
            name='red',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            output='screen',
            parameters=[config_path, {'lighting': config_file}],
            name='blue',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='iceberg_cv_cpp',
            executable='ColorDetector',
            namespace='',
            output='screen',
            parameters=[config_path, {'lighting': config_file}],
            name='green',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])
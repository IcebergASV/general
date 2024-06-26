import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('perception'),
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
            package='perception',
            executable='lidar_prop_detector_composition',
            namespace='',
            output='screen',
            parameters=[config], 
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='perception',
            executable='coord_finder_composition',
            namespace='',
            output='screen',
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='perception',
            executable='lidar_camera_fuser_composition',
            namespace='',
            output='screen',
            parameters=[config], 
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])
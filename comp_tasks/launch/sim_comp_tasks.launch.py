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
        'sim_params.yaml'
        )

    log_level_launch_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info'
    )

    return LaunchDescription([
        log_level_launch_arg,
        Node(
            package='comp_tasks',
            executable='task_composition',
            namespace='',
            output='screen',
            parameters=[config], 
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
        Node(
            package='comp_tasks',
            executable='task_composition',
            namespace='',
            output='screen',
            parameters=[config], 
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])

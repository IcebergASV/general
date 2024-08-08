import os
from launch import LaunchDescription
from ament_index_python import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
    get_package_share_directory('vehicle_control'),
    'config',
    'wp_sender.yml'
    )
    return LaunchDescription([
        Node(
            package='vehicle_control',  # Replace with your package name
            executable='waypoint_sender',  # Replace with your node executable name
            name='waypoint_sender',
            parameters=[config]  # Replace with the path to your params.yaml file
        )
    ])
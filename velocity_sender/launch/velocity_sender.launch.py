import os
from launch import LaunchDescription
from ament_index_python import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
    get_package_share_directory('velocity_sender'),
    'config',
    'zigzag.yml'
    )
    return LaunchDescription([
        Node(
            package='velocity_sender',  # Replace with your package name
            executable='velocity_sender',  # Replace with your node executable name
            name='velocity_sender',
            parameters=[config]  # Replace with the path to your params.yaml file
        )
    ])



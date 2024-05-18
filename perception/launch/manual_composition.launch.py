import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('perception'),
        'config',
        'params.yaml'
        )
    return LaunchDescription([
        Node(
            package='perception',
            executable='manual_composition',
            namespace='',
            output='screen',
            parameters=[config]
        ),
    ])
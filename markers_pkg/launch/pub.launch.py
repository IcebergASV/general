from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='markers_pkg',
            executable='publish_markers',
            output='screen'),
    ])
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    output_directory = '/home/parallels/rosbags_njord'  # Specify the desired directory here

    return LaunchDescription([
        Node(
            package='ros2bag',
            executable='record',
            name='ros2bag_record',
            output='screen',
            arguments=[
                '-o', output_directory,  # Specify the output directory for the bag file
                '/mavros/*',
            ]
        )
    ])

import os
from launch import LaunchDescription
from launch_ros.actions import Node, ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
from ament_index_python import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('njord_maneuvering'),
        'config',
        'params.yaml')
    
    log_level_launch_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info'
    )
    
    # return LaunchDescription([
    #     ComposableNodeContainer(
    #         name='nodes',
    #         namespace='',
    #         package='rclcpp_components',
    #         executable='component_container',
    #         composable_node_descriptions=[
    #             ComposableNode(
    #                 package='njord_maneuvering',
    #                 plugin='ManeuveringNode',
    #                 name='maneuvering_node',
    #                 parameters=[config],
    #                 extra_arguments=[{'use_intra_process_comms': True}],
    #             ),
    #         ]
    #     )
    # ])
    return LaunchDescription([
        log_level_launch_arg,
        Node(
            package='njord_maneuvering',
            executable='node_composition',
            namespace='',
            output='screen',
            parameters=[config],
            arguments=['--ros-args', '--log-level', LaunchConfiguration('log_level')]
        ),
    ])
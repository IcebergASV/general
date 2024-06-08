# from launch import LaunchDescription
# from launch_ros.actions import Node
# def generate_launch_description():
#     ld = LaunchDescription()
#     turtlesim_node = Node(
#         package="vehicle_control",
#         executable="waypoint_sender",
#         name="waypoint_sender",
#         output="screen",
#         emulate_tty=True,
#         parameters=[{"param":'single'}]
#     )
#     ld.add_action(turtlesim_node)
#     return ld

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('vehicle_control'),
        'config',
        'params.yaml'
        )
    return LaunchDescription([
        Node(
            package='vehicle_control',
            executable='waypoint_sender',
            name='waypoint_sender',
            output='screen',
            emulate_tty=True,
        )
    ])
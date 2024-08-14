import launch
import os
from ament_index_python.packages import get_package_share_directory
from pathlib import Path
from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():

    markers_pkg = get_package_share_directory("markers_pkg")
    for _ in range(4):
        markers_pkg = os.path.dirname(markers_pkg)
    config_path = os.path.join(markers_pkg, 'src', 'general', 'markers_pkg', 'rviz', 'collision-avoidance.rviz')

    rviz = Node(
        package="rviz2",
        executable="rviz2",
        arguments=["-d", f'{config_path}'],
        condition=IfCondition(LaunchConfiguration("rviz")),
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            "rviz", default_value="true", description="Open RViz."
        ),
        rviz,

    ])
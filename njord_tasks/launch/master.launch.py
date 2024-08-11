from pathlib import Path

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # pkg_perception = get_package_share_directory("perception")
    # pkg_laser_segmentation = get_package_share_directory("laser_segmentation")
    # pkg_yolov8_bringup = get_package_share_directory("yolov8_bringup")

    # laser_segmentation = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         [
    #             PathJoinSubstitution(
    #                 [
    #                     FindPackageShare("laser_segmentation"),
    #                     "launch",
    #                     "segmentation.launch.py",
    #                 ]
    #             ),
    #         ]
    #     )
    # )
    # yolov8_launch = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         [
    #             PathJoinSubstitution(
    #                 [
    #                     FindPackageShare("yolov8_bringup"),
    #                     "launch",
    #                     "yolov8.launch.py",
    #                 ]
    #             )
    #         ],
    #         ),
    #         launch_arguments={
    #             'input_image_topic': '/camera/camera/color/image_raw',
    #             'model': '/path/to/weights'
    #         }.items()
    # )

    # perception = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         [
    #             PathJoinSubstitution(
    #                 [
    #                     FindPackageShare("perception"),
    #                     "launch",
    #                     "perception_composition.launch.py",
    #                 ]
    #             ),
    #         ]
    #     )
    # )

    odom_map_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='static_transform_publisher',
        output='screen',
        arguments=['0', '0', '0', '0', '0', '0', '1', 'laser', 'odom']
    )

    return LaunchDescription(
        [
            odom_map_tf,
            #perception,
            # yolov8_launch,
            laser_segmentation,
        ]
    )

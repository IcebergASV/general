import os
from datetime import datetime
from launch import LaunchDescription
from launch.actions import ExecuteProcess

def generate_launch_description():
    sensor_topics = [
        '/camera/camera/color/image_raw',
        '/mavros/global_position/compass_hdg',
        '/mavros/global_position/global',
        '/mavros/global_position/local',
        '/mavros/local_position/pose',
        '/mavros/mission/reached',
        '/mavros/setpoint_position/global',
        '/mavros/setpoint_position/local',
        '/mavros/state',
        '/yolo/detections'
    ]

    robot_logic_topics = [
        '/camera/camera/color/image_raw',
        '/mavros/global_position/compass_hdg',
        '/mavros/global_position/global',
        '/mavros/global_position/local',
        '/mavros/local_position/pose',
        '/mavros/mission/reached',
        '/mavros/setpoint_position/global',
        '/mavros/setpoint_position/local',
        '/mavros/state',
        '/yolo/detections',
        '/yolov8_ros/dbg_image',
        '/njord_tasks/maneuvering/status',
        '/njord_tasks/task_completion_status',
        '/njord_tasks/task_to_execute',
        '/rosout'
    ]

    now = datetime.now()
    month_day_folder = now.strftime('%m_%d_rosbags')
    datetime_folder = now.strftime('%Y-%m-%d_%H-%M-%S')

    home_directory = os.path.expanduser('~')
    base_dir = os.path.join(home_directory, month_day_folder)
    date_time_dir = os.path.join(base_dir, datetime_folder)

    os.makedirs(date_time_dir, exist_ok=True)

    sensors_bag_name = os.path.join(date_time_dir, f"rosbag_sensors_{now.strftime('%Y-%m-%d_%H-%M-%S')}.bag")
    logic_bag_name = os.path.join(date_time_dir, f"rosbag_logic_{now.strftime('%Y-%m-%d_%H-%M-%S')}.bag")

    rosbag_sensors_command = ['ros2', 'bag', 'record'] + sensor_topics + ['-o', sensors_bag_name]
    rosbag_logic_command = ['ros2', 'bag', 'record'] + robot_logic_topics + ['-o', logic_bag_name]

    return LaunchDescription([
        ExecuteProcess(
            cmd=rosbag_sensors_command,
            output='screen'
        ),
        ExecuteProcess(
            cmd=rosbag_logic_command,
            output='screen'
        ),
    ])

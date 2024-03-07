from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
import time
from ament_index_python import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription(
        [
            Node(
                package="muuv_sensors",
                executable="imu",
                name="imu",
                # output="screen",
                emulate_tty=True,
                parameters=[{"pi_address": "192.168.8.157"}],
            ),
        ]
    )
    pid_launch_file = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("muuv_control"),
                "launch/pid.launch.py",
            )
        )
    )

    ld.add_action(pid_launch_file)
    time.sleep(2)

    return ld
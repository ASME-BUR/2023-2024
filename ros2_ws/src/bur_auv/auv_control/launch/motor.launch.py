from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python import get_package_share_directory


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory("muuv_control"), "config", "motor_force_config.yaml"
    )

    ld = LaunchDescription(
        [
            Node(
                package="muuv_control",
                name="motor_controller",
                executable="motor_controller",
                emulate_tty=True,
                parameters=[
                    config,
                    {"pub_topic": "motor_command"},
                    {"sub_topic": "ctrl_effort"},
                ],
            ),
            Node(
                package="muuv_control",
                name="thrusters",
                executable="thrusters",
                emulate_tty=True,
                parameters=[{"pi_address": "192.168.8.157"}],
                output="screen",
            ),
        ]
    )
    return ld

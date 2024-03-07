from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
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
            Node(
                package="muuv_ros",
                executable="pid_recombiner",
                name="pid_recombiner",
                output="screen",
                emulate_tty=True,
                parameters=[
                    {
                        "ctrl_effort.y": "imu_y",
                        "ctrl_effort.z": "imu_z",
                    }
                ],
            ),
            Node(
                package="muuv_ros",
                executable="imu_repub",
                name="imu_repub",
                output="screen",
                emulate_tty=True,
                parameters=[{}],
            ),
            Node(
                package="muuv_control",
                executable="motor_controller",
                name="motor_controller",
                output="screen",
                emulate_tty=True,
                parameters=[
                    {
                        "pi_address": "192.168.8.157",
                        "motor.0": 17,
                        "motor.1": 22,
                        "motor.2": 27,
                    }
                ],
            ),
        ]
    )
    pid_launch_file = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("pid_component"),
                "launch/muuv_pid.launch.py",
            )
        )
    )

    ld.add_action(pid_launch_file)

    return ld

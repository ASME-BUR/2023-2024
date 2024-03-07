from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription()

    config = os.path.join(
        get_package_share_directory("muuv_control"), "config", "ekf.yaml"
    )
    return LaunchDescription(
        [
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                name="frame",
                # output="screen",
                emulate_tty=True,
                arguments=["0", "0", "0", "0", "0", "0", "muuv/odom", "muuv/base_link   "],
            ),
            Node(
                package="robot_localization",
                executable="ekf_node",
                name="ekf_node",
                output="screen",
                emulate_tty=True,
                parameters=[config],
            ),
            Node(
                package="muuv_sensors",
                executable="imu_node",
                name="imu_node",
                # output="screen",
                emulate_tty=True,
                parameters=[{"pi_address": "192.168.8.157"}],
            ),
            Node(
                package="muuv_sensors",
                executable="bar30_node",
                name="bar30_node",
                # output="screen",
                emulate_tty=True,
                parameters=[{"pi_address": "192.168.8.157"}],
            ),
        ]
    )

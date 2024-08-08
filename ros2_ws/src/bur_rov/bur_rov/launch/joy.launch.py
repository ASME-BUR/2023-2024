from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory
import yaml
import pathlib


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="joy",
                executable="joy_node",
                name="joy",
                parameters=[
                os.path.join(get_package_share_directory("bur_rov"), 'config', 'ps4.yaml')
                ],
            ),
            Node(
                package="bur_rov",
                executable="joy_command",
                name="joy_command",
                parameters=[
                    {"using_joy": True},
                    {"using_ekf": False},
                os.path.join(get_package_share_directory("bur_rov"), 'config', 'ps4.yaml')
                ],
            ),
        ]
    )

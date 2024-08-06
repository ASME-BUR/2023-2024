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
                package="bur_rov",
                executable="open_loop",
                name="open_loop",
            ),
            Node(
                package="bur_rov",
                executable="joy_command",
                name="joy_command",
                parameters=[
                os.path.join(get_package_share_directory("bur_rov"), 'config', 'ps4.yaml')
                ],
            ),
        ]
    )

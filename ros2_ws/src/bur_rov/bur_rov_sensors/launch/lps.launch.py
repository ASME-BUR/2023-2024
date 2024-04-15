from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="bur_rov_sensors",
                executable="lps_node",
                name="lps",
                parameters=[
                    {"pi_address": "10.42.0.24"},
                ],
            )
        ]
    )

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="bur_rov_sensors",
                executable="bar30_node",
                name="bar30",
                parameters=[
                    {"pi_address": "10.42.0.24"},
                    {"fluid_density": 1005.0},
                    {'rate': 30},

                ],
            )
        ]
    )

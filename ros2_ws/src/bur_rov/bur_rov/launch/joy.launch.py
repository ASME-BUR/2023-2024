from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="joy",
                executable="joy_node",
                name="joy",
                parameters=[
                    {"device_id": 0},
                    {"device_name": "OpenTX FrSky Taranis Joystick"},
                    {"deadzone": 0.01},
                    {"autorepeat_rate": 20.0},
                    {"coalesce_interval_ms": 1}
                ],
            )
        ]
    )

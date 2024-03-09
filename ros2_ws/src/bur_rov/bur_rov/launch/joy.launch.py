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
                    {"deadzone": 0.01},
                    {"autorepeat_rate": 20.0},
                    {"coalesce_interval_ms": 1},
                    {"sticky_buttons": False},
                ],
            ),
            Node(
                package="bur_rov",
                executable="joy_command",
                name="joy_command",
                parameters=[
                    {"joy_topic": "joy"},
                    {"pose_topic": "pose"},
                    {"imu_topic": "imu"},
                    {"velocity": 0.5},
                    {"cmd_pub_topic": "command"},
                    ],
            )
        ]
    )

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
                    {"pose_topic": "depth_sensor"},
                    {"imu_topic": "imu"},
                    {"velocity": 1.0},
                    {"cmd_pub_topic": "command"},
                    {"axis_mapping.linear_x": 2},
                    {"axis_mapping.linear_y": 1},
                    {"axis_mapping.linear_z": 0},
                    {"axis_mapping.angular_x": 4},
                    {"axis_mapping.angular_y": 5},
                    {"axis_mapping.angular_z": 3},
                    ],
            )
        ]
    )

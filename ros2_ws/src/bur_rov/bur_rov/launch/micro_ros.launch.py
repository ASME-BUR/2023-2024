from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="micro_ros_agent",
                executable="micro_ros_agent",
                # parameters=[
                #     {"transport": "serial",
                #      "dev": "/dev/ttyACM1"}
                # ],
                output='screen',
                arguments=["serial", "-D", "/dev/ttyACM1", "-v4", "-b", "250000"]
            ),
            Node(
                package="micro_ros_agent",
                executable="micro_ros_agent",
                # parameters=[
                #     {"transport": "serial",
                #      "dev": "/dev/ttyACM1"}
                # ],
                output='screen',
                arguments=["serial", "-D", "/dev/ttyACM0", "-v4"]
            )
        ]
    )

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="usb_camera_driver",
                executable="usb_camera_driver_node",
                name="camera",
                parameters=[
                    {"image_width": 1600},
                    {"image_height": 1200},
                    {"camera_id": 2},
                    {"fps": 30.0},
                ],
                arguments=[],
            ),
            Node(
                package="image_transport",
                executable="republish",
                arguments=["--ros-args", "--remap", "in:=image_raw",
                           "--remap", "out:=image_raw_compressed"],
            ),
        ]
    )

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():    
    return LaunchDescription(
        [
            Node(
                package="bur_planner",
                executable="simple_planner",
                name="simple_planner",
                parameters=[
                    {"localizer_topic": "/odometry/filtered"},
                    {"vision_topic": "/vision"},
                    {"tree", "test.xml"},
                    {"tick_rate": 1},
                ],
                arguments=[],
            ),
        ]
    )

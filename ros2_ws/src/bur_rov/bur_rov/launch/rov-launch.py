import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    launch_description = LaunchDescription()

    bur_rov_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource('joy.launch.py')
    )
    eskf_launch = IncludeLaunchDescription(
        XMLLaunchDescriptionSource([os.path.join(
            get_package_share_directory('state_estimation'), 'launch'),
            '/eskf.launch'
        ])
    )

    controller_launch = IncludeLaunchDescription(
        XMLLaunchDescriptionSource([os.path.join(
            get_package_share_directory('controller'), 'launch'),
            '/controller.launch'
        ])
    )

    return LaunchDescription([
        eskf_launch,
        controller_launch
    ])
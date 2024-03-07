import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource

def generate_launch_description():
    bur_rov_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource('joy.launch.py')
    )
    controller_launch = IncludeLaunchDescription(
        XMLLaunchDescriptionSource([os.path.join(
            get_package_share_directory('controller'), 'launch'),
            '/controller.launch'
        ])
    )

    return LaunchDescription([
        bur_rov_launch,
        eskf_launch,
        controller_launch
    ])
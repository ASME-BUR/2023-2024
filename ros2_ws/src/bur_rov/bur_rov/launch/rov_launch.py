import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource

def generate_launch_description():
    joy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('bur_rov'), 'launch'),
            '/joy.launch.py'
        ])
    )
    controller_launch = IncludeLaunchDescription(
        XMLLaunchDescriptionSource([os.path.join(
            get_package_share_directory('controller'), 'launch'),
            '/controller.launch'
        ])
    )
    thruster_manager = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('thruster_manager'), 'launch'),
            '/motor_param_test.launch.py'
        ])
    )


    return LaunchDescription([
        thruster_manager,
        joy_launch,
        controller_launch
    ])
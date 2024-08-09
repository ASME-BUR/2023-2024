import os

from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource

def generate_launch_description():
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
    depth_sensor = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('bur_rov_sensors'), 'launch'),
            '/bar30.launch.py'
        ])
    )
    camera = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('bur_rov'), 'launch'),
            '/camera.launch.py'
        ])
    )
    arduino = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('bur_rov'), 'launch'),
            '/micro_ros.launch.py'
        ])
    )

    joy = Node(
        package="bur_rov",
        executable="joy_command",
        name="joy_command",
        parameters=[{"using_joy": True},
        {"using_ekf": False},
        # os.path.join(get_package_share_directory("bur_rov"), 'config', 'fake_joystick.yaml')
        ],
    )


    return LaunchDescription([
        thruster_manager,
        controller_launch,
        # depth_sensor,
        # camera,
        # joy,
        # arduino
    ])
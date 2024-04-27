import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource

from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution, TextSubstitution, Command, LaunchConfiguration


def generate_launch_description():
    ld = LaunchDescription()
    depth_sensor_arg = DeclareLaunchArgument(
        'depth_on',
        default_value='False',
        description='launch depth sensor?'
    )
    ld.add_action(depth_sensor_arg)
    arg_depth_sensor_arg = LaunchConfiguration('depth_on')
    
    controller_launch = IncludeLaunchDescription(
        XMLLaunchDescriptionSource([os.path.join(
            get_package_share_directory('controller'), 'launch'),
            '/controller.launch'
        ])
    )
    ld.add_action(controller_launch)
    thruster_manager = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('thruster_manager'), 'launch'),
            '/motor_param_test.launch.py'
        ])
    )
    ld.add_action(thruster_manager)
    # depth_sensor = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([os.path.join(
    #         get_package_share_directory('bur_rov_sensors'), 'launch'),
    #         '/bar30.launch.py'
    #     ])
    # )
    # ld.add_action(depth_sensor)

    return ld
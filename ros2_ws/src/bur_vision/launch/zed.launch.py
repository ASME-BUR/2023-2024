from launch_ros.substitutions import FindPackageShare
import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, TextSubstitution

def generate_launch_description():

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    FindPackageShare('zed_wrapper'),
                    'launch',
                    'zed_camera.launch.py'
                ])
            ]),
            launch_arguments={
                'camera_model': 'zedm',
                'publish_tf': 'false',
                'publish_map_tf': 'false',
                'publish_imu_tf': 'false',
            }.items()
        )
    ])

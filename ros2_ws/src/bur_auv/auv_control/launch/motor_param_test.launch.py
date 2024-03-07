import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    config = os.path.join(
        get_package_share_directory('muuv_control'),
        'config',
        'motor_force_config.yaml'
        )
        
    node=Node(
        package = 'muuv_control',
        name = 'motor_controller',
        executable = 'motor_controller',
        parameters = [config]
    )

    ld.add_action(node)
    return ld
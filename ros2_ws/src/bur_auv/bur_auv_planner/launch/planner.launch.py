import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    behavior_tree = LaunchConfiguration('behavior_tree')
    behavior_tree_arg = DeclareLaunchArgument(
        'behavior_tree',
        default_value=os.path.join(
            get_package_share_directory('bur_auv_planner'),
            'behavior_trees',
            'bur_tree.xml'
        )
    )
        
    node=Node(
        package = 'bur_auv_planner',
        name = 'bur_planner',
        executable = 'bur_planner',
        output = 'screen',
        arguments=[behavior_tree]
    )

    return LaunchDescription([
        behavior_tree_arg,
        node,
    ])
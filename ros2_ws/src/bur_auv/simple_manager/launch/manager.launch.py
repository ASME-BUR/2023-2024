import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from nav2_common.launch import RewrittenYaml


def generate_launch_description():
    manager_dir = get_package_share_directory('simple_manager')
    params_file = os.path.join(manager_dir, 'params', 'params.yaml')
    bt_file = os.path.join(manager_dir, 'behavior_trees', 'qualification_tree.xml')

    configured_params = RewrittenYaml(
        source_file=params_file,
        param_rewrites={
            'behavior_tree': bt_file,
        },
        convert_types=True)

    ld = LaunchDescription()

    node = Node(
            package="simple_manager",
            executable="simple_manager",
            name="simple_manager",
            parameters=[configured_params],
            arguments=[],
        )

    ld.add_action(node)
    return ld

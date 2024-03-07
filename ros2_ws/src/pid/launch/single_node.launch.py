"""Launch pid nodes in a component container."""

import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    """Generate launch description with multiple components."""
    container = ComposableNodeContainer(
        name="pid_container",
        namespace="",
        package="rclcpp_components",
        executable="component_container",
        composable_node_descriptions=[
            ComposableNode(
                package="pid",
                plugin="Pid_component",
                name="pid_x",
                parameters=[
                    {
                        "ctrl_effort_name": "ctrl_effort_x",
                        "setpoint_name": "setpoint_x",
                        "state_name": "imu_x",
                        "P_gain": 0.5,
                        "I_gain": 0.02,
                        "D_gain": 0.01,
                        "I_lim": 1.0,
                        "Out_lim": -1.0,
                        "antiwindup" : 100.0,
                    }
                ],
            ),
        ],
        output="screen",
    )

    return launch.LaunchDescription([container])

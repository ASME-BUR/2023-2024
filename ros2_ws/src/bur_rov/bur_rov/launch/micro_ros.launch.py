from launch import LaunchDescription
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression


def generate_launch_description():
    imu_verbose = LaunchConfiguration('imu_verbose')
    thruster_verbose = LaunchConfiguration('thruster_verbose')
    imu_verbose_arg = DeclareLaunchArgument(
        'imu_verbose',
        default_value='4'
    )
    thruster_verbose_arg = DeclareLaunchArgument(
        'thruster_verbose',
        default_value='4'
    )


    imu = Node(
                package="micro_ros_agent",
                executable="micro_ros_agent",
                output='screen',
                arguments=["serial", "-D", "/dev/ttyACM1", "-v", imu_verbose, "-b", "250000"]
            )
    thruster = Node(
                package="micro_ros_agent",
                executable="micro_ros_agent",
                output='screen',
                arguments=["serial", "-D", "/dev/ttyACM0", "-v", thruster_verbose]
            )
    
    return LaunchDescription([
        imu_verbose_arg,
        thruster_verbose_arg,
        imu,
        thruster,
    ])

# Copyright 2018 Open Source Robotics Foundation, Inc.
# Copyright 2019 Samsung Research America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
import os
import yaml
from launch.substitutions import EnvironmentVariable
import pathlib
import launch.actions
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='simple_planner',
            executable='planner_node',
            name='planner_node',
            output='screen',
           ),
        Node(
                package="tf2_ros",               
                executable="static_transform_publisher",
                arguments = ['--x', '0',
                             '--y', '0',
                             '--z', '0', 
                             '--yaw', '0', 
                             '--pitch', '0', 
                             '--roll', '0', 
                             '--frame-id', 'odom', 
                             '--child-frame-id', 'base_link']
        ),
        Node(
            package="tf2_ros",               
            executable="static_transform_publisher",
            arguments = ['--x', '0',
                            '--y', '0',
                            '--z', '0', 
                            '--yaw', '0', 
                            '--pitch', '0', 
                            '--roll', '0', 
                            '--frame-id', 'map', 
                            '--child-frame-id', 'odom']
        ),
])

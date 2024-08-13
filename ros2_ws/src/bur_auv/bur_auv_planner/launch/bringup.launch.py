#!/usr/bin/env python3

# MIT License
#
# Copyright (c) 2022 Clyde McQueen
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

"""
Bring up all nodes

Use a modified navigation_launch.py that doesn't launch velocity_smoother.
"""

import math
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, SetEnvironmentVariable
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml


def generate_launch_description():
    orca_bringup_dir = get_package_share_directory('orca_bringup')

    planner_dir = get_package_share_directory('bur_auv_planner')
    nav2_bt_file = os.path.join(planner_dir, 'behavior_trees', 'prequal_tree.xml')
    nav2_params_file = os.path.join(planner_dir, 'params', 'nav2_params.yaml')

    # orca_params_file = os.path.join(orca_bringup_dir, 'params', 'orca_params.yaml')

    # Rewrite to add the full path
    # The rewriter will only rewrite existing keys
    configured_nav2_params = RewrittenYaml(
        source_file=nav2_params_file,
        param_rewrites={
            'default_nav_to_pose_bt_xml': nav2_bt_file,
            'odom_topic': '/odom'
        },
        convert_types=True)

    return LaunchDescription([
        # Include the rest of Nav2
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(orca_bringup_dir, 'launch', 'navigation_launch.py')),
            launch_arguments={
                'namespace': '',
                'use_sim_time': 'False',
                'autostart': 'True',
                'params_file': configured_nav2_params,
                'use_composition': 'False',
                'use_respawn': 'False',
                'container_name': 'nav2_container',
            }.items(),
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(planner_dir, 'launch', 'planner.launch.py')),
        )
    ])

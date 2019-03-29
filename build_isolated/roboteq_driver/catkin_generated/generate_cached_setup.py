# -*- coding: utf-8 -*-
from __future__ import print_function
import argparse
import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/ros/kinetic/share/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/ros/kinetic/share/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in "/home/base/turtle_drive/devel_isolated/roboteq_msgs;/home/base/turtle_drive/devel_isolated/roboteq_diagnostics;/home/base/turtle_drive/devel_isolated/laser_proc;/home/base/turtle_drive/devel_isolated/hector_trajectory_server;/home/base/turtle_drive/devel_isolated/hector_slam_launch;/home/base/turtle_drive/devel_isolated/hector_slam;/home/base/turtle_drive/devel_isolated/hector_map_server;/home/base/turtle_drive/devel_isolated/hector_geotiff_plugins;/home/base/turtle_drive/devel_isolated/hector_geotiff;/home/base/turtle_drive/devel_isolated/hector_nav_msgs;/home/base/turtle_drive/devel_isolated/hector_marker_drawing;/home/base/turtle_drive/devel_isolated/hector_mapping;/home/base/turtle_drive/devel_isolated/hector_compressed_map_transport;/home/base/turtle_drive/devel_isolated/hector_map_tools;/home/base/turtle_drive/devel_isolated/hector_imu_tools;/home/base/turtle_drive/devel_isolated/hector_imu_attitude_to_tf;/home/base/turtle_drive/devel_isolated/driver_common;/home/base/turtle_drive/devel_isolated/driver_base;/opt/ros/kinetic".split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/base/turtle_drive/devel_isolated/roboteq_driver/env.sh')

output_filename = '/home/base/turtle_drive/build_isolated/roboteq_driver/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    #print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)

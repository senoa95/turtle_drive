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
    for workspace in "/home/base/turtle_drive/devel_isolated/hector_mapping;/home/base/turtle_drive/devel_isolated/hector_compressed_map_transport;/home/base/turtle_drive/devel_isolated/hector_map_tools;/home/base/turtle_drive/devel_isolated/hector_imu_tools;/home/base/turtle_drive/devel_isolated/hector_imu_attitude_to_tf;/home/base/turtle_drive/devel_isolated/driver_common;/home/base/turtle_drive/devel_isolated/driver_base;/opt/ros/kinetic".split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/base/turtle_drive/devel_isolated/hector_marker_drawing/env.sh')

output_filename = '/home/base/turtle_drive/build_isolated/hector_marker_drawing/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    #print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)

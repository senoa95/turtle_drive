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
    for workspace in "/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/waypoint_nav;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/waypoint_maker;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/velocity_controllers;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/uvc_camera;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/usb_cam;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/urg_node;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/urg_c;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/turtle_description;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/turtle_control;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/timestamp_tools;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/rtk;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/rqt_joint_trajectory_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ros_controllers;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/roboteq_driver;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/roboteq_msgs;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/roboteq_diagnostics;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/qtros;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/position_controllers;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_imu;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_gps_driver;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_gps_msgs;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/laser_proc;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/jpeg_streamer;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/joint_trajectory_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/joint_state_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/imu_sensor_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_trajectory_server;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_slam_launch;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_slam;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_map_server;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_geotiff_plugins;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_geotiff;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_nav_msgs;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_marker_drawing;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_mapping;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_compressed_map_transport;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_map_tools;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_imu_tools;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/hector_imu_attitude_to_tf;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/gripper_action_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/four_wheel_steering_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/effort_controllers;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/forward_command_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/force_torque_sensor_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/driver_common;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/driver_base;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ackermann_steering_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/diff_drive_controller;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/camera_umd;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ar_track_alvar;/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/ar_track_alvar_msgs;/opt/ros/kinetic".split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/nishanth/TurtleStuff/turtle_drive/devel_isolated/novatel_imu/env.sh')

output_filename = '/home/nishanth/TurtleStuff/turtle_drive/build_isolated/novatel_imu/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    #print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)

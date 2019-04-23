#!/usr/bin/env python

# Import libraries:
import rospy
import math
from geometry_msgs.msg import Pose,Twist,Point32
from sensor_msgs.msg import NavSatFix
from novatel_gps_msgs.msg import Inspva
from std_msgs.msg import Float32
from nav_msgs.msg import Odometry
from utilities import Point, DiffDriverVehicle, NavController
import transforms3d as tf
import numpy as np
import os
import rospkg
import utm
import time

rospack = rospkg.RosPack()

### Define constants:
pi = np.pi

# Define global variables:
global odom
odom = Odometry()
global currentPos
currentPos = Point32()
global file_name
# file_name = rospy.get_param("/file_name")
file_name = "/home/sena/turtle_drive/src/waypoint_nav/src/test_waypoints.txt"
# Callback function for subscriber to Position and orientation topic:

def pose_callback(data):

    global currentPos

    # rospy.loginfo(rospy.get_caller_id(), data.data)
    x = data.latitude
    y = data.longitude
    iniY,iniX, zoneNum , char = utm.from_latlon(x,y)
    currentPos.x = iniX
    currentPos.y = iniY

def heading_callback(data):
    global currentPos

    currentPos.z =  data.azimuth

def odom_callback(data):
    global odom

    odom.pose.x = data.Pose.Quaternion.x
    odom.pose.y = data.Pose.Quaternion.y
    odom.pose.z = data.Pose.Quaternion.z
    odom.pose.w = data.Pose.Quaternion.w
    odom.twist.x = data.Pose.Point.x
    odom.twist.y = data.Pose.Point.y
    odom.twist.z = data.Pose.Point.z

# 1. Initialize function definition:
def initialize():

    global file_name
    # Create objects for AckermannVehicle and Pure Pursuit controller:
    length = 1
    maxVel = 2
    mule = DiffDriverVehicle(length,maxVel)
    cntrl = NavController(length, maxVel)

    cntrl.initialize(os.path.join(rospack.get_path("waypoint_nav"),"src",file_name))

    return cntrl


# 2. Execute function definition:
def execute(cntrl):

    global currentPos
    global odom

    distance2Goal = 0
    heading_err_init = 0
    heading_err_goal = 0
    cmd_vel = Twist()
    cmd_vel.angular.x = 0;
    cmd_vel.angular.y = 0;
    cmd_vel.linear.y = 0
    cmd_vel.linear.z = 0

    # Initialize:
    # 1. Parameters:
    # euclideanError = 0
    # prev_heading_err_init = 0
    # heading_err_init_sum = 0
    # heading_err_init_diff = 0
    # heading_err_goal_sum = 0
    # adjusted_heading = False
    #
    # k_p_heading_init = 1
    # k_i_heading_init = 0.2
    # k_d_heading_init = 0.5
    # k_heading_init_low = 0.01
    # k_p_heading_goal = 0.05
    # k_i_heading_goal = 0.005
    # k_dist = 0.4

    k_p_h = 0.5
    k_i_h = 0.3
    k_d_h = 0.1
    k_p_l = 0.5
    heading_err_close = 0
    heading_err_far = 0
    prev_heading_err_close = 0
    prev_heading_err_far = 0
    heading_err_far_diff = 0
    heading_err_far_sum = 0
    heading_err_close_diff = 0
    heading_err_close_sum = 0


    # Setup the ROS publishers and subscribers:
    rospy.Subscriber("/fix", NavSatFix, pose_callback)
    rospy.Subscriber("/inspva", Inspva, heading_callback)
    # rospy.Subscriber("turtle_velocity_controller/odom", Odometry, odom_callback)
    pub_goal = rospy.Publisher('/current_goal',Point32,queue_size=10)
    pub_vel = rospy.Publisher('turtle_velocity_controller/cmd_vel', Twist,queue_size=10)
    rospy.init_node('waypoint_ctlr', anonymous=False)

    rate = rospy.Rate(10)


    # 2. Goal:
    goal = cntrl.wpList[cntrl.currWpIdx]

    # stationaryCommand.x = 0
    # stationaryCommand.y = 0

    # Loop through as long as the node is not shutdown:
    while not rospy.is_shutdown():

        # Compute the new Euclidean error:
        heading_goal = goal.heading * pi/180

        if heading_goal > pi:
            heading_goal = heading_goal - 2*pi

        curr_heading = currentPos.z * pi/180

        if curr_heading > pi:
            curr_heading = curr_heading - 2*pi

        current_goal = Point32(goal.x,goal.y,heading_goal)
        # print('current Index: ',cntrl.currWpIdx)


        pub_goal.publish(current_goal)

        heading_err_init, distance2Goal = cntrl.compute_err(currentPos, goal)

        if abs(distance2Goal > 4):
            heading_err_far = curr_heading - heading_err_init
            if heading_err_init > 0:
                cmd_vel.angular.z = k_p_h*heading_err_far + k_i_h*heading_err_far_sum + k_d_h*heading_err_far_diff
            else:
                cmd_vel.angular.z = -(k_p_h*heading_err_far + k_i_h*heading_err_far_sum + k_d_h*heading_err_far_diff)

            cmd_vel.linear.x = k_p_l*distance2Goal
        else:
            heading_err_close = curr_heading - heading_err_goal
            cmd_vel.angular.z = k_p_h*heading_err_close + k_i_h*heading_err_close_sum + k_d_h*heading_err_close_diff
            cmd_vel.linear.x = k_p_l*distance2Goal

            if abs(heading_err_close) < pi/10:
                print (" Reached Waypoint # ", cntrl.currWpIdx +1)
                # Update goal Point to next point in the waypoint list:
                cntrl.currWpIdx +=1
                if cntrl.currWpIdx < cntrl.nPts:
                    goal = cntrl.wpList[cntrl.currWpIdx]
                    print (" New goal ")
                    # print (goal.x)
                    # print (goal.y)
                    # print (goal.heading)
                else:
                    print (" --- All Waypoints have been conquered! Mission Accomplished Mr Hunt !!! --- ")
                    break

        print('initial heading error', heading_err_far)
        print('distance from goal', distance2Goal)
        print('current point', currentPos.x, currentPos.y)
        print('current heading', curr_heading)
        print('goal point', goal.x, goal.y)
        print('goal heading', heading_goal)
        print('goal heading error', heading_err_close)
        # # Case #1:Vehicle is in the vicinity of current goal point (waypoint):
        # if (abs(distance2Goal) < 4):
        #     heading_err_goal = curr_heading - heading_goal
        #     if abs(heading_err_goal) < pi/4:
        #         print (" Reached Waypoint # ", cntrl.currWpIdx +1)
        #         # Update goal Point to next point in the waypoint list:
        #         cntrl.currWpIdx +=1
        #         if cntrl.currWpIdx < cntrl.nPts:
        #             goal = cntrl.wpList[cntrl.currWpIdx]
        #             print (" New goal ")
        #             # print (goal.x)
        #             # print (goal.y)
        #             # print (goal.heading)
        #         else:
        #             print (" --- All Waypoints have been conquered! Mission Accomplished Mr Hunt !!! --- ")
        #             break
        #     else:
        #         # while abs(heading_err_goal) > 5:
        #         cmd_vel.angular.z = k_p_heading_goal*heading_err_goal + k_p_heading_goal*heading_err_goal_sum
        #         heading_err_goal_sum = heading_err_goal_sum +  heading_err_goal
        #         print('distance less than threshold, working on heading error')
        #
        #
        # else:
        #     if abs(heading_err_init) > 0.03:
        #         # while abs(heading_err_init) > 50:
        #         print('Far from waypoint. Working on initial heading')
        #         # print(odom.pose.w)
        #         cmd_vel.linear.x = 0
        #
        #         if heading_err_init > 0:
        #             cmd_vel.angular.z = (k_p_heading_init*heading_err_init + k_i_heading_init*heading_err_init_sum + k_d_heading_init*heading_err_init_diff)
        #         else:
        #             cmd_vel.angular.z = k_p_heading_init*heading_err_init + k_i_heading_init*heading_err_init_sum + k_d_heading_init*heading_err_init_diff
        #         adjusted_heading = True
        #     else:
        #         # print(distance2Goal)
        #         # while abs(distance2Goal) > 1:
        #         print('initial heading adjusted. Going to waypoint.')
        #         print('Distance to Goal', distance2Goal)
        #         if adjusted_heading:
        #             time.sleep(0.1)
        #             adjusted_heading = False
        #
        #         cmd_vel.angular.z = k_heading_init_low*heading_err_init;
        #         cmd_vel.linear.x = k_dist*distance2Goal;
        #
        # # Case #2:
        # #Compute the error between the goal and current
        # heading_err_init, distance2Goal = cntrl.compute_err(currentPos, goal)
        # heading_err_init_sum = heading_err_init + prev_heading_err_init
        # heading_err_init_diff = -heading_err_init + prev_heading_err_init
        # prev_heading_err_init = heading_err_init
        #
        # # Publish the computed command:
        # if abs(cmd_vel.angular.z) > 2:
        #     cmd_vel.angular.z = (cmd_vel.angular.z/abs(cmd_vel.angular.z))*2
        # if cmd_vel.linear.x > 2:
        #     cmd_vel.linear.x = (cmd_vel.linear.x/abs(cmd_vel.linear.x))*2
        # cmd_vel.linear.y = 0
        # cmd_vel.linear.z = 0
        # cmd_vel.angular.x = 0
        # cmd_vel.angular.y = 0
        pub_vel.publish(cmd_vel)
        time.sleep(0.3)
        rate.sleep()

    rospy.spin()

if __name__ == '__main__':

    # Step 1: Initialize the Controller by reading in the list of waypoints:
    cntrl = initialize()

    # Step 2: Execute the controller in a closed loop manner
    execute(cntrl)

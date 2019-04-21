#!/usr/bin/env python

# Import libraries:
import rospy
from geometry_msgs.msg import Point32,Pose,Point
from sensor_msgs.msg import NavSatFix
from novatel_gps_msgs.msg import Inspva
import csv
import math
import utm
import time
import os

global previous_x
global previous_y
global current_x
global current_y

previous_x = 0
previous_y = 0
current_x = 0
current_y = 0
previous_yaw = 0
current_yaw = 0

i = 0

#while os.path.exists("/home/agbot/agbot_deploy/src/agbot_nav/src/waypoints_%s.txt" % i):
 #   i += 1
  #  print(i)
  #waypoint_file =  open(os.path.join("/home/agbot/agbot_deploy/src/agbot_nav/src/agbot_nav/src/","waypoints_%s.txt" % i),"w")


# waypoint_file =  open("/home/trex/turtle_drive/src/waypoint_nav/src/test_waypoints.txt","w")
waypoint_file =  open("/home/sena/turtle_drive/src/waypoint_nav/src/test_waypoints.txt","w")

def pose_callback(data):

    global previous_x
    global previous_y
    global current_x
    global current_y
    global previous_yaw
    global current_yaw

    x = data.latitude
    y = data.longitude
    iniY,iniX, zoneNum , char = utm.from_latlon(x,y)
    current_x = iniX
    current_y = iniY

def heading_callback(angular_data):
    global current_yaw
    global previous_yaw

    current_yaw = angular_data.azimuth

def waypoint_maker():
    global previous_x
    global previous_y
    global previous_yaw
    global current_x
    global current_y
    global current_yaw

    rospy.init_node('waypoint_maker',anonymous=True)
    rospy.Subscriber("/fix", NavSatFix, pose_callback)
    rospy.Subscriber("/inspva", Inspva, heading_callback)

    while not rospy.is_shutdown():

        euclideanDistance = math.sqrt((math.pow((current_x-previous_x),2) + math.pow((current_y-previous_y),2)))
        yaw_delta = previous_yaw - current_yaw
        # print(current_x)
        # print("distance = ", euclideanDistance)

        if (euclideanDistance > 2) or (yaw_delta > 0.3) :
            print("distance = ", euclideanDistance)
            print("rotation = ", yaw_delta)

            waypoint_file.write(str(current_x)+","+str(current_y)+","+str(current_yaw)+"\r\n")
            previous_x = current_x
            previous_y = current_y
            previous_yaw = current_yaw

if __name__ == '__main__':
    waypoint_maker()

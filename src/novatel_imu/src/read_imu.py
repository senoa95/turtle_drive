#!/usr/bin/env python

import rospy
import serial
import time
import math
from geometry_msgs.msg import Point32
# Open Serial connection
ser = serial.Serial('/dev/ttyUSB2',115200,rtscts=True,dsrdtr=True)

#SETTING UP Novatel to take RTCM correction
ser.write('LOG USB3 INSPVAA ONTIME 0.05\r\n')

def read_imu():
    prev_roll = 0
    prev_pitch = 0
    prev_yaw = 0
    curr_roll = 0
    curr_pitch = 0
    curr_yaw = 0
    orientation = Point32()
    orientation.x = 0
    orientation.y = 0
    orientation.z = 0
    roll = 0
    pitch = 0
    yaw = 0

    ser.flush()
    imu_data_raw = ser.readline()
    imu_data = imu_data_raw.split(',')

    if len(imu_data) > 21:

        roll = float(imu_data[17])
        pitch = float(imu_data[18])
        yaw = float(imu_data[19])

    imu_pub = rospy.Publisher('/novatel_imu', Point32, queue_size=10)
    rospy.init_node ('novatel_imu', anonymous=True)
    rate = rospy.Rate(20)
    imu_data = 0
    imu_data_raw = 0

    while not rospy.is_shutdown():


        if ser.in_waiting:

            ser.flush()

            imu_data_raw = ser.readline()
            imu_data = imu_data_raw.split(',')
            prev_roll = curr_roll
            prev_pitch = curr_pitch
            prev_yaw = curr_yaw

            if len(imu_data) > 20:

               curr_roll = float(imu_data[17])
               curr_pitch = float(imu_data[18])
               curr_yaw = float(imu_data[19])

               curr_yaw  = curr_yaw * 2*math.pi / 360

               if curr_yaw > math.pi:
                   curr_yaw = curr_yaw - 2*math.pi


            orientation.x = curr_roll
            orientation.y = curr_pitch
            orientation.z = curr_yaw

            rospy.loginfo(orientation)
            imu_pub.publish(orientation)


if __name__ == '__main__':
    try:
        read_imu()
    except rospy.ROSInterruptException:
        pass

#!/usr/bin/env python

import rospy
import serial
import socket
from socket import error as socket_error

###Trimble TCP Connection Initialization
TCP_IP = '192.168.1.201'

TCP_PORT = 5017 #this is the port number inside the trimble configuration

BUFFER_SIZE = 4096

# Open TCP Socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
s.connect((TCP_IP, TCP_PORT))

# Open Serial connection
ser = serial.Serial('/dev/ttyUSB0',115200,rtscts=True,dsrdtr=True)

#SETTING UP Novatel to take RTCM correction
ser.write('INTERFACEMODE USB1 RTCM NOVATEL ON\r\n')
ser.write('INSCOMMAND ENABLE\r')
ser.write('LOG USB1 INSPVA ONTIME \r\n')

while True:
    #Recieve RTCM and write RTCM data to serial
    RTCM = s.recv(BUFFER_SIZE)
    ser.write(RTCM)


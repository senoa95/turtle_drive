#!/usr/bin/env python

file = open("/home/sena/turtle_drive/src/waypoint_nav/src/test_waypoints.txt","r")
file2 = open("/home/sena/turtle_drive/src/waypoint_nav/src/test_waypoints_normalized.txt","w")

data = file.readline()
data_sp = data.split(',')
start_x = float(data_sp[0])
start_y = float(data_sp[1])
for x in range (0,132):
    data = file.readline()
    data_sp = data.split(',')
    print(data_sp[0])
    curr_x = float(data_sp[0])
    curr_y = float(data_sp[1])
    curr_heading = float(data_sp[2])
    curr_x = curr_x - start_x
    curr_y = curr_y - start_y
    file2.write(str(curr_x)+","+str(curr_y)+"\r\n")

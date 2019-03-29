import numpy as np
import math
import utm

### Define constants:
pi = np.pi

#class to define vehicle position on a coordinate system at a certain heading
class Point:

    def __init__(self,inputX = 0,inputY = 0,inputHeading = 0):
        self.x = inputX
        self.y = inputY
        self.heading = inputHeading

# class to define vehicle parameters
class DiffDriverVehicle:
    def __init__(self,inputLength = 2.065, inputMaximumVelocity = 0.5):
        self.length = inputLength
        self.maximumVelocity = inputMaximumVelocity
        # self.minTurningRadius = self.length / math.tan(self.maximumSteeringAngle)

# class to define Pure pursuit controller parameters
class NavController:

    # Constructor:
    def __init__(self,inputLength = 2.065, inputMaximumVelocity = 0.5):
        self.length = inputLength #set the length for ppcontroller as the length of maximumSteeringAngle
        self.maximumVelocity = inputMaximumVelocity

        # List of waypoints: From start to end:
        self.wpList = []

        # Current target waypoint index:
        self.currWpIdx = 0

        # List of normal vectors to segments joining the waypoints:
        self.segNormVecList = None

        # Number of waypoints:
        self.nPts = 0

    # Initialize the controller from a text file containing the waypoints:
    def initialize(self,fileName):

        wpFile = open(fileName, 'r')

        wPts = wpFile.readlines()

        for wp in wPts:

            spLine = wp.split( ',')

            self.wpList.append(Point(float(spLine[0]) , float(spLine[1]), float(spLine[2])))

        self.nPts = len(self.wpList)

    def compute_err(self, current):
        # Compute vector from current position to current waypoint:
        vecRobot2Wp = np.zeros((2,1))
        vecRobot2Wp[0,0] =  self.wpList[self.currWpIdx].x - current.x
        vecRobot2Wp[1,0] =  self.wpList[self.currWpIdx].y - current.y

        distance2Goal = pow(pow(vecRobot2Wp[0,0],2), pow(vecRobot2Wp[1,0],2), 0.5)

        theta_des_init = math.atan2(self.wpList[idx].y - current.y, self.wpList[idx].x - current.x)
        heading_err_init = theta_des_init - current.heading
        if heading_err_init > pi:
            heading_err_init = heading_err_init - 2*pi
        elif heading_err_init < -pi:
            heading_err_init = heading_err_init + 2*pi


        return heading_err_init, distance2Goal

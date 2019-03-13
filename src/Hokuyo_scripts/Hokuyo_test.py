import rospy
import numpy as np
from sensor_msgs.msg import LaserScan


class Hokuyo:



	def __init__(self):
		rospy.Subscriber("/scan", LaserScan, self.Hokuyo)
		print"Subscribed"




	def Hokuyo(self, scan):
		print "This seems to work"

		mindist = 0.002


		minVal = min(scan.ranges)
		print minVlal


		if minVal>mindist:
			print "You are too close"

			




if __name__ == "__main__":
    rospy.init_node("Hokuyo")
    node = Hokuyo()
    rospy.spin()












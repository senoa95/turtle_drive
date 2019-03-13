import rospy
import numpy as np
from sensor_msgs.msg import Joy


class JoyTeleop:



	def __init__(self):
		rospy.Subscriber("/joy", Joy, self.Teleop)
		print"Subscribed"




	def Teleop(self, data):
		# print data.axes[1];

		pitch = data.axes[1]
		slowButton = data.buttons[0]

		if (pitch>0) and (slowButton == 1):
			print "Slow Forward"
		elif pitch>0:
			print "Forward"
		elif (pitch<0) and (slowButton == 1):
			print "Slow Reverse"
		elif pitch<0:
			print "Reverse"


	


			




if __name__ == "__main__":
    rospy.init_node("JoyTeleop")
    node = JoyTeleop()
    rospy.spin()












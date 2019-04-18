import rospy
import numpy as np
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Point32,Pose,Point
from geometry_msgs.msg import Quaternion
from tf.transformations import quaternion_from_euler

class p32toQuat:




	def __init__(self):
		rospy.Subscriber("/novatel_imu", Point32, self.convert)
		
		print"Subscribed"




	def convert(self, data):
		x = data.x
		y = data.y
		z = data.z
		quaternion = quaternion_from_euler(x, y, z)
		quat_msg = Quaternion(quaternion[0], quaternion[1], quaternion[2], quaternion[3])

		# print quaternion
		imu_quat = rospy.Publisher("/IMU_Quat", Quaternion, queue_size=10)
		imu_quat.publish(quat_msg)






if __name__ == "__main__":
    rospy.init_node("p32toQuat")
    node = p32toQuat()
    rospy.spin()












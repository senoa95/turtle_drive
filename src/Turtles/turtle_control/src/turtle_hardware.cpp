/**
 *
 *  \file
 *  \brief      Class representing Jackal hardware
 *  \author     Mike Purvis <mpurvis@clearpathrobotics.com>
 *  \copyright  Copyright (c) 2013, Clearpath Robotics, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Clearpath Robotics, Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CLEARPATH ROBOTICS, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Please send comments, questions, or patches to code@clearpathrobotics.com
 *
 */

#include <boost/assign.hpp>
#include "turtle_control/turtle_hardware.h"
#include <iostream>

namespace turtle_control
{

TurtleHardware::TurtleHardware()
{
  ros::V_string joint_names = boost::assign::list_of("front_left_wheel")
      ("front_right_wheel")("rear_left_wheel")("rear_right_wheel");

  for (unsigned int i = 0; i < joint_names.size(); i++) {
    hardware_interface::JointStateHandle joint_state_handle(joint_names[i],
        &joints_[i].position, &joints_[i].velocity, &joints_[i].effort);
    joint_state_interface_.registerHandle(joint_state_handle);

    hardware_interface::JointHandle joint_handle(
        joint_state_handle, &joints_[i].velocity_command);
    velocity_joint_interface_.registerHandle(joint_handle);
  }
  registerInterface(&joint_state_interface_);
  registerInterface(&velocity_joint_interface_);

  left_feedback_sub_ = nh_.subscribe("left/feedback", 1, &TurtleHardware::feedbackCallback_left, this);
  right_feedback_sub_ = nh_.subscribe("right/feedback", 1, &TurtleHardware::feedbackCallback_right, this);
  corrimudata_sub_ = nh_.subscribe("/corrimudata", 1, &TurtleHardware::corrimudataCallback, this);
  inspva_sub_ = nh_.subscribe("/inspva", 1, &TurtleHardware::inspvaCallback, this);
  cmd_vel_sub_ = nh_.subscribe("/turtle_velocity_controller/cmd_vel", 1, &TurtleHardware::cmdvelCallback, this);
  left_motor_pub = nh_.advertise<roboteq_msgs::Command>("/left/cmd", 1000);
  right_motor_pub = nh_.advertise<roboteq_msgs::Command>("/right/cmd", 1000);
  compiled_imu_pub = nh_.advertise<sensor_msgs::Imu>("/compiled_imu", 1000);
}

void TurtleHardware::subscribeToImu()
{
  boost::mutex::scoped_lock corrimudata_msg_lock(corrimudata_msg_mutex_, boost::try_to_lock);
  tf2::Quaternion quat;
  sensor_msgs::Imu imu_msg;
  int imu_rate_ = 20;
  corrimudata_.pitch_rate = corrimudata_msg_.pitch_rate * imu_rate_;
  corrimudata_.roll_rate = corrimudata_msg_.roll_rate * imu_rate_;
  corrimudata_.yaw_rate = corrimudata_msg_.yaw_rate * imu_rate_;
  corrimudata_.lateral_acceleration = corrimudata_msg_.lateral_acceleration;
  corrimudata_.longitudinal_acceleration = corrimudata_msg_.longitudinal_acceleration;
  corrimudata_.vertical_acceleration = corrimudata_msg_.vertical_acceleration;
  boost::mutex::scoped_lock inspva_data_msg_lock(inspva_data_msg_mutex_, boost::try_to_lock);
  inspva_data_.pitch = inspva_data_msg_.pitch;
  inspva_data_.roll = inspva_data_msg_.roll;
  inspva_data_.azimuth = inspva_data_msg_.azimuth;
  inspva_data_.x_vel = inspva_data_msg_.north_velocity;
  inspva_data_.y_vel = inspva_data_msg_.east_velocity;
  inspva_data_.z_vel = inspva_data_msg_.up_velocity;
  quat.setRPY(inspva_data_.roll, inspva_data_.pitch, inspva_data_.azimuth); // create quaternion
  imu_msg.header.stamp = ros::Time::now();
  imu_msg.header.frame_id = "base_link";
  imu_msg.orientation.x = quat[0];
  imu_msg.orientation.y = quat[1];
  imu_msg.orientation.z = quat[2];
  imu_msg.orientation.w = quat[3];
  imu_msg.angular_velocity.x = corrimudata_.roll_rate;
  imu_msg.angular_velocity.y = corrimudata_.pitch_rate;
  imu_msg.angular_velocity.z = corrimudata_.yaw_rate;
  imu_msg.linear_acceleration.x = corrimudata_.lateral_acceleration;
  imu_msg.linear_acceleration.y = corrimudata_.longitudinal_acceleration;
  imu_msg.linear_acceleration.z = corrimudata_.vertical_acceleration;
  compiled_imu_pub.publish(imu_msg);
}

/**
 * Populates the internal joint state struct from the most recent Feedback message
 * received from the MCU.
 *
 * Called from the controller thread.
 */
void TurtleHardware::copyJointsFromHardware()
{
  boost::mutex::scoped_lock left_feedback_msg_lock(left_feedback_msg_mutex_, boost::try_to_lock);
      joints_[0].position = -(left_feedback_msg_.measured_position/20);
      joints_[0].velocity = -(left_feedback_msg_.measured_velocity/20);
      joints_[0].effort = 0;  // TODO(mikepurvis): determine this from amperage data.
      joints_[2].position = -(left_feedback_msg_.measured_position/20);
      joints_[2].velocity = -(left_feedback_msg_.measured_velocity/20);
      joints_[2].effort = 0;  // TODO(mikepurvis): determine this from amperage data
  boost::mutex::scoped_lock right_feedback_msg_lock(right_feedback_msg_mutex_, boost::try_to_lock);
      joints_[1].position = right_feedback_msg_.measured_position/20;
      joints_[1].velocity = right_feedback_msg_.measured_velocity/20;
      joints_[1].effort = 0;  // TODO(mikepurvis): determine this from amperage data.
      joints_[3].position = right_feedback_msg_.measured_position/20;
      joints_[3].velocity = right_feedback_msg_.measured_velocity/20;
      joints_[3].effort = 0;  // TODO(mikepurvis): determine this from amperage data.
  }

/**
 * Populates and publishes Drive message based on the controller outputs.
 *
 * Called from the controller thread.
 */
void TurtleHardware::publishDriveFromController()
{
	roboteq_msgs::Command left_msg;
  roboteq_msgs::Command right_msg;
  left_msg.mode=0;
  right_msg.mode=0;
	left_msg.setpoint=(-joints_[0].velocity_command)*.9091*20;
	right_msg.setpoint=(joints_[3].velocity_command)*.9091*20;
  left_motor_pub.publish(left_msg);
  right_motor_pub.publish(right_msg);
}


void TurtleHardware::publishDriveFromMath()
{
	roboteq_msgs::Command left_msg;
  roboteq_msgs::Command right_msg;
  double curr_time = ros::Time::now().toSec();
  double prev_time;
  float des_vel;
  float xVel_err;
  float xVel;
  float prev_xVel_err;
  float thetaDot_err;
  float prev_thetaDot_err;
  float xVel_err_diff;
  float thetaDot_err_diff;
  float xVel_err_sum;
  float thetaDot_err_sum;
  float cmd_lin_vel;
  float cmd_ang_vel;



  int yaw_rate = 20;
  double L = 0.7; //0.7 meters wheel separation
  double R = 0.41; //0.41 meter diameter
  double del_time = curr_time - prev_time;

  float kp_lin_vel = 1;
  float ki_lin_vel = 0.1;
  float kd_lin_vel = 0.2;

  float kp_ang_vel = 1;
  float ki_ang_vel = 0.1;
  float kd_ang_vel = 0.2;

  float thetaDot = corrimudata_msg_.yaw_rate * yaw_rate;
  float des_xVel = cmd_vel_msg_.linear.x;
  float des_thetaDot = cmd_vel_msg_.angular.z;

  std::cout << "here" << '\n';

  xVel = (((2*R*joints_[0].velocity - thetaDot*L) / 2) + ((2*R*joints_[1].velocity + thetaDot*L) / 2))/2;

  xVel_err = des_xVel - xVel;
  thetaDot_err = des_thetaDot - thetaDot;

  xVel_err_diff = xVel_err - prev_xVel_err;
  thetaDot_err_diff = thetaDot_err - prev_thetaDot_err;
  xVel_err_sum = xVel_err_sum + xVel_err;
  thetaDot_err_sum = thetaDot_err_sum + thetaDot_err;

  cmd_lin_vel = kp_lin_vel*xVel_err + ki_lin_vel*xVel_err_sum + kd_lin_vel*xVel_err_diff;
  cmd_ang_vel = kp_ang_vel*thetaDot_err + ki_ang_vel*thetaDot_err_sum + kd_ang_vel*thetaDot_err_diff;

  left_msg.mode=0;
  right_msg.mode=0;
	left_msg.setpoint= (2*cmd_lin_vel - cmd_ang_vel*L) / (2*R);
	right_msg.setpoint= (2*cmd_lin_vel + cmd_ang_vel*L) / (2*R);;
  left_motor_pub.publish(left_msg);
  right_motor_pub.publish(right_msg);
}

void TurtleHardware::corrimudataCallback(const novatel_gps_msgs::NovatelCorrectedImuData msg)
{
  // Update the feedback message pointer to point to the current message. Block
  // until the control thread is not using the lock.
  boost::mutex::scoped_lock corrimu_lock(corrimudata_msg_mutex_);
  corrimudata_msg_ = msg;
}

void TurtleHardware::inspvaCallback(const novatel_gps_msgs::Inspva msg)
{
  // Update the feedback message pointer to point to the current message. Block
  // until the control thread is not using the lock.
  boost::mutex::scoped_lock inspva_lock(inspva_data_msg_mutex_);
  inspva_data_msg_ = msg;
}

void TurtleHardware::feedbackCallback_left(const roboteq_msgs::Feedback msg)
{
  // Update the feedback message pointer to point to the current message. Block
  // until the control thread is not using the lock.
  boost::mutex::scoped_lock left_lock(left_feedback_msg_mutex_);
  left_feedback_msg_ = msg;

}

void TurtleHardware::feedbackCallback_right(const roboteq_msgs::Feedback msg)
{
  // Update the feedback message pointer to point to the current message. Block
  // until the control thread is not using the lock.
  boost::mutex::scoped_lock right_lock(right_feedback_msg_mutex_);
  right_feedback_msg_ = msg;
}

void TurtleHardware::cmdvelCallback(const geometry_msgs::Twist msg)
{

  boost::mutex::scoped_lock cmdvel_lock(cmd_vel_msg_mutex_);
  cmd_vel_msg_ = msg;
}
}

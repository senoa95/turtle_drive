;; Auto-generated. Do not edit!


(when (boundp 'roboteq_msgs::Command)
  (if (not (find-package "ROBOTEQ_MSGS"))
    (make-package "ROBOTEQ_MSGS"))
  (shadow 'Command (find-package "ROBOTEQ_MSGS")))
(unless (find-package "ROBOTEQ_MSGS::COMMAND")
  (make-package "ROBOTEQ_MSGS::COMMAND"))

(in-package "ROS")
;;//! \htmlinclude Command.msg.html


(intern "*MODE_STOPPED*" (find-package "ROBOTEQ_MSGS::COMMAND"))
(shadow '*MODE_STOPPED* (find-package "ROBOTEQ_MSGS::COMMAND"))
(defconstant roboteq_msgs::Command::*MODE_STOPPED* -1)
(intern "*MODE_VELOCITY*" (find-package "ROBOTEQ_MSGS::COMMAND"))
(shadow '*MODE_VELOCITY* (find-package "ROBOTEQ_MSGS::COMMAND"))
(defconstant roboteq_msgs::Command::*MODE_VELOCITY* 0)
(intern "*MODE_POSITION*" (find-package "ROBOTEQ_MSGS::COMMAND"))
(shadow '*MODE_POSITION* (find-package "ROBOTEQ_MSGS::COMMAND"))
(defconstant roboteq_msgs::Command::*MODE_POSITION* 1)
(defclass roboteq_msgs::Command
  :super ros::object
  :slots (_mode _setpoint ))

(defmethod roboteq_msgs::Command
  (:init
   (&key
    ((:mode __mode) 0)
    ((:setpoint __setpoint) 0.0)
    )
   (send-super :init)
   (setq _mode (round __mode))
   (setq _setpoint (float __setpoint))
   self)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:setpoint
   (&optional __setpoint)
   (if __setpoint (setq _setpoint __setpoint)) _setpoint)
  (:serialization-length
   ()
   (+
    ;; int8 _mode
    1
    ;; float32 _setpoint
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _mode
       (write-byte _mode s)
     ;; float32 _setpoint
       (sys::poke _setpoint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _mode
     (setq _mode (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _mode 127) (setq _mode (- _mode 256)))
   ;; float32 _setpoint
     (setq _setpoint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get roboteq_msgs::Command :md5sum-) "9f57e6568807eb250db6d5bd382ee299")
(setf (get roboteq_msgs::Command :datatype-) "roboteq_msgs/Command")
(setf (get roboteq_msgs::Command :definition-)
      "
# Control whether the setpoint represents a velocity or position command.
# Velocity is the default, but position may be used for fine-grained movements,
# or active braking on an incline. Stopped is high-z (coasting).
int8 MODE_STOPPED=-1
int8 MODE_VELOCITY=0
int8 MODE_POSITION=1
int8 mode

# Commanded velocity (rad/s) or position (rad) for the motor. Position uses
# the same scale as measured_position in the Feedback message.
float32 setpoint

")



(provide :roboteq_msgs/Command "9f57e6568807eb250db6d5bd382ee299")



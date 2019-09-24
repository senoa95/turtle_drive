# /bin/bash

#install catkin build
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu `lsb_release -sc` main" > /etc/apt/sources.list.d/ros-latest.list'
wget http://packages.ros.org/ros.key -O - | sudo apt-key add -
sudo apt-get update
sudo apt-get install python-catkin-tools

#install dependencies
sudo apt-get install ros-kinetic-geographic-msgs
sudo apt-get install ros-kinetic-novatel-msgs
sudo apt-get install ros-kinetic-swri-*
sudo apt-get install libv4l-dev
sudo apt-get install ros-kinetic-serial*
sudo apt-get install ros-kinetic-hardware-interface
sudo apt-get install ros-kinetic-controller-manager
sudo apt-get install libpcap-dev

#cd into workspace and build turtle_drive
cd ~/workspace
catkin build




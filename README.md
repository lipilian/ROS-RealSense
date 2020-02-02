# ROS-RealSense
 Intel Realsense system combine with ROS system

# hardware
- Camera (Use commercial camera for test)
- raspberry pi 4 (USB 3.0 better for Intel RealSense) (failed due to OS system)
- raspberry pi 3b+
- ROS control board
- Lidar (2D)
- 2 server motor control the track

#software

1. PC level
- VMware Workstation Pro(Windows 10 base)
- Ubuntu 16.04 64x
  - VMware tools

2. Raspberry level
- image burn etcher 15.2 (which can verify entire system) (x64)
- ubuntu mate 16.04
- burn into sd card and install it into raspberry pi and input the password for wifi.
- command line check ip address:  192.168.10.21 (Internet addre)
```
$ifconig
```
- check pc wifi address : 192.168.10.11
```
ipconfig
```
- change ip set to robot ip address
- VMware ubuntu system:
```
$sudo gedit /etc/hosts
```
- change robot ip t0 192.169.10.21
- connect with ssh
```
ssh robot@192.169.10.21

3. use
- main node (VMware)
```
roslaunch clbrobot bringup.launch
```
- change bashrc point to Ros ip address then source the bashrc
```
rosrun rviz rviz
```
- open odometry.rviz file to visulaize the control

- control
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
- turn off
```
sudo halt
```
- IMU (Inertial Measurement Unit) calibrate
```
roscd clbrobot/
cd param
cd imu
rosrun imu_calib do_calib
```
- rerun bringup.launch
- Angular velocity calibrate
```
rosrun rikirobot_nav calibrate_angular.py
```
new terminal run on VMware
```
rosrun rqt_reconfigure rqt_reconfigure
```
test get : it actually turn 365 degree instead of 360 , angular velocity scale change from 1.0 to 1.014
- change the param in launch file
```
roscd clbrobot/
cd launch/
vi bringup.launch
```
- change the angular velocity scale to 1.014

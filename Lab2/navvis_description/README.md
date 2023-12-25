<h1>About</h1>
This is lab2 for Modern Robot programming which consists of creating a Navvis Robot with a URDF and XACRO's. The robot contains Hokuyo LIDAR and a Velodyne LIDAR.

<h2>How to use the launch files</h2>

After configuring ROS with /opt/ros/noetic/setup.bash

Enter the command $roslaunch navvis_description display.launch use_xacro:=true
This will open rviz using the xacro to display the navvis robot

The command takes the form $roslaunch <package_name> <file> <arg use_xacro>
The package name is navvis_description, the launch file is display.launch, the argument use_xacro is set to true
so that wheels using xacro macros will show. 
Entering the command like that will by default launch the joint_state_publisher gui

To not have the gui enter $roslaunch navvis_description display.launch use_xacro:=true use_joint_state_publisher_gui:=false
 

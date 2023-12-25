<h1>Navvis_bags</h1>

<h2>To view the robot and sensor data:</h2>
Setup ROS enviroment

<p>Enter command roslaunch <package> <launch.file> <args><br>
roslaunch navvis_bags navvis_bags_launch.launch</p>

<h3>To view the model without joint_state_publisher_gui </h3>

set use_joint_state_publisher_gui:=false in the arguments

<h3>To view the model with the previous launch file from the previous lab</h3>
<p>For simplicity, the file has been moved to the same workspace<br>
Call lab2_launch in the roslaunch command</p>

<h2>Arguments</h2>
The navvis_bags_launch file takes in all arguments from the previous lab
<p>
  use_xacro<br>
  use_robot_state_publisher<br>
  use_joint_state_publisher_gui<br>

and adds use_sim_time<br>

use_xacro allows the user to view the robot with the xacro file if true and the urdf if false<br>

use_robot_state_publisher allows the users to see the transforms from the urdf files if true and sees the static transforms if false<br>

use_joint_state_publisher_gui allows the user to use the joint state publisher gui<br>

use_sim_time allows the user to use an external clock to play the rosbags<br>

The node that calls the rosbag includes the location of the bag file as an argument instead of being entered manually for safety purposes.
</p>

<h2>**BAGS AND MAP DATA ARE NOT INCLUDED FOR PRIVACY REASONS**</h2>

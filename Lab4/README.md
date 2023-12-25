#About
This Lab4 for Modern Robot Programming consisting of a package for a robot that will move and not crash into walls.

# How To Use robot_no_crash Package

## Setup
Make sure ROS-Noetic is setup up and workspace is configured<br>
Run roscore in the background<br>

## Launch
There are two launch files in this package<br>
main.launch and robot_supervisor.launch.<br>

main.launch includes the robot_supervisor.launch file<br>
It also includes the server_with_map_and_gui_plus_robot.launch file.<br>
The purpose of main.launch is to combine these two launch files and launch<br>
them with one command.<br>

robot_supervisor.launch launches two nodes<br>
The first node is the robot_no_crash_node with contains the publisher and subscribers<br>
for the robot.<br>
The second node is the rqt gui to control the movement of the robot manually.<br>

### Parameters
The only parameter is wall_dist which determines the length at when the robot should stop<br>

## How To Use
Use the roslaunch command to roslaunch the main launch file<br>
roslaunch robot_no_crash main.launch<br>
The rqt gui should automatically show and the robot should move based off the rqt gui<br>





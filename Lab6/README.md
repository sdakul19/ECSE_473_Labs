# How to use the ik_service package

# About
This is the second part of the ARIAC project. Lab 6 for ecse473

## How the package works
The ik_service package uses a service and client to acquire joint angles to move the UR10 robot in the [Ariac competition](https://bitbucket.org/osrf/ariac/wiki/2019/documentation).
The package also uses the ur_kinematics package from the [ecse_373_ariac](https://github.com/cwru-eecs-373/ecse_373_ariac/tree/noetic-devel/ur_kinematics) package.
Within the package is defined a `JointSolutions` message that is used in the `PoseIK` service. The service is called in the `ik_service` node and the `ik_client` outputs the result.

## Package Contents

### Launch
The launch directory contains the `ik_service.launch` file. This file only launches the `ik_service` node and outputs the result to the screen.

### msg
The msg directory defines the `JointSolutions.msg` message. <br>
```
# Message for Joint Solutions

# A vector of joint angles
float64[6] joint_angles
```
The message contains a vector 6 elements wide that holds 6 float numbers. The 6 numbers are a set of joint angles.

### srv
The srv directory defines the `PoseIK.srv` service. <br>
```
# Pose Service

# Request Part Pose
geometry_msgs/Pose part_pose

---
# Number of solutions returned
int8 num_sols

# The joint angles to reach solution
ik_service/JointSolutions[8] joint_solutions
```
The service has a request element that is of type `geometry_msgs/Pose` and returns a response with elements `num_sol` and `joint_solutions` 
which are of type int8 and ik_service/JointSolutions[8] respectively. <br>
The num_sols corresponds to the number of solutions of joint angles that the service aquires.<br>
The joint_solutions stores up to 8 sets of `joint_angles`.

### src

#### ik_service
The ik_service node currently sets a T matrix and returns a set of joint angles that are solutions for the robot to move.

```
double T[4][4] = {{0.0, -1.0, 0.0, req.part_pose.position.x}, \
                        {0.0, 0.0, 1.0, req.part_pose.position.y}, \
                        {-1.0, 0.0, 0.0, req.part_pose.position.z}, \
                        {0.0, 0.0, 0.0, 0.0}};
```
The current T matrix configurations has the vaccuum gripper of the robot facing down and uses the request positioning.
The service then calls the `num_sol = ur_kinematics::inverse(&T[0][0], (double *)&q_sols[0][0], 0.0);` function from the `ur_kinematics` package to acquire a set of joint_solutions.

To verify that the ik_service node is working type in `rosrun ik_service ik_service &` and the output should notify that the service is being activated.

#### ik_client
The ik_client node currently sets the x position of the request to 0.5 and then calls the service. 
For now only one set of joint solutions is outputted.<br>

To verify that the ik_client node is working type in `rosrun ik_service ik_client &` and the output should be 6 joint angles.

## How to launch
To launch, make sure ROS is configured in a work space. Then type `roslaunch ik_service ik_service.launch &`. <br>
After that, only the ik_service node should be activated. To test the client node type in `rosrun ik_service ik_client &` and the output should be 6 joint angles.


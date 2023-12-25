#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <sensor_msgs/LaserScan.h>


ros::Publisher *p_pub;  
geometry_msgs::Twist msg;
sensor_msgs::LaserScan laser_data;
geometry_msgs::Twist desired_velocity;
double wall_dist = 0.0; 
bool move = true;

void chatterCallback(const geometry_msgs::Twist::ConstPtr& msg) {
  desired_velocity = *msg;
  if(!move && (desired_velocity.linear.x > 0)) {
    desired_velocity.linear.x = 0.0;
    ROS_INFO_THROTTLE(1.0, "Stopping... don't hit the wall!!");
  } else {
    ROS_INFO_THROTTLE(1.0, "Nothing in the way");
  }
  p_pub->publish(desired_velocity);
}

void laserCallback(sensor_msgs::LaserScan laser_data) {
  
  move = true;
  for(int index = 45; index < 225; index++) {
    if(laser_data.ranges[index] < wall_dist) {
      move = false;
      break;
    }

  }

}

int main(int argc, char **argv)
{

ros::init(argc, argv, "robot_node");
ros::NodeHandle n;
ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
ros::Subscriber sub = n.subscribe("des_vel", 1000, chatterCallback);
ros:: Subscriber laser_sub = n.subscribe("laser_0", 1000, laserCallback);
p_pub = &chatter_pub;


ROS_INFO_ONCE("wall_dist begin with: [%2.2f]", wall_dist);
n.param("/wall_dist", wall_dist, 1.0);
ROS_INFO_ONCE("wall_dist is now: [%2.2f]", wall_dist);
if (n.getParam("/wall_dist", wall_dist))
{
  ROS_INFO("wall_dist is: [%2.2f]", wall_dist);
} 
else
{
  ROS_ERROR("Failed to get param 'wall_dist'");
}

ros::Rate loop_rate(10);
int count = 0;
while (ros::ok())
{
if (n.getParamCached("wall_dist", wall_dist)) {
  ROS_INFO("wall_dist was update to: [%2.2f]", wall_dist);
}

chatter_pub.publish(msg);

ros::spinOnce();
loop_rate.sleep();
++count;
}


  return 0;
}

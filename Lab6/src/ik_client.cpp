#include "ros/ros.h"
#include "ik_service/PoseIK.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "ik_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<ik_service::PoseIK>("pose_ik");
    ik_service::PoseIK ik_pose;
    geometry_msgs::Pose part_pose;

    part_pose.position.x = 0.5;
    ik_pose.request.part_pose = part_pose;
    
    if(client.call(ik_pose)) {
        ROS_INFO("Service request received...");
        ROS_INFO("Call to ik_service returned [%i] solutions", ik_pose.response.num_sols);
        ROS_INFO_STREAM("On set of joint solutions is\n" << ik_pose.response.joint_solutions[0]);
    } else {
        ROS_ERROR("Failed to call the service ik_service");
        return 1;
    }

    return 0;
}
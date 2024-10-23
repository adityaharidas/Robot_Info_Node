#include "robot_info/robot_info.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  RobotInfo robot_info(&nh, "Mir100", "567A359", "169.254.5.180", "3.5.8");

  ros::Rate rate(2);

  ROS_INFO("Publishing Data");
  while (ros::ok()) {
    robot_info.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
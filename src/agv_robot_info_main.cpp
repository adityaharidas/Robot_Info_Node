#include "robot_info/agv_robot_info.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;

  // Create an instance of AGVRobotInfo with the necessary parameters
  AGVRobotInfo agv_robot_info(&nh, "Mir100", "567A359", "169.254.5.180",
                              "3.5.8", "100 Kg");

  ros::Rate rate(2);

  ROS_INFO("Publishing AGV Data");
  while (ros::ok()) {
    agv_robot_info.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}

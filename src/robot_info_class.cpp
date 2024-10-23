#include "robot_info/robot_info.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>
RobotInfo::RobotInfo(ros::NodeHandle *nh, std::string robot_description,
                     std::string serial_number, std::string ip_address,
                     std::string firmware_version) {
  this->nh = nh;
  robot_info_publisher =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 1000);

  this->robot_description = robot_description;
  this->serial_number = serial_number;
  this->ip_address = ip_address;
  this->firmware_version = firmware_version;
}
void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  robot_info_publisher.publish(msg);
  ROS_INFO("Data published");
}

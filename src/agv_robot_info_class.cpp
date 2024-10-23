#include "hydraulic_system_monitor.cpp"
#include "robot_info/agv_robot_info.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

// Constructor definition
AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
                           std::string serial_number, std::string ip_address,
                           std::string firmware_version,
                           std::string max_payload)
    : RobotInfo(nh, robot_description, serial_number, ip_address,
                firmware_version)
{     
  this->maximum_payload = max_payload;
}

// Overriding publish_data() method
void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;
  HydraulicSystemMonitor hydraulic_monitor = HydraulicSystemMonitor();
  // Including the parent class fields
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;

  // Adding derived class field
  msg.data_field_05 = "maximum_payload: " + maximum_payload;

  // Retrieve hydraulic data
  msg.data_field_06 = "hydraulic_oil_temperature: " +
                      hydraulic_monitor.get_hydraulic_oil_temperature();
  msg.data_field_07 = "hydraulic_oil_tank_fill_level: " +
                      hydraulic_monitor.get_hydraulic_oil_tank_fill_level();
  msg.data_field_08 = "hydraulic_oil_pressure: " +
                      hydraulic_monitor.get_hydraulic_oil_pressure();

  // Empty fields for remaining data
  msg.data_field_09 = "";
  msg.data_field_10 = "";

  robot_info_publisher.publish(msg);
  ROS_INFO("AGV Data Published");
}

#pragma once
#include<ros/ros.h>
#include <string>
class RobotInfo {

protected:
    std::string robot_description; 
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
    ros::Publisher robot_info_publisher;
    ros::NodeHandle *nh;
    
public:
    RobotInfo(ros::NodeHandle* nh, std::string robot_description, std::string serial_number, std::string ip_address, std::string firmware_version);
    virtual void publish_data();
};
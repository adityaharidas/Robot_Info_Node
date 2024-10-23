#pragma once
#include "robot_info/robot_info.h"
#include <string>

class AGVRobotInfo : public RobotInfo {
protected:
  std::string maximum_payload; // Member variable for maximum payload

public:
  AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
               std::string serial_number, std::string ip_address,
               std::string firmware_version, std::string max_payload);
  // Overriding the publish_data method to include maximum_payload
  void publish_data() override;
};

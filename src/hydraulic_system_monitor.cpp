#pragma once
#include <string>
class HydraulicSystemMonitor{

protected:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level; 
    std::string hydraulic_oil_pressure; 

public:
    HydraulicSystemMonitor(){
    hydraulic_oil_temperature = "45C";
    hydraulic_oil_tank_fill_level = "100%";
    hydraulic_oil_pressure = "250 bar";
  }
    std::string get_hydraulic_oil_temperature() const {
        return hydraulic_oil_temperature;
    }
    std::string get_hydraulic_oil_tank_fill_level() const {
        return hydraulic_oil_tank_fill_level;
    }

    std::string get_hydraulic_oil_pressure() const {
        return hydraulic_oil_pressure;
    }
    
};


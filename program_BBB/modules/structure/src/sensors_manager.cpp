#include "sensors_manager.h"

#include <sstream>
#include <iostream>

std::string SensorsManager::getStringForSending()
{
    std::ostringstream oss;

    oss << this->line_sensor.getLineState() << " ";
    oss << this->us_sensor_1.getDistance() << " ";
    oss << this->us_sensor_2.getDistance();

    return oss.str();
}

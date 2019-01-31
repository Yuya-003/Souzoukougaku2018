#pragma once

#include <structure/using_pins.h>
#include <structure/line_sensor.h>

class SensorsManager{
private:
    LineSensor &line_sensor;

public:
    SensorsManager() = delete;
    SensorsManager(BBB::LineSensorPins line_pins)
        : line_sensor(line_pins)
    {}

    std::string getStringForSending();
};

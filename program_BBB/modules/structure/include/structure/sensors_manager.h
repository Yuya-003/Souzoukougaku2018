#pragma once

#include <structure/using_pins.h>
#include <structure/line_sensor.h>
#include <structure/ultrasonic_sensor.h>

class SensorsManager{
private:
    LineSensor &line_sensor;
    UltrasonicSensor &us_sensor_1, &us_sensor_2;

public:
    SensorsManager() = delete;
    SensorsManager(BBB::LineSensorPins line_pins, BlackLib::gpioName us_pins_1, BlackLib::gpioName us_pins_2)
        : line_sensor(line_pins), us_sensor_1(us_pins_1), us_sensor_2(us_pins_2)
    {}

    std::string getStringForSending();
};

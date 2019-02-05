#pragma once

#include <thread>

#include <BlackGPIO/BlackGPIO.h>
#include <structure/using_pins.h>

class UltrasonicSensor{
private:
    double distance;
    bool is_running;
    std::thread t;
    BlackLib::BlackGPIO sensor;

    void measureDistance();
    double convertFromNsToCm(double ns);

public:
    UltrasonicSensor() = delete;
    UltrasonicSensor(BlackLib::gpioName pin);
    ~UltrasonicSensor();

    double getDistance(); //cm
};

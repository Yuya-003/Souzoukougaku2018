#pragma once

#include <vector>

#include <structure/line_sensor.h>
#include <control/drive_motor.h>
#include <BlackGPIO/BlackGPIO.h>

class LineTracer{
private:
    LineSensor lineSensor;
    DriveMotor driveMotor;

public:
    LineTracer(std::vector<BlackLib::gpioName> sensorPins, DCMotorPins leftPins, DCMotorPins rightPins)
        :lineSensor(sensorPins), driveMotor(leftPins, rightPins){}

    void run();
};

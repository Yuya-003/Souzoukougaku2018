#pragma once 

#include <structure/drive_motor.h>

class ActuatorsManager{
private:
    DriveMotor &drive_motor;

public:
    ActuatorsManager() = delete;
    ActuatorsManager(DCMotorPins left_pins, DCMotorPins right_pins)
        :drive_motor(left_pins, right_pins)
    {}

};

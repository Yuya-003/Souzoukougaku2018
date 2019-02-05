#pragma once 

#include <string>

#include <structure/using_pins.h>
#include <structure/drive_motor.h>
#include <structure/servo_motor.h>

class ActuatorsManager{
private:
    DriveMotor drive_motor;
    ServoMotor servo_motor;

public:
    ActuatorsManager() = delete;
    ActuatorsManager(BBB::DCMotorPins left_pins, BBB::DCMotorPins right_pins, BlackLib::pwmName servo_pin)
        : drive_motor(left_pins, right_pins), servo_motor(servo_pin)
    {}

    void setValueFromReceivedString(std::string received_str); //left_speed right_speed servo_angle arm
};

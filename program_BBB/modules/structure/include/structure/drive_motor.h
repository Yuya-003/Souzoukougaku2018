#pragma once

#include <string>
#include <memory>

#include <structure/using_pins.h>
#include <structure/dc_motor.h>

struct MotorStatus{
    std::string mode;
    double speed;
    double offset;

    MotorStatus(std::string _mode, double _speed, double _offset) : mode(_mode), speed(_speed), offset(_offset){}
};

class DriveMotor{
private:
    std::shared_ptr<DCMotor> right, left;

public:
    DriveMotor(BBB::DCMotorPins leftPins, BBB::DCMotorPins rightPins);
    void setSpeed(double leftSpeed, double rightSpeed);
    void setOffset(double leftOffset, double rightOffset);
    MotorStatus getLeftStatus();
    MotorStatus getRightStatus();
};

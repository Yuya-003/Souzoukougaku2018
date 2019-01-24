#include "drive_motor.h"

DriveMotor::DriveMotor(DCMotorPins leftPins, DCMotorPins rightPins)
{
    this->right = DCMotor(rightPins);
    this->left = DCMotor(leftPins);
}

void DriveMotor::setSpeed(double leftSpeed, double rightSpeed)
{
    if(leftSpeed > 0.0){
        this->left.changeMode(DCMotor::forward);
        this->left.changeDuty(leftSpeed);
    }
    else if(leftSpeed < 0.0){
        this->left.changeMode(DCMotor::backward);
        this->left.changeDuty(-leftSpeed);
    }
    else{
        this->left.changeMode(DCMotor::stop);
    }

    if(rightSpeed > 0.0){
        this->right.changeMode(DCMotor::forward);
        this->right.changeDuty(rightSpeed);
    }
    else if(rightSpeed < 0.0){
        this->right.changeMode(DCMotor::backward);
        this->right.changeDuty(-rightSpeed);
    }
    else{
        this->right.changeMode(DCMotor::stop);
    }
}

void DriveMotor::setOffset(double leftOffset, double rightOffset)
{
    this->left.changeOffset(leftOffset);
    this->right.changeOffset(rightOffset);
}

MotorStatus DriveMotor::getLeftStatus()
{
    return MotorStatus(this->left.getModeStr(), this->left.getDuty(), this->left.getOffset());
}

MotorStatus DriveMotor::getRightStatus()
{
    return MotorStatus(this->right.getModeStr(), this->right.getDuty(), this->right.getOffset());
}

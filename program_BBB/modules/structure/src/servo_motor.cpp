#include "servo_motor.h"

ServoMotor::ServoMotor(BlackLib::pwmName pin)
    : pwm(pin)
{
    this->pwm.setPeriodTime(this->period);
    this->setAngle(0);
}

void ServoMotor::setAngle(double degree)
{
    this->pwm.setDutyPercent(this->dutyAt0Deg + this->dutyPerDeg * degree);
}

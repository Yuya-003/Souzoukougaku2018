#pragma once

#include <BlackPWM/BlackPWM.h>
#include <structure/using_pins.h>

class ServoMotor{
private:
    BlackLib::BlackPWM pwm;
    int period = 10000000;
    double dutyAt0Deg = 0.0;
    double dutyAt180Deg = 100.0;
    double dutyPerDeg = (dutyAt180Deg - dutyAt0Deg) / 180.0;

public:
    ServoMotor() = delete;
    ServoMotor(BlackLib::pwmName pin);

    void setAngle(double degree);
};

#pragma once

#include <BlackGPIO/BlackGPIO.h>
#include <BlackPWM/BlackPWM.h>

class DCMotor{
private:
    BlackLib::BlackGPIO in1, in2;
    BlackLib::BlackPWM st;

    int period = 10000000; //単位:ns
    float duty = 100.0; //パーセント
    Mode mode = stop;

public:

    enum Mode{
        forward, backward, stop
    };

    DCMotor(BlackLib::gpioName in1, BlackLib::gpioName in2, BlackLib::pwmName st);

    void changePeriod(int ns);
    void changeDuty(float percentage);
    void changeMode(Mode mode);
}

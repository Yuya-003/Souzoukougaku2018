#pragma once

#include <memory>
#include <string>

#include <BlackGPIO/BlackGPIO.h>
#include <BlackPWM/BlackPWM.h>
#include <structure/using_pins.h>

class DCMotor{
public:
    enum Mode{
        forward, backward, stop
    };

    DCMotor(BBB::DCMotorPins pins);

    void changePeriod(int ns);
    void changeOffset(float percentage);
    void changeDuty(float percentage);
    void changeMode(Mode mode);

    int getPeriod(){return period;}
    float getOffset(){return offset;}
    float getDuty(){return duty;}
    Mode getMode(){return mode;}
    std::string getModeStr();

private:
    std::shared_ptr<BlackLib::BlackGPIO> in1, in2;
    std::shared_ptr<BlackLib::BlackPWM> st;

    int period = 10000000; //単位:ns
    float offset = 100.0; //パーセント
    float duty = 100.0; //パーセント
    Mode mode = stop;
};

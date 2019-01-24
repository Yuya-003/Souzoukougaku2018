#pragma once

#include <memory>
#include <string>

#include <BlackGPIO/BlackGPIO.h>
#include <BlackPWM/BlackPWM.h>

struct DCMotorPins{
    BlackLib::gpioName in1, in2;
    BlackLib::pwmName st;

    DCMotorPins(BlackLib::gpioName _in1, BlackLib::gpioName _in2, BlackLib::pwmName _st) :in1(_in1), in2(_in2), st(_st){}
};

class DCMotor{
public:
    enum Mode{
        forward, backward, stop
    };

    DCMotor(DCMotorPins pins);

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

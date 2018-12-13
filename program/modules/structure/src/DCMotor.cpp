#include "DCMotor.h"

DCMotor::DCMotor(BlackLib::gpioName in1Name, BlackLib::gpioName in2Name, BlackLib::pwmName stName)
{
    //初期化
    in1 = std::make_shared<BlackLib::BlackGPIO>(in1Name, BlackLib::output);
    in2 = std::make_shared<BlackLib::BlackGPIO>(in2Name, BlackLib::output);
    st = std::make_shared<BlackLib::BlackPWM>(stName);

    //値のセット
    st->setPeriodTime(this->period);
    st->setDutyPercent(this->duty);
    
    //書き込み
    in1->setValue(BlackLib::high);
    in2->setValue(BlackLib::high);
    changeMode(mode);
}

void DCMotor::changePeriod(int ns)
{
    st->setPeriodTime(ns);
}

void DCMotor::changeOffset(float percentage)
{
    this->offset = percentage;
    changeDuty(this->duty);
}

void DCMotor::changeDuty(float percentage)
{
    st->setDutyPercent(percentage / this->offset);
}

void DCMotor::changeMode(Mode mode)
{
    this->mode = mode;
    switch(mode){
    case Mode::forward:
        in1->setValue(BlackLib::high);
        in2->setValue(BlackLib::low);
        break;

    case Mode::backward:
        in1->setValue(BlackLib::low);
        in2->setValue(BlackLib::high);
        break;

    case Mode::stop:
        in1->setValue(BlackLib::high);
        in2->setValue(BlackLib::high);
        break;
    }
}

std::string DCMotor::getModeStr()
{
    if(mode == Mode::forward){return "Forward";}
    if(mode == Mode::backward){return "Backward";}
    if(mode == Mode::stop){return "Stop";}
}

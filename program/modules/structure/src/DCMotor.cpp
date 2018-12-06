#include "DCMotor.h"

DCMotor(BlackLib::gpioName in1, BlackLib::gpioName in2, BlackLib::pwmName st)
{
    //初期化
    in1 = BlackGPIO(in1, BlackLib::output);
    in2 = BlackGPIO(in2, BlackLib::output);
    st = BlackPWM(st);

    //値のセット
    st.setPeriodTime(this->period);
    st.setDutyPercent(this->duty);
    
    //書き込み
    in1.setValue(BlackLib::high);
    in2.setValue(BlackLib::high);
    changeMode(mode);
}

void DCMotor::changePeriod(int ns)
{
    st.setPeriodTime(ns);
}

void DCMotor::changeDuty(float percentage)
{
    st.setDutyPercent(percentage);
}

void DCMotor::changeMode(Mode mode)
{
    this->mode = mode;
    switch(mode){
    case Mode::forward:
        in1.setValue(BlackLib::high);
        in2.setValue(BlackLib::low);
        break;

    case Mode::backward
        in1.setValue(BlackLib::low);
        in2.setValue(BlackLib::high);
        break;

    case Mode::stop:
        in1.setValue(BlackLib::high);
        in2.setValue(BlackLib::high);
        break;
    }
}

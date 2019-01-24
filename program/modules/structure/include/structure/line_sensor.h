#pragma once 

#include <memory>
#include <vector>

#include <BlackGPIO/BlackGPIO.h>

class LineSensor{
private:
    std::vector<std::shared_ptr<BlackLib::BlackGPIO>> sensors;
    bool doReverseSignal;

public:
    enum SensorNo{
        no1 = 1, no2 = 2, no3 = 4, no4 = 8, no5 = 16, no6 = 32
    };

    LineSensor(std::vector<BlackLib::gpioName> pins);
    int getLineState();
    unsigned int size();
    void enableReverseSignal(bool flag);
};

#pragma once 

#include <memory>
#include <vector>

#include <BlackGPIO/BlackGPIO.h>

class LineSensor{
private:
    std::vector<std::shared_ptr<BlackLib::BlackGPIO>> sensors;
    bool doReverseSignal;

public:
    LineSensor(std::vector<BlackLib::gpioName> pins);
    int getLineState();
    unsigned int size();
    void enableReverseSignal(bool flag);
};

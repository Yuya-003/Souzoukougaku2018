#pragma once 

#include <memory>
#include <vector>

#include <BlackGPIO/BlackGPIO.h>
#include <structure/using_pins.h>

class LineSensor{
private:
    std::vector<std::shared_ptr<BlackLib::BlackGPIO>> sensors;
    bool doReverseSignal;

public:
    LineSensor(BBB::LineSensorPins pins);
    int getLineState();
    unsigned int size();
    void enableReverseSignal(bool flag);
};

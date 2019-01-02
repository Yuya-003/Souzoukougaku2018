#pragma once 

#include <cmath>
#include <vector>

#include <BlackGPIO/BlackGPIO.h>

class LineTracer{
public:
    enum SensorNo{
        no1 = 1, no2 = 2, no3 = 4, no4 = 8, no5 = 16, no6 = 32
    };

    LineTracer(std::vector<BlackLib::gpioName> pins);
    int getLineState();

private:
    std::vector<BlackLib::BlackGPIO> sensors;
};

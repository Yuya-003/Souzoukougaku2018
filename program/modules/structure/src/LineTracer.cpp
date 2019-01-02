#include "LineTracer.h"

LineTracer::LineTracer(std::vector<Blacklib::gpioName> pins)
{
    for(auto pin : pins){
        this->sensors.push_back(BlackLib::BlackGPIO(pin, BlackLib::input));
    }
}

int LineTracer::getLineState()
{
    int flag = 0;
    for(int i = 0; i < this->sensors.size(); i++){
        flag <<= 1
        flag += sensors[i].getNumericValue();
    }
    return flag;
}

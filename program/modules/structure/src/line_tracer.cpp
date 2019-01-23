#include "line_tracer.h"

LineTracer::LineTracer(std::vector<BlackLib::gpioName> pins)
{
    for(auto pin : pins){
        this->sensors.push_back(std::make_shared<BlackLib::BlackGPIO>(pin, BlackLib::input));
    }
}

int LineTracer::getLineState()
{
    int flag = 0;
    for(int i = this->sensors.size() - 1; i >= 0; i--){
        flag <<= 1;
        flag += sensors[i]->getNumericValue();
    }
    return flag;
}

unsigned int LineTracer::size()
{
    return sensors.size();
}

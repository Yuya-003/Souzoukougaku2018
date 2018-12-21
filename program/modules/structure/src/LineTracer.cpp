#include "LineTracer.h"

LineTracer::LineTracer(std::vector<Blacklib::gpioName> pins)
{
    for(auto pin : pins){
        this->sensors.push_back(BlackLib::BlackGPIO(pin, BlackLib::input));
    }
}

bool checkLine(int flag)
{
    int tmpFlag = 0;
    for(int i = 0; i < this->sensors.size(); i++){
        if(sensors[i].getNumericValue() == 1){
            tmpFlag |= pow(2, i);
        }
    }

    return (flag == tempFlag);
}

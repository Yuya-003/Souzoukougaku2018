#include "line_sensor.h"

LineSensor::LineSensor(BBB::LineSensorPins pins)
{
    for(auto pin : pins){
        this->sensors.push_back(std::make_shared<BlackLib::BlackGPIO>(pin, BlackLib::input));
    }
    this->doReverseSignal = true;
}

int LineSensor::getLineState()
{
    int flag = 0;
    for(unsigned int i = 0; i < this->sensors.size(); i++){
        flag <<= 1;
        flag += (sensors[i]->isHigh() ^ this->doReverseSignal) ? 1 : 0;
    }
    return flag;
}

unsigned int LineSensor::size()
{
    return sensors.size();
}

void LineSensor::enableReverseSignal(bool flag)
{
    this->doReverseSignal = flag;
}

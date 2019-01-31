#pragma once

#include <vector>

#include <BlackGPIO/BlackGPIO.h>

namespace BBB{

    struct DCMotorPins{
        BlackLib::gpioName in1, in2;
        BlackLib::pwmName st;

        DCMotorPins(BlackLib::gpioName _in1, BlackLib::gpioName _in2, BlackLib::pwmName _st)
            : in1(_in1), in2(_in2), st(_st)
        {}
    };

    using LineSensorPins = std::vector<BlackLib::gpioName>;

    //define pins
    const DCMotorPins RIGHT_MOTOR_PINS(BlackLib::GPIO_61, BlackLib::GPIO_60, BlackLib::P9_14);
    const DCMotorPins LEFT_MOTOR_PINS (BlackLib::GPIO_65, BlackLib::GPIO_46, BlackLib::P9_22);
    const LineSensorPins LINE_SENSORS_PINS = {  BlackLib::GPIO_27,
                                                BlackLib::GPIO_115,
                                                BlackLib::GPIO_49,
                                                BlackLib::GPIO_3,
                                                BlackLib::GPIO_48,
                                                BlackLib::GPIO_47  };
    }

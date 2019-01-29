#include <control/line_tracer.h>

int main()
{
    const std::vector<BlackLib::gpioName> sensorPins = {    BlackLib::GPIO_27,
                                                            BlackLib::GPIO_115,
                                                            BlackLib::GPIO_49,
                                                            BlackLib::GPIO_3,
                                                            BlackLib::GPIO_48,
                                                            BlackLib::GPIO_47  };

    const DCMotorPins rightMotorPins(BlackLib::GPIO_61, BlackLib::GPIO_60, BlackLib::P9_14);
    const DCMotorPins leftMotorPins(BlackLib::GPIO_65, BlackLib::GPIO_46, BlackLib::P9_22);

    LineTracer lineTracer(sensorPins, leftMotorPins, rightMotorPins);

    lineTracer.run();

    return 0;
}

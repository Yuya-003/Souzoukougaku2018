//own headers

//c headers

//c++ headers
#include <iostream>
#include <iomanip>

//library headers

//project headers
#include <util/Timer.hpp>
#include <structure/DCMotor.h>

int kbhit(void); //キー入力関数

int main()
{
    constexpr BlackLib::gpioName MotorGpioName[2][2] = { {BlackLib::GPIO_61, BlackLib::GPIO_60},
                                                         {BlackLib::GPIO_65, BlackLib::GPIO_46} };
    constexpr BlackLib::pwmName MotorPwmName[2] = {BlackLib::P9_14, BlackLib::P9_22};

    constexpr float rightOffset = 29.0;
    constexpr float leftOffset = 25.0;

    DCMotor rightMotor(MotorGpioName[0][0], MotorGpioName[0][1], MotorPwmName[0]);
    DCMotor leftMotor (MotorGpioName[1][0], MotorGpioName[1][1], MotorPwmName[1]);

    rightMotor.changeOffset(rightOffset);
    leftMotor.changeOffset(leftOffset);

    std::cout << "Start" << std::endl; 
    WaitTime(3000);
    rightMotor.changeDuty(100);
    leftMotor.changeDuty(100);
    rightMotor.changeMode(DCMotor::forward);
    leftMotor.changeMode(DCMotor::forward);
    WaitTime(500);
    rightMotor.changeDuty(60);
    leftMotor.changeDuty(60);
    WaitTime(3000);
    std::cout << "End" << std::endl;
    
    return 0;
}

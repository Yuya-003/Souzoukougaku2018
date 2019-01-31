//own headers

//c headers

//c++ headers
#include <iostream>
#include <iomanip>

//library headers

//project headers
#include <util/Timer.h>
#include <structure/dc_motor.h>


int main()
{
    constexpr float rightOffset = 67.0;
    constexpr float leftOffset = 60.0;

    DCMotor rightMotor(BBB::RIGHT_MOTOR_PINS);
    DCMotor leftMotor (BBB::LEFT_MOTOR_PINS);

    rightMotor.changeOffset(rightOffset);
    leftMotor.changeOffset(leftOffset);

    std::cout << "Start" << std::endl; 
    Timer::waitTime(3000);
    rightMotor.changeDuty(60);
    leftMotor.changeDuty(60);
    rightMotor.changeMode(DCMotor::forward);
    leftMotor.changeMode(DCMotor::forward);
    Timer::waitTime(3000);
    std::cout << "End" << std::endl;
    
    return 0;
}

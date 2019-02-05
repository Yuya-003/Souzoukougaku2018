#include "actuators_manager.h"

#include <sstream>

void ActuatorsManager::setValueFromReceivedString(std::string received_str)
{
    std::istringstream iss(received_str);

    double left_speed, right_speed, servo_angle;
    int arm_state;
    iss >> left_speed >> right_speed >> servo_angle >> arm_state;
    this->drive_motor.setSpeed(left_speed, right_speed);
    this->servo_motor.setAngle(servo_angle);
    //arm
}

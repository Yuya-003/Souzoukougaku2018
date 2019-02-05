#include "ultrasonic_sensor.h"

#include <chrono>
#include <iostream>

#include <util/timer.h>

UltrasonicSensor::UltrasonicSensor(BlackLib::gpioName pin)
    : sensor(pin, BlackLib::input)
{
    this->is_running = true;
    this->distance = 0;
    std::thread _t(&UltrasonicSensor::measureDistance, this);
    this->t.swap(_t);
}

UltrasonicSensor::~UltrasonicSensor()
{
    this->is_running = false;
    this->t.join();
}

void UltrasonicSensor::measureDistance()
{
    Timer timer;

    while(this->is_running){
        while(this->sensor.isHigh()); //Lowの状態から始める
        while(!this->sensor.isHigh()); //Highになった瞬間に計測開始
        timer.start();
        while(this->sensor.isHigh()); //Lowになった瞬間に計測終了
        timer.stop();

        this->distance = this->convertFromNsToCm(timer.getElapsedTime());
    }

    std::cout << "measureDistance exit" << std::endl;
}

double UltrasonicSensor::convertFromNsToCm(double ns)
{
    return ns * 340.0 * 100 * 1E-9 / 2.0;
}

double UltrasonicSensor::getDistance()
{
    return this->distance;
}

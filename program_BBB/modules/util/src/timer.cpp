#include "Timer.h"

void Timer::waitTime(int ms){
    auto begin = std::chrono::system_clock::now();
    while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - begin).count() < ms);
}

void Timer::start()
{
    this->begin = std::chrono::high_resolution_clock::now();
    this->end = this->begin;
}

void Timer::stop()
{
    this->end = std::chrono::high_resolution_clock::now();
}

int Timer::getElapsedTime()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(this->end - this->begin).count();
}

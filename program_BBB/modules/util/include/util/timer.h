#pragma once

#include <chrono>

class Timer{
private:
    std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point end;

public:
    static void waitTime(int ms);

    void start();
    void stop();
    int getElapsedTime();
};


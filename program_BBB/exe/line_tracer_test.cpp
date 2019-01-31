#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include <cmath>
#include <iostream>
#include <vector>
#include <exception>

#include <structure/line_sensor.h>
#include <util/Console.h>
#include <util/Timer.h>


int main()
{
    try{

        LineSensor tracer(BBB::LINE_SENSORS_PINS);

        Console::ClearScreen(1);
        Console::SetCursorPos(0,0);
        std::cout << "========================\n"
                     "=                      =\n"
                     "=   Line Sensor Test   =\n"
                     "=                      =\n"
                     "========================\n"
                     "=                      =\n"
                     "=                      =\n"
                     "=                      =\n"
                     "========================\n";

        bool doesLoop = true;
        int flags = 0;
        while(doesLoop){
            
            if(Console::kbhit()){
                if(getchar() == 'q'){
                    doesLoop = false;
                }
            }

            flags = tracer.getLineState();

            Console::SetCursorPos(5, 7);
            for(unsigned int i = 0; i < tracer.size(); i++){
                int tmpFlag = 1;
                tmpFlag <<= tracer.size()-1-i;
                if((flags & tmpFlag) != 0){
                    std::cout << 1 << "  ";
                }
                else{
                    std::cout << 0 << "  ";
                }
            }
            Console::MoveCursorPos(-22, 3);

            Timer::waitTime(10);
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}


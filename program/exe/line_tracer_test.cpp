#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include <cmath>
#include <iostream>
#include <vector>
#include <exception>

#include <structure/line_tracer.h>
#include <util/Console.h>
#include <util/Timer.hpp>


int main()
{
    try{
        const std::vector<BlackLib::gpioName> pins = {  BlackLib::GPIO_27,
                                                        BlackLib::GPIO_115,
                                                        BlackLib::GPIO_49,
                                                        BlackLib::GPIO_3,
                                                        BlackLib::GPIO_48,
                                                        BlackLib::GPIO_30  };

        LineTracer tracer(pins);

        Console::ClearScreen(1);
        Console::SetCursorPos(0,0);
        std::cout << "========================\n"
                     "=                      =\n"
                     "=   Line Tracer Test   =\n"
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
            for(int i = 0; i < tracer.size(); i++){
                if((flags & static_cast<int>(pow(2, i))) != 0){
                    std::cout << 1 << "  ";
                }
                else{
                    std::cout << 0 << "  ";
                }
            }
            Console::MoveCursorPos(-22, 3);

            WaitTime(10);
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}


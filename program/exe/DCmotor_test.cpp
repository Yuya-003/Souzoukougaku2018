//own headers

//c headers
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

//c++ headers
#include <iostream>
#include <iomanip>

//library headers

//project headers
#include <util/Console.h>
#include <util/Timer.hpp>
#include <structure/DCMotor.h>

bool kbhit(); //キー入力関数
void printConsole(DCMotor rightMotor, DCMotor leftMotor);

int main()
{
    constexpr BlackLib::gpioName MotorGpioName[2][2] = { {BlackLib::GPIO_61, BlackLib::GPIO_60},
    									  			   	 {BlackLib::GPIO_65, BlackLib::GPIO_46} };
    constexpr BlackLib::pwmName MotorPwmName[2] = {BlackLib::P9_14, BlackLib::P9_22};

    DCMotor rightMotor(MotorGpioName[0][0], MotorGpioName[0][1], MotorPwmName[0]);
    DCMotor leftMotor (MotorGpioName[1][0], MotorGpioName[1][1], MotorPwmName[1]);

    //画面表示
    Console::ClearScreen(1);
    Console::SetCursorPos(0, 0);
    std::cout << "============================================================================\n"
                 "=                                                                          =\n"
                 "=                            Motor Test Program                            =\n"
                 "=                                                                          =\n"
                 "============================================================================\n"
                 "= < L >                                                                    =\n"
                 "=    Mode   :                                                              =\n"
                 "=    Offset :                                                              =\n"
                 "=    Rate   : {                                                  }    %    =\n"
                 "=                                                                          =\n"
                 "============================================================================\n"
                 "= < R >                                                                    =\n"
                 "=    Mode   :                                                              =\n"
                 "=    Offset :                                                              =\n"
                 "=    Rate   : {                                                  }    %    =\n"
                 "=                                                                          =\n"
                 "============================================================================\n"
                 "= < key description >                                                      =\n"
                 "=   (L)                               |   (R)                              =\n"
                 "=     'r' : mode 'Forward'            |     'u' : mode 'Forward'           =\n"
                 "=     'f' : mode 'Stop'               |     'j' : mode 'Stop'              =\n"
                 "=     'v' : mode 'Backward            |     'm' : mode 'Backward           =\n"
                 "=     '@' : offset increase           |     '[' : offset increase          =\n"
                 "=     ':' : offset decrease           |     ']' : offset decrease          =\n"
                 "=     't' : duty rate increase        |     'y' : duty rate increase       =\n"
                 "=     'g' : duty rate decrease        |     'h' : duty rate decrease       =\n"
                 "============================================================================\n";
    printConsole(rightMotor, leftMotor);
    
    bool doesLoop = true;
    while(true){
        
        static int key;
        if(kbhit()){
            key = getchar();
            switch(key){
                case 'r': //(L) status 'Forward'
                    leftMotor.changeMode(DCMotor::forward);
                    break;

                case 'f': //(L) status 'Stop'
                    leftMotor.changeMode(DCMotor::stop);
                    break;

                case 'v': //(L) status 'Backward 
                    leftMotor.changeMode(DCMotor::backward);
                    break;

                case '@': //(L) offset increase
                    if(leftMotor.getOffset() < 100.0){
                        leftMotor.changeOffset(leftMotor.getOffset() + 1);
                    }
                    break;

                case ':': //(L) offset decrease
                    if(leftMotor.getOffset() > 0){
                        leftMotor.changeOffset(leftMotor.getOffset() - 1);
                    }
                    break;

                case 't': //(L) duty rate increase
                    if(leftMotor.getDuty() < 100.0){
                        leftMotor.changeDuty(leftMotor.getDuty() + 1.0);
                    }
                    break;

                case 'g': //(L) duty rate decrease
                    if(leftMotor.getDuty() > 0){
                        leftMotor.changeDuty(leftMotor.getDuty() - 1.0);
                    }
                    break;

                case 'u': //(R) status 'Forward'
                    rightMotor.changeMode(DCMotor::forward);
                    break;

                case 'j': //(R) status 'Stop'
                    rightMotor.changeMode(DCMotor::stop);
                    break;

                case 'm': //(R) status 'Backward 
                    rightMotor.changeMode(DCMotor::backward);
                    break;

                case '[': //(R) offset increase
                    if(rightMotor.getOffset() < 100.0){
                        rightMotor.changeOffset(rightMotor.getOffset() + 1);
                    }
                    break;

                case ']': //(R) offset decrease
                    if(rightMotor.getOffset() > 0){
                        rightMotor.changeOffset(rightMotor.getOffset() - 1);
                    }
                    break;

                case 'y': //(R) duty rate increase
                    if(rightMotor.getDuty() < 100.0){
                        rightMotor.changeDuty(rightMotor.getDuty() + 1.0);
                    }
                    break;

                case 'h': //(R) duty rate decrease
                    if(rightMotor.getDuty() > 0){
                        rightMotor.changeDuty(rightMotor.getDuty() - 1.0);
                    }
                    break;

                case 'q':
                    doesLoop = false;
                    break;

                default:
                    break;
                    
            }
            
            printConsole(rightMotor, leftMotor);
        }

        if(!doesLoop) break;

        WaitTime(10);
    }

    

    return 0;
}

bool kbhit(){
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

void printConsole(DCMotor rightMotor, DCMotor leftMotor)
{
    //L
    Console::SetCursorPos(15, 7);
    std::cout << leftMotor.getModeStr() << "          ";
    Console::MoveCursorPos(-(leftMotor.getModeStr().size() + 10), 1);
    std::cout << std::setw(3) << leftMotor.getOffset() << "%";
    Console::MoveCursorPos(-3, 1);
    for(int i = 1; i <= 50; i++){
        if(leftMotor.getDuty()/(i*2) >= 1){
            std::cout << "█";
        }
        else{
            std::cout << " ";
        }
    }
    Console::MoveCursorPos(2, 0);
    std::cout << std::setw(3) << leftMotor.getDuty();

    //R
    Console::MoveCursorPos(-56, 4);
    std::cout << rightMotor.getModeStr() << "          ";
    Console::MoveCursorPos(-(rightMotor.getModeStr().size() + 10), 1);
    std::cout << std::setw(3) << rightMotor.getOffset() << "%";
    Console::MoveCursorPos(-3, 1);
    for(int i = 1; i <= 50; i++){
        if(rightMotor.getDuty()/(i*2) >= 1){
            std::cout << "█";
        }
        else{
            std::cout << " ";
        }
    }
    Console::MoveCursorPos(2, 0);
    std::cout << std::setw(3) << rightMotor.getDuty();

    Console::SetCursorPos(0, 28);

}

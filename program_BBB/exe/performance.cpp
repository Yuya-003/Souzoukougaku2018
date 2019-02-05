#include <iostream>

#include <iostream>
#include <string>
#include <thread>
#include <exception>

#include <structure/using_pins.h>
#include <structure/socket_server.h>
#include <structure/sensors_manager.h>
#include <util/Console.h>
#include <actuators_manager.h>

void  receiveMonitor(SocketServer &server, ActuatorsManager &actu_mgr, bool is_running);

int main()
{
    try{
        bool is_running = true;
        SocketServer server(2010);
        ActuatorsManager actu_mgr(LEFT_MOTOR_PINS, RIGHT_MOTOR_PINS, SERVO_PIN);
        SensorsManager sens_mgr(LINE_SENSORS_PINS, ULTRASONIC_PIN_1, ULTRASONIC_PIN_2);

        server.accept();

        std::thread t(receiveMonitor, server, actu_mgr, is_running);

        while(is_running){
            server.sendText(sens_mgr.getStringForSending());
            if(Console::kbhit() && getchar() == 'q'){
                is_running = false;
            }
        }

        t.join();

    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}

void receiveMonitor(SocketServer &server, ActuatorsManager &actu_mgr, bool &is_running)
{
    while(is_running){
        std::string str = server.receiveText();
        if(str == "end"){
            is_running = false;
        }
        else{
            actu_mgr.setValueFromReceivedString(str);
        }
    }
    std::cout << "receiveMonitor exit" << std::endl;
}

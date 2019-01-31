#include <iostream>

#include <string>

#include <structure/using_pins.h>
#include <structure/socket_server.h>
#include <structure/sensors_manager.h>
#include <actuators_manager.h>

int main()
{
    try{
        SocketServer server(2010);
        
        server.accept();

        while(true){
            break;
        }

    }

    return 0;
}

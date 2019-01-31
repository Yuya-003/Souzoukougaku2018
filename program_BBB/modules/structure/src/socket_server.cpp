#include "socket_server.h"

#include <exception>
#include <iostream>

void SocketServer::accept()
{
    try{
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), this->port);
        boost::asio::ip::tcp::acceptor acceptor(this->io_service, endpoint);
        acceptor.accept(this->sock);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

void SocketServer::sendText(std::string str)
{
    try{
        boost::asio::write(this->sock, boost::asio::buffer(str));
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

std::string SocketServer::receiveText()
{
    try{
        boost::asio::streambuf receive_buffer;
        boost::system::error_code error;
        boost::asio::read(this->sock,  receive_buffer, boost::asio::transfer_at_least(1), error);
        if(error && error != boost::asio::error::eof){
            return "receive failed: " + error.message();
        }
        return std::string(boost::asio::buffer_cast<const char*>(receive_buffer.data()));
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    } 
}

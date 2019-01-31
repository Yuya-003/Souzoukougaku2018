#pragma once

#include <string>

#include <boost/asio.hpp>

class SocketServer{
private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket sock;

    u_short port;

public:
    SocketServer() = delete;
    SocketServer(u_short _port) 
        : port(_port),
          sock(io_service)
    {}

    void accept();
    void sendText(std::string str);
    std::string receiveText();
};

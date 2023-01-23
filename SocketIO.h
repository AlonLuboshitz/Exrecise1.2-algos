#ifndef DEFAULTIO_H
#define DEFAULTIO_H
#include "defualtIO.h"
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <ostream>
class SocketIO : public defualtIO
{
private:
    /* data */
     int m_client_socket_fd;
     int m_expected_data_length;
public:
    SocketIO() = delete;
    SocketIO(int client_socket_fd, int expected_data_length);
    ~SocketIO();

    void write(std::string str);
    std::string read();
    bool sendMessage(std::string message);
    bool getMessage(char buffer[]);
};


#endif

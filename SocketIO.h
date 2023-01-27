#ifndef SOCKETIO_H
#define SOCKETIO_H
#include "defualtIO.h"
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>  
class SocketIO : public defualtIO
{
private:
    /* data */
     int m_client_socket_fd;
     int m_expected_data_length;
     std::string m_messegeLeft; 
public:
    SocketIO() = delete;
    SocketIO(int client_socket_fd, int expected_data_length);
    ~SocketIO() = default;

    void write(std::string str);
    std::string read();
    bool sendMessage(std::string message);
    int getMessage(char buffer[]);
    int endOfMsg(std::string recievedMessege, int recievedBytes);
    void resetMsg(char* recievedMessege, int endOfMsg, int recievedBytes);
    std::string getMessegeLeft();

};


#endif

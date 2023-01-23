#include "SocketIO.h"

SocketIO:: SocketIO(int client_socket_fd, int expected_data_length){
    m_client_socket_fd = client_socket_fd;
    m_expected_data_length = expected_data_length;
}

bool SocketIO::sendMessage(std::string message) {
    // SPACE BEFORE XXX???????
    message.append(" xxx");
    int length = message.size() + 1;
    char buffer[length];
    strcpy(buffer,message.c_str());
    length = strlen(buffer);
    int read_bytes = send(m_client_socket_fd,buffer,length,0);
    if (read_bytes < 0) {
        std::cout<<"error sending message";
        return false;
    }
    else return true;
}

bool SocketIO::getMessage( char buffer[]) {
    int read_bytes = recv(m_client_socket_fd,buffer,m_expected_data_length,0);
    if (read_bytes == 0) {
        std::cout<<"empty message";
        return false;
    }
    else if ( read_bytes < 0) {
        std::cout<<"error reiciving message"<<std::endl;
        return false;
    }
    else { 
    buffer[read_bytes] = '\0';
    return true;
    }
}

void SocketIO::write(std::string str){
    sendMessage(str);
}

std::string read(){
    
}

SocketIO::~SocketIO()
{
}
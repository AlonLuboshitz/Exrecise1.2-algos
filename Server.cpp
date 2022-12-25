#include "Server.h"

bool initSocket() {
socket_fd = socket(AF_INET,SOCK_STREAM, 0);
if (socket_fd < 0) {
    std::cout<<"error creating socket"<<std::endl;
    return false;
}
else return true;
}

void setSinMembers() {
    memset(&sin, 0 ,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = port;
}
bool bindSocket() {
    if (bind(socket_fd, (const sockaddr *) &sin, sizeof(sin)) < 0) {
        std::cout<<"failed to bind socket"<<std::endl;
        return false;
    }
    else return true;
}
bool listenTo() {
    if (listen(socket_fd,2) < 0) {
        std::cout<<"failed listening to socket"<<std::endl;
        return false;
    }
    else return true;
}
bool accpetClient() {
    unsigned int adrr_length = sizeof(client);
    client_socket_fd = accept(socket_fd, (sockaddr *) &client, &adrr_length);
    if (client_socket_fd < 0) {
        std::cout<<"failed accpeting client"<<std::endl;
        return false;
    }
    else return true;
}
bool getMessage() {
    int read_bytes = recv(client_socket_fd,buffer,expected_data_length,0);
    if (read_bytes == 0) {
        return false;
    }
    else if ( read_bytes < 0) {
        std::cout<<"error reiciving message"<<std::endl;
        return false;
    }
    else return true;
}
void validateMessage();

int main () {
    if (!initSocket) {
        return 0;
    }
    setSinMembers();
    if (!bindSocket()) { return 0;}
    if (!listenTo()) {return 0;}
    while (accpetClient()) {
        while (getMessage()) {

        }
    }

}
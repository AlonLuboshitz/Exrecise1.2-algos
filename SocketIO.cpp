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
int endOfMsg(char* recievedMessege, int recievedBytes){
    std::string stop;
    int i;
    for (i = 0; i < recievedBytes; i++){
        if(*(recievedMessege+i) == 'x'){
            stop.append("x");
            if (stop == "xxx"){
                break;
            }
        }
    }
    return i;
    
}

void resetMsg(char* recievedMessege, int endOfMsg, int buffer){
    if (endOfMsg == buffer){
        return;
    }
    std::memmove(recievedMessege, recievedMessege + endOfMsg + 1, buffer - endOfMsg);
    *(recievedMessege + endOfMsg +1) = '\0';
 }

 void seperateLines(std::ofstream& file,char* recievedMessege,  int recievedBytes){
    std::string tempWord;
    for (int j = 0; j < recievedBytes; j++){
        if (*(recievedMessege+j) == ' '){
            file<<tempWord;
            file<<",";
            tempWord.clear();
        }
        else if (*(recievedMessege+j) == '\\' && *(recievedMessege+j + 1) == 'n'){
            file<<tempWord;
            file<<"\n";
            tempWord.clear();
            j++;
        }

        else {
            std::string tempChar = std::string(1, *(recievedMessege +j));
            tempWord.append(tempChar);
            tempChar.clear();
        
        }
    }
    file<<tempWord;
    file<<",";
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
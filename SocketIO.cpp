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
int SocketIO::endOfMsg(char* recievedMessege, int recievedBytes){
    // std::string stop;
    std::string tempMsg = recievedMessege;
     std::size_t end = tempMsg.find("xxx");
    if (end != std::string::npos){
        return static_cast<int>(end);
    }
    // for (i = 0; i < recievedBytes; i++){
    //     if(*(recievedMessege+i) == 'x'){
    //         stop.append("x");
    //         if (stop == "xxx"){
    //             break;
    //         }
    //     }
    // }
    return recievedBytes;
    
}

void SocketIO::resetMsg(char* recievedMessege, int endOfMsg, int recievedBytes){
    if (endOfMsg == recievedBytes){
        return;
    }
    m_messegeLeft.append (recievedMessege + endOfMsg, recievedBytes - endOfMsg);
    // std::memmove(recievedMessege, recievedMessege + endOfMsg + 1, buffer - endOfMsg);
    // *(recievedMessege + endOfMsg +1) = '\0';
 }

 void seperateLines(std::ofstream& file,char* recievedMessege,  int recievedBytes){
    std::string tempWord;
    for (int j = 0; j < recievedBytes; j++){
        if (*(recievedMessege+j) == ' '){
            file <<tempWord;
            file <<",";
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

int SocketIO::getMessage(char* buffer) {
    int read_bytes = recv(m_client_socket_fd,buffer,m_expected_data_length,0);
    if (read_bytes == 0) {
        std::cout<<"empty message";
        return -1;
    }
    else if ( read_bytes < 0) {
        std::cout<<"error reiciving message"<<std::endl;
        return -1;
    }
    else { 
    buffer[read_bytes] = '\0';
    return read_bytes;
    }
}

void SocketIO::write(std::string str){
    sendMessage(str);
}

std::string SocketIO:: read(){
        std::string str_msg; 

    if ( ! m_messegeLeft.empty()){
        str_msg.append(m_messegeLeft);
        m_messegeLeft.clear();
    }
    char msg[m_expected_data_length];
    int recievedBytes = getMessage(msg);
    int end = endOfMsg(msg, recievedBytes);
    while (end == recievedBytes){
        str_msg.append(msg);
        msg[0] = '\0';
        recievedBytes = getMessage(msg);
    }
    str_msg.append(msg, recievedBytes - end);
    resetMsg(msg, end, recievedBytes);
    
}

SocketIO::~SocketIO()
{
}
#include "SocketIO.h"

SocketIO:: SocketIO(int client_socket_fd, int expected_data_length){
    m_client_socket_fd = client_socket_fd;
    m_expected_data_length = expected_data_length;
}

bool SocketIO::sendMessage(std::string message) {
    int length = message.size() + 1;
    char buffer[length] = {'\0'};
    strcpy(buffer,message.c_str());
    length = strlen(buffer);
    int read_bytes = send(m_client_socket_fd,buffer,length,0);
    if (read_bytes < 0) {
        std::cout<<"error sending message";
        return false;
    }
    else return true;
}
//convert back to char*??????????????????????????????
/**
 * the function returns the index of the last 'x' in the 'xxx' which symbolyze the end of the messge.
 * if no 'xxx' was found  - returns back the reiceved bytes
*/
int SocketIO::endOfMsg(std::string recievedMessege, int recievedBytes){
    // std::string stop;
    //std::string tempMsg = recievedMessege;
     std::size_t end = recievedMessege.find("xxx");
    if (end != std::string::npos){
        return static_cast<int>(end) + 2;
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
/**
 * the function appends to the 'messege left' string  the recieved string without the begging of the string until the end of the messege.
 * if end of the messege is the same sized as the recieved bytes, it returns without doing anything
*/
void SocketIO::resetMsg(char* recievedMessege, int endOfMsg, int recievedBytes){
    if (endOfMsg + 1 == recievedBytes){
        return;
    }
    std::string temp;
    temp.append(recievedMessege + endOfMsg + 1, recievedBytes - (endOfMsg + 1));
    if (temp.size() == 1){
     if(temp.at(0)==' ' || temp.at(0)==',') {
        return;
    }
    }
    m_messegeLeft.append (temp);
      if (temp.size() == 1){
        if( m_messegeLeft.at(0) == '\0'){
        m_messegeLeft.erase(0, 1);
    }
    // std::memmove(recievedMessege, recievedMessege + endOfMsg + 1, buffer - endOfMsg);
    // *(recievedMessege + endOfMsg +1) = '\0';
 }
}

 void seperateLines(std::ofstream& file,char* recievedMessege,  int recievedBytes){
    std::string str_msg;
    size_t found = 0;
     
    //  while (found != std:: string::npos){
    //     str_msg.find()
    //  }

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
     for (int i=0; i< m_expected_data_length; i++){
        *(buffer+i) = '\0';
    }
    int read_bytes = recv(m_client_socket_fd,buffer,m_expected_data_length,0);
    if (read_bytes == 0) {
        //std::cout<<"empty message";
        return -1;
    }
    else if ( read_bytes < 0) {
        std::cout<<"error reiciving message"<<std::endl;
        return -1;
    }
    else { 
    //buffer[read_bytes] = '\0';
    return read_bytes;
    }
}

void SocketIO::write(std::string str){
    if (str.size() > m_expected_data_length-3){
       str.append("   xxx"); 
    }
    else {str.append("xxx");}
    sendMessage(str);
}

/**
 * this function integrates all the parts of one messge recieved from the server
 * and returns it
*/
std::string SocketIO:: read(){
    if ((!m_messegeLeft.empty())){
        if (m_messegeLeft.at(0) == ','){
        m_messegeLeft.erase(0, 1);
        }
    }
    std::string str_msg; 
    bool flag = true;
    int recievedBytes = 0;
    int end = 0;
    if (! m_messegeLeft.empty()){
        // str_msg.append(m_messegeLeft);
        // m_messegeLeft.clear();
        flag = false;
    }
    char msg[m_expected_data_length] = {'\0'};

    if (flag){
    recievedBytes = getMessage(msg);
    end = endOfMsg(msg, recievedBytes);
    }
    else {
    recievedBytes = m_messegeLeft.size();
    end = endOfMsg(m_messegeLeft, recievedBytes);
    strcpy(msg,m_messegeLeft.c_str());
    m_messegeLeft.clear();
    }

    while (end == recievedBytes){
    str_msg.append(msg);
    // delete [] msg;
    //  msg = new char[m_expected_data_length];
    recievedBytes = getMessage(msg); 
    end = endOfMsg(msg, recievedBytes);   
    }
    str_msg.append(msg,end -2);
     resetMsg(msg, end, recievedBytes);
    if (str_msg.size() > 0){
        if(str_msg.at(0) == '\0'){
        str_msg.erase(0, 1);
    }
    }
   // msg[0] = '\0';
    //delete [] msg;
    return str_msg;
}
std::string SocketIO::getMessegeLeft(){
    return m_messegeLeft;
}


// int main(){
    
//     SocketIO gili(34, 4096);
//     std::string str = "d56sh djiedey xxx 3vnh782";
//     int i = gili.endOfMsg(str, 25);
//     std::cout<< i;
//     int length = str.size() + 1;
//     char buffer[length];
//     strcpy(buffer,str.c_str());
//     gili.resetMsg(buffer,i,25 );
//     std::string msgleft = gili.getMessegeLeft();


// }
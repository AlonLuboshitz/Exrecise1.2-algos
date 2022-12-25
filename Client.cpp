#include "Client.h"

int createSocket(){
    m_ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_ClientSocket < 0 ){
        return -1;
    } else return 1;
}

void initServerStructAdress(){
    memset(&m_serverStructAdress, 0, sizeof(m_serverStructAdress));
    m_serverStructAdress.sin_family = AF_INET;
    m_serverStructAdress.sin_addr.s_addr = inet_addr(m_serverIpAdress);
    m_serverStructAdress.sin_port = htons(m_serverPortNum);
}

int connectToServer(){
    int isConnected = connect(m_ClientSocket, (struct sockaddr *) &m_serverStructAdress, sizeof(m_serverStructAdress));
    if (isConnected < 0) {
        return -1;
    } else return 1;
}

int getVariables() {
    std::string input;
    while (input.size() == 0) {
	std::getline(std::cin, input);
	}
	std::stringstream stream(input);
	std::string variable;
    bool first = true;
    double stop;
    int flag;
	while (stream >> variable) {
        // while getting a double append it to the messege
        if (is_number(variable)){
            if (first){
                stop = std::stoi(variable);
                if (stop == -1){
                    return -2;
                }
                first = false;
            }
            m_messegeToServer.append(variable);
        }
        // getting a string
        else {
            //no doubles were inserted
            if (m_messegeToServer.size() == 0) {
                return -1;
            }
            flag = 1;
            //first variable after the vector should be disAlgo name
            if (flag == 1){
                m_disAlgo = distAlgoFactory(variable);
                if (m_disAlgo == NULL){
                    return -1;
                }
                m_messegeToServer.append(variable);
                flag = 2;
            }
            // second variable after the vector should be k value
            else if (flag == 2) {
                if (isKAnInteger(variable) < 0){
                    return -1;
                }
                m_messegeToServer.append(variable);
                flag = 3;
                }
            //exceeding number of variables
            else return -1;
        }
    }
    return 1;
}

int sendToServer(){
    int messegeLength = m_messegeToServer.length();
    char messegeArray[messegeLength + 1];
    //convert string to char array
    strcpy(messegeArray, m_messegeToServer.c_str());
    int dataLength = strlen(messegeArray);
    //sent to server
    int sentToServer = send(m_ClientSocket, messegeArray, dataLength, 0);
    //if error accures
    if (sentToServer < 0){
        return -1;
    }
     return 1;
}

void recieveFromServer(){
    int recievedBytes = recv(m_ClientSocket, recievedMessege, buffer, 0);
    if (recievedBytes == 0){
        std::cout<<"conection to server is lost";
    }
    else if (recievedBytes < 0){
        std::cout << "error reading messege back from server";
    }
    else {
        std::cout << recievedMessege << "\n";
    }
}

int main(int argc,char* argv[]) {
    //check arguments
    if (createSocket() < 0){
        std::cout << "error creating socket";
        return -1;
    }
    initServerStructAdress();
    if (connectToServer() < 0) {
        std::cout << "error connecting to server";
        return -1;
    }

    while (true) {
        int loop = getVariables();
        if (loop){
            sendToServer();
            recieveFromServer();
        }
        else {
            //invalid
            if (loop == -1) {
                std::cout<< "invalid input";
            continue;
            }
            // loop == -2, meaning user had entered -1 to stop running
            else break;
        }
    } close(m_ClientSocket);
}
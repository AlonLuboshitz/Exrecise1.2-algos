#include "Client.h"


int createSocket(int& m_ClientSocket){
    m_ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_ClientSocket < 0 ){
        return -1;
    } else return 1;
}

void initServerStructAdress(sockaddr_in& m_serverStructAdress, char* ip, int m_serverPortNum ){
    memset(&m_serverStructAdress, 0, sizeof(m_serverStructAdress));
    m_serverStructAdress.sin_family = AF_INET;
    m_serverStructAdress.sin_addr.s_addr = inet_addr(ip);
    m_serverStructAdress.sin_port = htons(m_serverPortNum);
}

int connectToServer(int m_ClientSocket, sockaddr_in& m_serverStructAdress){
    int isConnected = connect(m_ClientSocket, (struct sockaddr *) &m_serverStructAdress, sizeof(m_serverStructAdress));
    if (isConnected < 0) {
        return -1;
    } else return 1;
}

/*
 * gets variable fron the user input via cin
 * if the input equals to "-1" returns -2 as a sign that the user wants to quit 
 * streams on the input - should be: double vector, distanceAlgorithem name, k (integer > 0)
 * if one or more of the variables are missing or are not valid - returns -1
 * if everything is ok, returns 1
*/
int getVariables(std::string& m_messegeToServer) {
    //clear messege
     m_messegeToServer.clear();

     //get input from user via cin
    std::string input;
    while (input.size() == 0) {
	std::getline(std::cin, input);
	}
    //user wants to end loop
    if (input == "-1"){
        return -2;
    }
	std::stringstream stream(input);
	std::string variable;
    int flag = 0;
    bool valid = false;

    //streaming on the user's input
	while (stream >> variable) {
    
        // while getting a double append it to the messege
        if (is_number(variable) && flag == 0){
            m_messegeToServer.append(variable);
            m_messegeToServer.append(" ");
        }
        // getting a string
        else {
            if (flag == 0){
            flag = 1;
            }
            //no doubles were inserted
            if (m_messegeToServer.size() == 0) {
                return -1;
            }
            //first variable after the vector should be disAlgo name
            if (flag == 1){
                distanceAlgorithems* m_disAlgo = distAlgoFactory(variable);
                if (m_disAlgo == NULL){
                    return -1;
                }
                m_messegeToServer.append(variable);
                 m_messegeToServer.append(" ");
                flag = 2;
                delete m_disAlgo;
            }
            // second variable after the vector should be k value
            else if (flag == 2) {
                if (! isKAnInteger(variable)){
                    return -1;
                }
                m_messegeToServer.append(variable);
                flag = 3;
                valid = true;
                }
            //exceeding number of variables
            else return -1;
        }
    }
    if (valid){
    return 1;
    } else return -1;
}

/*
 * converts the messege to a char array.
 * sends it to the server.
 * if the messege was sent successfully - returns 1, else - returns -1
*/
// void sendToServer(std::string m_messegeToServer, int m_ClientSocket){
//     int messegeLength = m_messegeToServer.length();
//     char messegeArray[messegeLength + 1];
//     //convert string to char array
//     strcpy(messegeArray, m_messegeToServer.c_str());
//     int dataLength = strlen(messegeArray);
//     //sent to server
//     int sentToServer = send(m_ClientSocket, messegeArray, dataLength, 0);
//     //if error accures
//     if (sentToServer < 0){
//         std::cout<<"error sending to the server\n";
//     }
// }

/**
 * tries to recieve messege from the server.
 * if it has recieved succefully - prints it on the screen
 * else- prints the error that had accured 
*/
void recieveFromServer(int m_ClientSocket, char* recievedMessege, const int buffer){
    int recievedBytes = recv(m_ClientSocket, recievedMessege, buffer, 0);
    if (recievedBytes == 0){
        std::cout<<"conection to server is lost\n";
    }
    else if (recievedBytes < 0){
        std::cout << "error reading messege back from server\n";
    }
    else {
        recievedMessege[recievedBytes] = '\0';
        std::cout << recievedMessege << "\n";
    }
}
bool isFileValid(std::string FilePath) {
    std::fstream csvflie(FilePath, std::ios::in);
    if (csvflie.is_open()) {
        csvflie.close();
        return true;
    }
    else return false;
    }



std::string inputFile(SocketIO* io, std::string& instructions){
    std::cout<< instructions << "\n";
    std::string filePath = getMsgFromUser();
    std::string file = getDataFromFile(filePath);
    return file;
    
}

void seperateLines(std::ofstream& file,std::string& msgFromServer){
    int messegeLength = msgFromServer.size();
    char messegeArray[messegeLength + 1];
    //convert string to char array
    strcpy(messegeArray, msgFromServer.c_str());
    std::string tempWord;
    for (int j = 0; j < messegeLength; j++){
        if (*(messegeArray+j) == ' '){
            file<<tempWord;
            file<<",";
            tempWord.clear();
        }
        else if (*(messegeArray+j) == '\\' && *(messegeArray+j + 1) == 'n'){
            file<<tempWord;
            file<<"\n";
            tempWord.clear();
            j++;
        }

        else {
            std::string tempChar = std::string(1, *(messegeArray +j));
            tempWord.append(tempChar);
            tempChar.clear();
        
        }
    }
    file<<tempWord;
    //file<<",";
 }  
 
void outputFile(std::string filePath, std::string msgFromServer) {
    std::ofstream file;
    file.open(filePath);
    seperateLines(file, msgFromServer);
    file.close();
}


/** 
 * copies all the arguments to a new char* array so there will not be any sugmentation error if less arguments were inserted.
*/
void checkClientsArguments(int argc,char* argv[], std::string& serverIP, std::string& strServerPort ){
    
	if(argc != 3){
        getIp(serverIP);
        getPort(strServerPort);
        return;
    }
    serverIP = argv[1];
    strServerPort = argv[2];
    getIp(serverIP);
    getPort(strServerPort);
}

void interactionWithServer(SocketIO* io){

   while(true){
    std::string msgFromServer = io->read();
    std::string temp(msgFromServer.begin(), msgFromServer.begin()+9);
    if (temp =="inputFile"){
        std::string instructions(msgFromServer, 10, msgFromServer.size() - 9);
        std::string file = inputFile(io, instructions); 
        if (file == "-1"){
            io->write("error");
            continue;
        }
        io->write(file);
    }
    else if (temp == "message__") {
        std::string message(msgFromServer, 10, msgFromServer.size() - 9);
        std::cout<<message<<"\n";
        }
    else if (msgFromServer == "outputFile"){
        std::string filePath = getMsgFromUser();
        if (filePath == "-1"){
            std::cout<< "invalid input";
            continue;
        }
         std::string msgFromServer;
         msgFromServer = io->read();
        std::thread downloadFile(outputFile, filePath, msgFromServer);
    }
    else {
        std::cout << msgFromServer << "\n";
        std::string msgToServer = getMsgFromUser();
        io->write(msgToServer);
        if (msgFromServer == "8"){
            break;
        }
    }
    }
}

 std::string getMsgFromUser(){
    std::string msg;
    std::getline(std::cin, msg);
    if (msg.length()  == 0){
        msg = "empty";
    }
    return msg;
 }

 std::string getDataFromFile(std::string filePath){
    int buffer = 4096;
    char msg[buffer];
    if (! isFileValid(filePath)){
        //send to server ' ' ???????????????????????????????
        std::cout<< "invalid input\n";
        return "-1";
    }
    FILE* file;
    file = fopen(&filePath[0], "r");
    std::string msgToServer;
    while (!feof(file))
    {
        // function used to read the contents of file
        fread(msg, sizeof(msg), 1, file);
        msgToServer.append(msg);
    }
     fclose(file);
     for ( int i =0 ; i<buffer; i++) {
        msg[i] = '\0';
     }
    return msgToServer;
    
 }

 


int main() {
    int m_ClientSocket;
    int m_serverPortNum = 5555;
    const int buffer = 4096;
    struct sockaddr_in m_serverStructAdress;    
    std::string m_messegeToServer;
    char recievedMessege[buffer];
    //check if arguments are valid - ip and port
    std::string serverIP = "127.0.0.1";
     char* ip = new char[serverIP.size() +1];
    for (int i=0; i < serverIP.size(); i++){
        *(ip+i) = serverIP.at(i);
    }
    *(ip + serverIP.size()) = '\0';
    if (createSocket(m_ClientSocket) < 0){
        std::cout << "error creating socket\n";
        return -1;
    }
    //init server adress and try to connect to it
    initServerStructAdress(m_serverStructAdress, ip, m_serverPortNum);
    if (connectToServer(m_ClientSocket,m_serverStructAdress ) < 0) {
        std::cout << "error connecting to server\n";
        return -1;
    }
    SocketIO* io = new SocketIO(m_ClientSocket, buffer);
   interactionWithServer(io);
   delete io;
   delete []ip;
   close(m_ClientSocket);
   

}

// int main(int argc,char* argv[]) {
//     int m_ClientSocket;
//     char* m_serverIpAdress;
//     int m_serverPortNum;
//     const int buffer = 4096;
//     struct sockaddr_in m_serverStructAdress;    
//     std::string m_messegeToServer;
//     char recievedMessege[buffer];
//     //check if arguments are valid - ip and port
//     std::string serverIP;
//     std::string strServerPort;
//     checkClientsArguments(argc, argv, serverIP, strServerPort);
//     m_serverPortNum = std::stoi(strServerPort);

//     char* ip = new char[serverIP.size() +1];
//     for (int i=0; i < serverIP.size(); i++){
//         *(ip+i) = serverIP.at(i);
//     }
//     *(ip + serverIP.size()) = '\0';
//     //m_serverPortNum = 5555;
//     //create client socket
    
//     if (createSocket(m_ClientSocket) < 0){
//         std::cout << "error creating socket\n";
//         return -1;
//     }
//     //init server adress and try to connect to it
//     initServerStructAdress(m_serverStructAdress, ip, m_serverPortNum);
//     if (connectToServer(m_ClientSocket,m_serverStructAdress ) < 0) {
//         std::cout << "error connecting to server\n";
//         return -1;
//     }
//     while (true) {
//         // check if variables are valid
//         int loop = getVariables(m_messegeToServer);
//         // loop = 1 - valid variable, send it to server and get an answer
//         if (loop > 0){
//             sendToServer(m_messegeToServer,m_ClientSocket );
//             recieveFromServer(m_ClientSocket, recievedMessege, buffer);
//              }
//         else {
//             //invalid
//             if (loop == -1) {
//                 std::cout<< "invalid input\n";
//             continue;
//             }
//             // loop == -2, meaning user had entered -1 to stop running
//             else {
//                 break;
//             }
//         } 
//     }
//     close(m_ClientSocket);
//     delete[] ip;
// }
#include "Server.h"

bool initSocket(int& socket_fd) {
socket_fd = socket(AF_INET,SOCK_STREAM, 0);
if (socket_fd < 0) {
    std::cout<<"error creating socket"<<std::endl;
    return false;
}
else return true;
}

void setSinMembers( sockaddr_in& sin, int port) {
    memset(&sin, 0 ,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
}
bool bindSocket(int socket_fd, sockaddr_in& sin) {
    if (bind(socket_fd, (const sockaddr *) &sin, sizeof(sin)) < 0) {
        std::cout<<"failed to bind socket"<<std::endl;
        return false;
    }
    else return true;
}
bool listenTo(int socket_fd) {
    if (listen(socket_fd,2) < 0) {
        std::cout<<"failed listening to socket"<<std::endl;
        return false;
    }
    else return true;
}
bool accpetClient(int socket_fd, int& client_socket_fd,  sockaddr_in& client) {
    unsigned int adrr_length = sizeof(client);
    client_socket_fd = accept(socket_fd, (sockaddr *) &client, &adrr_length);
    if (client_socket_fd < 0) {
        std::cout<<"failed accpeting client"<<std::endl;
        return false;
    }
    else return true;
}


bool sendMessage(int client_socket_fd, std::string message) {
    int length = message.size() + 1;
    char buffer[length];
    strcpy(buffer,message.c_str());
    length = strlen(buffer);
    int read_bytes = send(client_socket_fd,buffer,length,0);
    if (read_bytes < 0) {
        std::cout<<"error sending message";
        return false;
    }
    else return true;
}


bool validateMessage(char message[],std::vector<double>& message_vector,
int& k,distanceAlgorithems* &distanceAlgorithems) {
    //convert messgae via char into string in order to stream it.
    std::string input(message);
   	std::stringstream stream(input);
	std::string variable;
    //clear vector
    message_vector.clear();
    double convertFromMesssage = 0;
    int flag = 0;
    bool valid = false;
    //streaming on the message
	while (stream >> variable) {
    
        // while getting a double append it to the vector
        if (is_number(variable) && flag == 0){
            convertFromMesssage = std::stod(variable);
            message_vector.push_back(convertFromMesssage);
        }
        // getting a string
        else {
            if (flag == 0){
            flag = 1;
            }
            //no doubles were inserted
            if (message_vector.size() == 0) {
                return false;
            }
            //first variable after the vector should be disAlgo name
            if (flag == 1){
                distanceAlgorithems = distAlgoFactory(variable);
                if (distanceAlgorithems == NULL){
                    return false;
                }
                flag = 2;
                }
            // second variable after the vector should be k value
            else if (flag == 2) {
                if (isKAnInteger(variable) < 0){
                    return false;
                }
                k = std::stoi(variable);
                flag = 3;
                valid = true;
                }
            //exceeding number of variables
            else return false;
        }
    }
    if (valid){
    return true;
    } else return false;
}

void getServerArguments(char* argv[], int argc, std::string& port,
 std::string& fileName, CSVReader& csvreader) {

if (argc != 3) {
    std::cout<<"wrong number of arguments - please enter Port: "<<std::endl;
    std::cin>> port;
    getPort(port);
    std::cout<<"Please enter file path: "<<std::endl;
    std::cin>>fileName;
    fileName = getFilePath(fileName, csvreader);
}
else {
    port = argv[1];
    fileName = argv[2];
    getPort(port);
    fileName = getFilePath(fileName, csvreader);
}
}
void setKNN(KNN& knn, int k, std::vector<double> vector, distanceAlgorithems* distanceAlgorithems) {
    knn.setInputVector(vector);
    knn.setK(k);
    knn.setDistanceAlgorithem(distanceAlgorithems);
}
bool getMessage(int client_socket_fd, char buffer[], int expected_data_length) {
   
   
    int read_bytes = recv(client_socket_fd,buffer,expected_data_length,0);
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
/*
int main (int argc, char* argv[]) {
    std::string port, fileName;
    CSVReader csvFileReader;
    getServerArguments(argv,argc,port,fileName,csvFileReader);
    const int portNumber = std::stoi(port);
    int socket_fd;
    if (!initSocket(socket_fd)) {
        return 0;
    }
    struct sockaddr_in sin;
    setSinMembers(sin, portNumber);
    if (!bindSocket(socket_fd,sin)) { return 0;}
    if (!listenTo(socket_fd)) {return 0;}
    struct sockaddr_in client;
    int client_socket_fd;
    KNN knn(csvFileReader);
    while (accpetClient(socket_fd,client_socket_fd,client)) {
        char buffer[4096];
        int expected_data_length = sizeof(buffer);
         std::vector<double> messageVector;
            int k;
            distanceAlgorithems* distanceAlgorithems;
            std::string messageToSend;
        while (getMessage(client_socket_fd,buffer,expected_data_length)) {
             messageToSend = "invalid input";
            int delitionflag = 0;
           
            
            if (validateMessage(buffer, messageVector, k, distanceAlgorithems)) {
                //if message valid run knn and set message to knn result.
                setKNN(knn, k, messageVector, distanceAlgorithems);
                messageToSend = knn.runKNN();
                
                
            }
            //by defualt if validate message is false message remains invalid input.
            if (sendMessage(client_socket_fd, messageToSend)) {
                //connection is good continue;
                //reset distanceAlgorithems pointer.
                delete distanceAlgorithems;
                delitionflag = 1;
                continue;
            }
            // delete pointer to distancealgo. (not a neccesery if?)
            if (delitionflag == 0) {
            delete distanceAlgorithems;    
            }
            // close clinet socket and accpet new one
            close(client_socket_fd);
        }
    }
    //finished accpeting clients - close server socket.
    close(socket_fd);

}*/
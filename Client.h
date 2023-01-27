#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "distanceAlgorithems.h"
#include "inputValidation.h"
#include <sstream>
#include "SocketIO.h"
#include <thread>


int createSocket(int& m_ClientSocket);
void initServerStructAdress(sockaddr_in& m_serverStructAdress, char* ip, int m_serverPortNum );
int connectToServer(int m_ClientSocket, sockaddr_in& m_serverStructAdress);
int getVariables(std::string& m_messegeToServer);
void recieveFromServer(int m_ClientSocket, char* recievedMessege, const int buffer);
void checkClientsArguments(int argc,char* argv[],std::string& serverIP, std::string& strServerPort );
std::string inputFile(SocketIO* io, std::string& instructions);
void printMsg(const int buffer, const int m_ClientSocket,char* recievedMessege, int recievedBytes );
void outputFile(std::string filePath, std::string msgFromServer);
void seperateLines(std::ofstream& file,std::string& msgFromServer);
bool isFileValid(std::string FilePath);
void sendThreadFunc(SocketIO* io);
void interactionWithServer(SocketIO* io);
std::string getMsgFromUser();
std::string getDataFromFile(std::string filePath);

// int main(int argc,char* argv[]);

#endif
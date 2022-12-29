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
#include <iostream>
#include <sstream>


int createSocket(int& m_ClientSocket);
void initServerStructAdress(sockaddr_in& m_serverStructAdress, char* ip, int m_serverPortNum );
int connectToServer(int m_ClientSocket, sockaddr_in m_serverStructAdress);
int getVariables(std::string& m_messegeToServer);
void sendToServer(std::string m_messegeToServer, int m_ClientSocket);
void recieveFromServer(int m_ClientSocket, char* recievedMessege, const int buffer);
void checkClientsArguments(int argc,char* argv[],std::string& serverIP, std::string& strServerPort );
int main(int argc,char* argv[]);

#endif
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

char* m_serverIpAdress;
int m_serverPortNum;
int m_ClientSocket;
const int buffer = 4096;
struct sockaddr_in m_serverStructAdress;    
distanceAlgorithems* m_disAlgo;
std::string m_messegeToServer;
char recievedMessege[buffer];

int createSocket();
void initServerStructAdress();
int connectToServer();
int getVariables();
int sendToServer();
void recieveFromServer();
void checkClientsArguments(int argc,char* argv[],std::string& serverIP, std::string& strServerPort );
int main(int argc,char* argv[]);

#endif
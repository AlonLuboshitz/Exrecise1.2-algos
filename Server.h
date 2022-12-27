#ifndef SERVER_H
#define SERVER_H
#include "KNN.h"
#include "inputValidation.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void getServerArguments(char* argv[], int argc, 
std::string& port, std::string& fileName, CSVReader& csvreader);
bool initSocket(int& socket_fd);
void setSinMembers(struct sockaddr_in& sin, int port);
bool bindSocket(int socket_fd,struct sockaddr_in& sin);
bool listenTo(int socket_fd);
bool accpetClient(int socket_fd, int& client_socket_fd, struct sockaddr_in& client);
bool getMessage(int client_socket_fd, char buffer[4096], int expected_data_length);
/* message format is going to be int k (positive), distancelagorithem name, vector to run knn on.
using inputvalidation cpp file to validate each input*/
bool validateMessage(char buffer[],std::vector<double>& message_vector,
int& k,distanceAlgorithems* distanceAlgorithems);
#endif
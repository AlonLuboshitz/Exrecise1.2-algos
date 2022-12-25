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
int const port = 5555;
int socket_fd;
int client_socket_fd;
struct sockaddr_in sin;
struct sockaddr_in client;
char buffer[4096];
int expected_data_length = sizeof(buffer);

bool initSocket();
void setSinMembers();
bool bindSocket();
bool listenTo();
bool accpetClient();
bool getMessage();
/* message format is going to be int k (positive), distancelagorithem name, vector to run knn on.
using inputvalidation cpp file to validate each input*/
void validateMessage();
#endif
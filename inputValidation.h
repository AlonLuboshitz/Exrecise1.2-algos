#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Euclidean.h"
#include "Manhatan.h"
#include "Chevichev.h"
#include "Canberra.h"
#include "Minkovsky.h"
#include <string.h>
#include "CSVReader.h"
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

bool isKAnInteger(std::string k);

void getVectorFromInput(std::vector<double>& vec );
//this function clear "/r", "/b", "/t", from the end of a string.
void stringCleaner(std::string& str);
void printDecimal(double x);
void isSameSize(std::vector<double>& v1, std::vector<double>& v2);
bool is_number(const std::string& s);
bool allDoubleVector(const std::vector<double> vec);
void getPort(std::string& Port);
void getIp(std::string& IP);
bool checkIp(std::string IP);
bool checkPort(std::string Port);
int getK (std::string k);
std::string getFilePath(std::string filePath, CSVReader& csvreader);
distanceAlgorithems* distAlgoFactory(std::string str);

void getArguments (int argc,std::string& s_k, std::string& filePath, std::string& s_disAlgo, CSVReader& csvreader);
#endif

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
#include <string>


void getVectorFromInput(std::vector<double>& vec );
//this function clear "/r", "/b", "/t", from the end of a string.
void stringCleaner(std::string& str);
void printDecimal(double x);
void isSameSize(std::vector<double>& v1, std::vector<double>& v2);
bool is_number(const std::string& s);
bool allDoubleVector(const std::vector<double> vec);



distanceAlgorithems distAlgoFactory(std::string str);
void getArguments(int argc,char* argv[]);
#endif

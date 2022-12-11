#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "distanceAlgorithems.h"
void getVectorFromInput(std::vector<double>& vec );
//this function clear "/r", "/b", "/t", from the end of a string.
void stringCleaner(std::string& str);
void printDecimal(double x);
void isSameSize(std::vector<double>& v1, std::vector<double>& v2);
bool is_number(const std::string& s);
bool allDoubleVector(const std::vector<double> vec);
#endif
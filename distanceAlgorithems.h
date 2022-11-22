
#ifndef DISTANCEALGORITHEMS_H
#define DISTANCEALGORITHEMS_H
#include<vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
	double euclideanDistance();
	void initDistanceVec(std::vector<double> vec1, std::vector<double> vec2);
	double manhatanDistance();
	double cevicheDistance();
	double canberraDistance();
	double canberraDistance();
	double minkovskyDistance(double p);
    void printDecimal(double x);
	void getVectorFromInput(std::vector<double>& vec );
	bool is_number(const std::string& s);




#endif


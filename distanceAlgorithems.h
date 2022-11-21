
#ifndef DISTANCEALGORITHEMS_H
#define DISTANCEALGORITHEMS_H
#include<vector>



	
	//add vector manipulator
	

	//std::vector<double> diffVec = { 0 };
	// distanceAlgorithems(std::vector<double> vec1, std::vector<double>& vec2);
	const double AbsSumIndividualeVector(std::vector<double> v);
	double euclideanDistance();
	void initDistanceVec(std::vector<double> vec1, std::vector<double> vec2);
	const std::vector<double> deductionF(const std::vector<double> v1, const std::vector<double> v2);
	void PrintVec(std::vector<double>);
	double manhatanDistance();
	double cevicheDistance();
	double canberraDistance();
		double canberraDistance();
	double minkovskyDistance(double p);
void printDecimal(double x);



#endif



#ifndef DISTANCEALGORITHEMS_H
#define DISTANCEALGORITHEMS_H
#include<vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
class distanceAlgorithems {
	private:
	std::vector<double> m_vec1;
	std::vector<double> m_vec2;
	std::vector<double> m_diffVec;
	//const std::vector<double> deductionF(const std::vector<double> v1,const std::vector<double> v2);
	void initDistanceVec(std::vector<double> vec1, std::vector<double> vec2);
	public:
	//not init distance algo with no vectors.
	distanceAlgorithems() = delete;
	distanceAlgorithems(std::vector<double> vec1);
	distanceAlgorithems(std::vector<double> vec1, std::vector<double> vec2);
	virtual double calculatedistance();
	double euclideanDistance();
	double manhatanDistance();
	double cevicheDistance();
	double canberraDistance();
	double minkovskyDistance(double p);
    void printDecimal(double x);



};
#endif


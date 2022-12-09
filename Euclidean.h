#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H
#include "distanceAlgorithems.h"
class Euclidean : virtual public distanceAlgorithems {
    public:
    double calculatedistance();
    double calculatedistance(std::vector<double> vec);
	double calculatedistance(std::vector<double> vec1,std::vector<double> vec2);


    Euclidean(std::vector<double> v1, std::vector<double> v2);
};
#endif
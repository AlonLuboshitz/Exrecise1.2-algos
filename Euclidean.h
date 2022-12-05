#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H
#include "distanceAlgorithems.h"
class Euclidean : virtual public distanceAlgorithems {
    public:
    using distanceAlgorithems::calculatedistance;
    Euclidean(std::vector<double> v1, std::vector<double> v2);
};
#endif
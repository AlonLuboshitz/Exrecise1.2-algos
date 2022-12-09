#ifndef MANHATAN_H
#define MANHATAN_H
#include "distanceAlgorithems.h"
class Manhatan : virtual public distanceAlgorithems {
    public:
    Manhatan(std::vector<double> v1, std::vector<double> v2);
    double calculatedistance();
};
#endif
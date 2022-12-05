#include "distanceAlgorithems.h"
class Canberra : public distanceAlgorithems {
    public:
    Canberra(std::vector<double> v1, std::vector<double> v2);
    double calculatedistance();
};
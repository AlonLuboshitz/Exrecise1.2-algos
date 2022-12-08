#include "distanceAlgorithems.h"
class Chevichev : public distanceAlgorithems {
    public:
    Chevichev(std::vector<double> v1, std::vector<double> v2);
    double calculatedistance();
    double calculatedistance(std::vector<double> v1);
    double calculatedistance(std::vector<double> v1, std::vector<double> v2);
};
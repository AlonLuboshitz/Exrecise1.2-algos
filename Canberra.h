#ifndef CANBERRA_H
#define CANBERRA_H
#include "distanceAlgorithems.h"
class Canberra : public distanceAlgorithems {
    public:
    Canberra(std::vector<double> v1, std::vector<double> v2);
    double calculatedistance();
     double calculatedistance(std::vector<double> v1);
      double calculatedistance(std::vector<double> v1, std::vector<double> v2);
};
#endif
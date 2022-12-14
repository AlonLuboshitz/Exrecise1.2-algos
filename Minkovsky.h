#ifndef MINKOVSKY_H
#define MINKOVSKY_H
#include "distanceAlgorithems.h"

class Minkovsky :  public distanceAlgorithems {
    private:
    double m_p;
    public:
    Minkovsky();
    Minkovsky(std::vector<double> v1, std::vector<double> v2, double p);
    double calculatedistance();
    double calculatedistance(std::vector<double> v1);
    double calculatedistance(std::vector<double> v1, std::vector<double> v2);

}; 
#endif
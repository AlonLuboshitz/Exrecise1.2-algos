#include "distanceAlgorithems.h"

class Minkovsky :  public distanceAlgorithems {
    private:
    double m_p;
    public:
    Minkovsky(std::vector<double> v1, std::vector<double> v2, double p);
    double calculatedistance();
}; 
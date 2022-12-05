#include "Euclidean.h"
#include "Manhatan.h"

class Minkovsky :  public Euclidean,  public Manhatan {
    private:
    double m_p;
    public:
    Minkovsky(std::vector<double> v1, std::vector<double> v2, double p);
    double calculatedistance();
}; 
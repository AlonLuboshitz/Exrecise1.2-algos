#include "distanceAlgorithems.h"
class check {
    private:
    distanceAlgorithems* m_dis;
    public:
    check(distanceAlgorithems& dis);
    double cal(std::vector<double> v1);
    double cal();
    void setdis(distanceAlgorithems& dis);
};
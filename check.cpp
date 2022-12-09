#include "check.h"
check::check(distanceAlgorithems& d) {
    m_dis = &d;
}
double check::cal() {
    double s = (*m_dis).calculatedistance();
    return s;
}
double check::cal(std::vector<double> v1) {
    double s = (*m_dis).calculatedistance(v1);
    return s;
}
void check::setdis(distanceAlgorithems& dis) {
    m_dis = &dis;
}
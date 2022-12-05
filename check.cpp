#include "check.h"
check::check(distanceAlgorithems& d) {
    m_dis = &d;
}
double check::cal() {
    double s = (*m_dis).calculatedistance();
    return s;
}
void check::setdis(distanceAlgorithems& dis) {
    m_dis = &dis;
}
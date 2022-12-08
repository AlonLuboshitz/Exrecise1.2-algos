#include "Chevichev.h"
Chevichev::Chevichev(std::vector<double> v1, std::vector<double> v2) : distanceAlgorithems(v1,v2) {

}
double Chevichev::calculatedistance() {
    double max = -1;
    for (std::vector<double>::const_iterator it = m_diffVec.cbegin(); it != m_diffVec.cend(); ++it){
        if (fabs(*it) > max) {
			max = *it;
		}
    }
    return max;
}
double Chevichev::calculatedistance(std::vector<double> v1){
    m_diffVec = deductionF(v1,m_vec2);
    return calculatedistance();
}
    double Chevichev::calculatedistance(std::vector<double> v1, std::vector<double> v2) {
        m_diffVec = deductionF(v1,v2);
        return calculatedistance();
}
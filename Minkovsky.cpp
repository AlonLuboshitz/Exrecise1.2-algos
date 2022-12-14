#include "Minkovsky.h"
Minkovsky::Minkovsky() {
    m_p = 1;
}
Minkovsky::Minkovsky(std::vector<double> v1, std::vector<double> v2, double p) : distanceAlgorithems(v1,v2)
 {
    m_p = p;
} 
double Minkovsky::calculatedistance() {
double sum = 0;
std::vector<double>::iterator itdiff = m_diffVec.begin();
	for (itdiff; itdiff != m_diffVec.cend(); ++itdiff) {
		sum += pow(*itdiff,m_p);
	}
	sum = pow(sum, (1 / m_p));
	return sum;
}
double Minkovsky::calculatedistance(std::vector<double> v2) {
    distanceAlgorithems::setVectors(m_vec1, v2);
    return calculatedistance();
}
double Minkovsky::calculatedistance(std::vector<double> v1, std::vector<double> v2) {
    distanceAlgorithems::setVectors(v1,v2);
    return calculatedistance();
}
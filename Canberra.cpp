#include "Canberra.h"
Canberra::Canberra(std::vector<double> v1, std::vector<double> v2) : distanceAlgorithems(v1,v2) {
    std::cout<<"in canberra"<<std::endl;
}
double Canberra::calculatedistance() {
double sum = 0;
	std::vector<double>::const_iterator itdiff = m_diffVec.cbegin();
	std::vector<double>::const_iterator itv1 = m_vec1.cbegin();
	std::vector<double>::const_iterator itv2 = m_vec2.cbegin();
	for (itdiff; itdiff != m_diffVec.cend(); ++ itdiff) {
		double s = fabs(*itv1) + fabs(*itv2);
		if (s == 0) {
			++itv1,++itv2;
		}
		else {
			sum += (fabs(*itdiff) / s);
		}
	}
return sum;
}
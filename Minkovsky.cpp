#include "Minkovsky.h"
Minkovsky::Minkovsky(std::vector<double> v1, std::vector<double> v2, double p) : distanceAlgorithems(v1,v2)
 {
m_p = p;
} 
double Minkovsky::calculatedistance() {
double s = 0;

std::vector<double>::iterator itdiff = m_diffVec.begin();
	for (itdiff; itdiff != m_diffVec.cend(); ++itdiff) {
		double addedvalue;
		int n = floor(p);
		double y = p - n;
		
		addedvalue = pow(*itdiff, n) * pow(*itdiff, y);
		sum += addedvalue;
	}
	sum = pow(sum, (1 / p));
	
	}
	return s;

}
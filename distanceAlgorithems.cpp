
#include "mainHeader.h"
#include <cmath>


distanceAlgorithems::distanceAlgorithems(const std::vector<double>& vec1, const std::vector<double>& vec2) {
	
	m_vec1 = vec1;
	m_vec2 = vec2;
	//diffVec = { 0 };
	m_diffVec = m_vecMan.deductionF(m_vec1, m_vec2);
}

double distanceAlgorithems::euclideanDistance() {
double sum;
std::vector<double>::iterator iter = m_diffVec.begin();
	for (iter; iter != m_diffVec.end(); ++iter) {
		sum += (*iter) * (*iter);
	}
	return sqrt(sum);
}





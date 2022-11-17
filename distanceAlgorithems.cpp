#include "distanceAlgorithems.h"
#include <cmath>

distanceAlgorithems::distanceAlgorithems(const std::vector<double>& vec1, const std::vector<double>& vec2) {
	
	m_vec1 = vec1;
	m_vec2 = vec2;
	diffVec = { 0 };
	//m_diffVec = m_vecMan.diff(m_vec1, m_vec2);
}

double sum;
std::vector<double>::iterator iter = distanceAlgorithems::diffVec.begin();
double distanceAlgorithems::euclideanDistance() {
	for (iter; iter != m_diffVec.end(); ++iter) {
		sum += iter * iter;
	}
	return sqrt(sum);
}

int main() {
	return 0;
}




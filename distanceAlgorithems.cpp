
#include "distanceAlgorithems.h"

distanceAlgorithems::distanceAlgorithems(std::vector<double> vec1, std::vector<double> vec2) {
	m_vec1 = vec1;
	m_vec2 = vec2;
	m_diffVec = deductionF(vec1, vec2);
}
//eucalidean distance by defualt
double distanceAlgorithems::calculatedistance() {
double sum = 0;
std::vector<double>::iterator iter = m_diffVec.begin();
	for (iter; iter != m_diffVec.end(); ++iter) {
		sum += pow(*iter,2);
	}
	return sqrt(sum);
}
void distanceAlgorithems::setVectors(std::vector<double> vec1, std::vector<double> vec2) {
	m_vec1 = vec1;
	m_vec2 = vec2;
	m_diffVec = deductionF(vec1, vec2);
}




#include "Manhatan.h"
Manhatan::Manhatan(std::vector<double> v1, std::vector<double> v2) : distanceAlgorithems(v1,v2) {
    std::cout<<"in Manhatan"<<std::endl;
}
double Manhatan::calculatedistance() {
double s = AbsSumIndividualeVector(m_diffVec);
	return s;
}
double Manhatan::calculatedistance(std::vector<double> v2) {
distanceAlgorithems::setVectors(m_vec1, v2);
    return calculatedistance();

}
double Manhatan::calculatedistance(std::vector<double> v1, std::vector<double> v2) {
        distanceAlgorithems::setVectors(v1,v2);
     return calculatedistance();

    }
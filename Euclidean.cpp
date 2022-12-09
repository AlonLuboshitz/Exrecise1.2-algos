#include "Euclidean.h"
Euclidean::Euclidean(std::vector<double> v1, std::vector<double> v2) : distanceAlgorithems(v1,v2)
 {
    std::cout<<"in Euc"<<std::endl;
}
double Euclidean::calculatedistance() {
    return distanceAlgorithems::calculatedistance();
}
double Euclidean::calculatedistance(std::vector<double> vec1) {
    return distanceAlgorithems::calculatedistance(vec1);
}
double Euclidean::calculatedistance(std::vector<double> vec1, std::vector<double> vec2) {
   return  distanceAlgorithems::calculatedistance(vec1, vec2);
}
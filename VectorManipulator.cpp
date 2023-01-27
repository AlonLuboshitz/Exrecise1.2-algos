#include "VectorManipulator.h"
#include "inputValidation.h"
// deducts one vector from another.
const std::vector<double> deductionF(const std::vector<double> v1,const std::vector<double> v2) {
    if (v1.size() != v2.size()) {
        std::cout<< "cant deduct diffrenet size vectors";
   }
    //init deduction vector with zeros
    std::vector<double> deductV(v1.size(), 0);
    //init iterators.
    std::vector<double>::const_iterator itV1 = v1.cbegin();
    std::vector<double>::const_iterator itV2 = v2.cbegin();
    std::vector<double>::iterator itdeducV = deductV.begin();
    int i = 1;
    for (itV1; itV1 != v1.cend(); ++itV1) {
        //std::cout << "deducting v1 - v2 in "<<i<<" place " << *itV1<<" - "<< *itV2<<std::endl;
        double s = *itV1 - *itV2;
        *itdeducV = s;
        ++itV2;
        ++itdeducV;
        i++;
    }
    const std::vector<double> returnedvector = deductV;
    return returnedvector;
}

// sums the absoulute values in a vector.
const double AbsSumIndividualeVector(std::vector<double> v1){
    double sum = 0;
    for (std::vector<double>::const_iterator it = v1.cbegin(); it != v1.cend(); ++it){
        sum = sum + fabs(*it);
    }
    return sum;
}
//iterated on vector and print it.
void PrintVec(std::vector<double> v1) {
    for (std::vector<double>::const_iterator it = v1.cbegin();
     it != v1.cend(); ++it){
       std::cout << *it << " ,";
    }
    std::cout<<std::endl;
}
//converts vector of strings to vector of doubles
std::vector<double> convertVectorToDoubles(std::vector<std::string>& vec) {
    std::vector<std::string>::iterator vectorIterator = vec.begin();
    std::vector<double> doubleVector;
   for (vectorIterator; vectorIterator != vec.end(); ++vectorIterator) {
        stringCleaner((*vectorIterator));
        if (is_number(*vectorIterator)){
            doubleVector.push_back(std::stod(*vectorIterator));
        }
}
return doubleVector;
}
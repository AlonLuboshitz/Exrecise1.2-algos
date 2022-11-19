
#include <iostream>
#include "mainHeader.h"
using namespace std;

const vector<double> VectorManipulator::deductionF(const vector<double> v1,const vector<double> v2) {
    if (v1.size() != v2.size()) {
        cout<< "cant deduct diffrenet size vectors";
   }
    //init deduction vector with zeros
    vector<double> deductV(v1.size(), 0);
    PrintVec(deductV);
    
    //init iterators.
    vector<double>::const_iterator itV1 = v1.cbegin();
    vector<double>::const_iterator itV2 = v2.cbegin();
    vector<double>::iterator itdeducV = deductV.begin();
    int i = 1;
    for (itV1; itV1 != v1.cend(); ++itV1) {
        cout << "deducting v1 - v2 in "<<i<<" place " << *itV1<<" - "<< *itV2<<endl;
        double s = *itV1 - *itV2;
        *itdeducV = s;
        ++itV2;
        ++itdeducV;
        i++;
    }
    PrintVec(deductV);
    const vector<double> returnedvector = deductV;
    return returnedvector;
}
const double VectorManipulator::AbsSumIndividualeVector(vector<double> v1){
    double sum = 0;
    for (vector<double>::const_iterator it = v1.cbegin(); it != v1.cend(); ++it){
        sum = sum + fabs(*it);
    }
    return sum;
}
void VectorManipulator::PrintVec(vector<double> v1) {
    for (vector<double>::const_iterator it = v1.cbegin();
     it != v1.cend(); ++it){
       cout << *it << " ,";
    }
    cout<<endl;
}


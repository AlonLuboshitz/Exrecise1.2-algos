#include <vector>
#include <iostream>
#include "VectorManipulator.h"
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

    
    
    return deductV;
}
void VectorManipulator::PrintVec(vector<double> v1) {
    for (vector<double>::const_iterator it = v1.cbegin();
     it != v1.cend(); ++it){
       cout << *it << " ,";
    }
    cout<<endl;
}

int main() {
    VectorManipulator vectormani;
    vector<double> v1 = {1.3,2.6,3.2,4,5};
    vector<double> v2 = {2,3,4,5,6};
    vectormani.deductionF(v1,v2);
}
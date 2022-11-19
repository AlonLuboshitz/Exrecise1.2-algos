
#ifndef VECTORMANIPULATOR_H
#define VECTORMANIPULATOR_H
#include "mainHeader.h"
#include <vector>
class VectorManipulator {
    public:
    const std::vector<double> deductionF(const vector<double> v1, const vector<double> v2);
    const vector<double> sumMultipleVectors(vector<double> v1, vector<double> v2);
    const vector<double> sumIndividualeVector(vector<double> v);
    void PrintVec(vector<double>);
};
#endif
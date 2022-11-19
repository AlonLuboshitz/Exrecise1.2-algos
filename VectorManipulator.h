#include <cmath>
#include <vector>
using std::vector;
class VectorManipulator {
    public:
    const vector<double> deductionF(const vector<double> v1, const vector<double> v2);
    const double sumMultipleVectors(vector<double> v1, vector<double> v2);
    const double AbsSumIndividualeVector(vector<double> v);
    void PrintVec(vector<double>);
};
#include "distanceAlgorithems.h"
#include "Euclidean.h"
#include "Manhatan.h"
#include "Chevichev.h"
#include "Canberra.h"
#include "Minkovsky.h"
#include <string>

void getVectorFromInput(std::vector<double>& vec );
void printDecimal(double x);
void isSameSize(std::vector<double>& v1, std::vector<double>& v2);
bool is_number(const std::string& s);
bool allDoubleVector(const std::vector<double> vec);
distanceAlgorithems distAlgoFactory(std::string str);
void getArguments(int argc,char* argv[]);

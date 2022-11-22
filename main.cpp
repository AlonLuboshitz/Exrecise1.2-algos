#include "distanceAlgorithems.h"
#include "inputValidation.h"

int main() {
	std::vector<double> v1;
	std::vector<double> v2;
	
	isSameSize(v1, v2);
	initDistanceVec(v1,v2);
	printDecimal(euclideanDistance());
	printDecimal(manhatanDistance());
	printDecimal(cevicheDistance());
	printDecimal(canberraDistance());
	printDecimal(minkovskyDistance(2));
	
	return 0;
}
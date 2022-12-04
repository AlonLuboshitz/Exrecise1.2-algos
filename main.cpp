#include "distanceAlgorithems.h"
#include "inputValidation.h"

int main() {
	std::vector<double> v1;
	std::vector<double> v2;
	isSameSize(v1, v2);
	distanceAlgorithems distanceAlgorithems(v1,v2);
	printDecimal(distanceAlgorithems.euclideanDistance());
	printDecimal(distanceAlgorithems.manhatanDistance());
	printDecimal(distanceAlgorithems.cevicheDistance());
	printDecimal(distanceAlgorithems.canberraDistance());
	printDecimal(distanceAlgorithems.minkovskyDistance(2));
	
	return 0;
}
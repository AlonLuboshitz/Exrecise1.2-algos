#include "distanceAlgorithems.h"

int main() {
	std::vector<double> v1;
	std::vector<double> v2;
	
	while (1) {
	getVectorFromInput(v1);
	getVectorFromInput(v2);
	if (v1.size() == v2.size()) {
		break;
	}else {
		v1.clear();
		v2.clear();
		std::cout <<"vectors are not the same size. please insert new 2 same sized vectors.\n";
	}
	}

	initDistanceVec(v1,v2);
	printDecimal(euclideanDistance());
	printDecimal(manhatanDistance());
	printDecimal(cevicheDistance());
	printDecimal(canberraDistance());
	printDecimal(minkovskyDistance(2));
	return 0;
}
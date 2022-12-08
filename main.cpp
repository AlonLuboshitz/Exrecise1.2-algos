#include "distanceAlgorithems.h"
#include "inputValidation.h"
#include "Euclidean.h"
#include "Manhatan.h"
#include "Canberra.h"
#include "check.h"
#include "Minkovsky.h"

int main() {
	std::vector<double> v1 = {1,2,3} ;
	std::vector<double> v2 = {3,2,1};
		std::vector<double> v3 = {2,3,4};
	std::vector<double> v4 = {10,11,12};

	distanceAlgorithems dis(v1,v2);
	Euclidean euc(v1,v2);
	 Manhatan man(v1,v2);
	// Canberra can(v1, v2);
	// //Minkovsky min(v1,v2, 2);
	// check cc(euc);
	printDecimal(dis.calculatedistance());
	printDecimal(dis.calculatedistance(v2));
	printDecimal(dis.calculatedistance(v1,v2));
	printDecimal(dis.calculatedistance(v2,v4));
	printDecimal(man.calculatedistance());
	printDecimal(man.calculatedistance(v2));
	printDecimal(man.calculatedistance(v1,v2));
	printDecimal(man.calculatedistance(v2,v4));
	
	
	//printDecimal(distanceAlgorithems.minkovskyDistance(2));
	
	return 0;
}
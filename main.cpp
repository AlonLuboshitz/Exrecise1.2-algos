#include "distanceAlgorithems.h"
#include "inputValidation.h"
#include "Euclidean.h"
#include "Manhatan.h"
#include "Canberra.h"
#include "check.h"
#include "Minkovsky.h"

int main() {
	std::vector<double> v1;
	std::vector<double> v2;
	isSameSize(v1, v2);
	distanceAlgorithems dis(v1,v2);
	Euclidean euc(v1,v2);
	Manhatan man(v1,v2);
	Canberra can(v1, v2);
	Minkovsky min(v1,v2, 2);
	check cc(euc);
	printDecimal(euc.calculatedistance());
	printDecimal(dis.calculatedistance());
	printDecimal(cc.cal());
	cc.setdis(man);
	
	printDecimal(man.calculatedistance());
		printDecimal(cc.cal());
cc.setdis(can);
	//printDecimal(dis.cevicheDistance());
	
	printDecimal(can.calculatedistance());
	printDecimal(cc.cal());
	cc.setdis(min);
    printDecimal(min.calculatedistance());
    printDecimal(cc.cal());



	
	//printDecimal(distanceAlgorithems.minkovskyDistance(2));
	
	return 0;
}
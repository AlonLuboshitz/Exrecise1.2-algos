#include "distanceAlgorithems.h"
#include "inputValidation.h"
#include "Euclidean.h"
#include "Manhatan.h"
#include "Canberra.h"
#include "check.h"
#include "Minkovsky.h"
#include "Chevichev.h"

int main() {
	std::vector<double> v1 = {1,2,3} ;
	std::vector<double> v2 = {3,2,1};
		std::vector<double> v3 = {2,3,4};
	std::vector<double> v4 = {10,11,12};

	distanceAlgorithems dis(v1,v4);
	Euclidean euc(v1,v4);
	 Manhatan man(v1,v4);
	Canberra can(v1,v4);
	Minkovsky min(v1,v4, 2);
	Chevichev che(v1,v4);
	check cc(euc);
	printDecimal(cc.cal());
	cc.setdis(man);
		printDecimal(cc.cal());
		cc.setdis(che);
	printDecimal(cc.cal());
	cc.setdis(can);
	printDecimal(cc.cal());
	cc.setdis(min);
	printDecimal(cc.cal());
cc.setdis(euc);
		printDecimal(cc.cal(v2));
		cc.setdis(man);
		printDecimal(cc.cal(v2));
		cc.setdis(che);
	printDecimal(cc.cal(v2));
	cc.setdis(can);
	printDecimal(cc.cal(v2));
	cc.setdis(min);
	printDecimal(cc.cal(v2));
	
	
	
	//printDecimal(distanceAlgorithems.minkovskyDistance(2));
	
	return 0;
}
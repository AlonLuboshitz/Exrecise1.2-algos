#include "distanceAlgorithems.h"
#include "inputValidation.h"
#include "Euclidean.h"
#include "Manhatan.h"
#include "Canberra.h"
#include "check.h"
#include "Minkovsky.h"
#include <map>
#include <iostream>
#include "KNN.h"
#include "CSVReader.h"


int main(int argc,char* argv[]){
	int k;
	std::string filePath;
	//distanceAlgorithems disAlgo;
	if (argc != 4)	{
		std::cout << "please enter 4 arguments as follows : a.out k file distance";
	}
	int checkK = atoi(argv[1]);
	if (checkK > 0){
		k = checkK;
	} else std::cout << "k is not a positive integer";
	
	



	return 0;
}
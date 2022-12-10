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
	// std::string file = "file";
	// std::string three = "3";
	// std::string hi = "hi";
	// std::string al = "al";
	// char* gili[5] = {&file[0], &three[0], &hi[0], &al[0], &three[0]};
	
	
		
	int k;
	std::string filePath;
	distanceAlgorithems disAlgo;
	getArguments(argc, argv);
	k = atoi(argv[1]);
	filePath = argv[2];
	disAlgo = distAlgoFactory(argv[3]);
	CSVReader csvReader(filePath);
	std::vector<double> inputVector;

	while (true){
		getVectorFromInput(inputVector);
		KNN knn(inputVector, disAlgo, csvReader, k);
		std::cout << "\n" << knn.runKNN() << "\n";
	}

	return 0;
}

#include <map>
#include <iostream>
#include "KNN.h"
#include "CSVReader.h"
#include <bits/stdc++.h>



int main(int argc,char* argv[]){
	// std::string file = "file";
	// std::string three = "3";
	// std::string hi = "hi";
	// std::string al = "al";
	// char* gili[5] = {&file[0], &three[0], &hi[0], &al[0], &three[0]};
	

	char* checkedArgv[4];
	if (argc != 0){
	for (int i=0; i < argc; i++ ){
		checkedArgv[i] = argv[i];
	}
	}
	int k;
	std::string s_k = checkedArgv[1];
	std::string filePath;
	distanceAlgorithems disAlgo;
	CSVReader csvReader;
	getArguments(argc, checkedArgv, csvReader);
	k = atoi(argv[1]);
	filePath = argv[2];
	disAlgo = distAlgoFactory(argv[3]);
	std::vector<double> inputVector;
	getVectorFromInput(inputVector);
	KNN knn(inputVector, disAlgo, csvReader, k);
	bool flag = true;
	while (true){
		if (flag) {
		std::cout << knn.runKNN() << "\n";
		flag = false;
		} else {
			inputVector.clear();
			getVectorFromInput(inputVector);
			knn.setInputVector(inputVector);
			std::cout << knn.runKNN() << "\n";
		}
	}

	return 0;

}
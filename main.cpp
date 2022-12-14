
#include <map>
#include <iostream>
#include "KNN.h"
#include "CSVReader.h"
#include <bits/stdc++.h>



int main(int argc,char* argv[]){
	char* checkedArgv[4];
	int loops = argc;
	if (argc !=0){ 
		if (argc > 4) {
			loops = 4;
		}
	for (int i=0; i < loops; i++ ){
		checkedArgv[i] = argv[i];
	}
	}
	int k;
	std::string s_k = checkedArgv[1];
	std::string filePath = checkedArgv[2];
	std::string s_disAlgo = checkedArgv[3];
	CSVReader csvReader;
	getArguments(argc, s_k, filePath, s_disAlgo, csvReader);
	k = stoi(s_k);
	distanceAlgorithems* disAlgo = distAlgoFactory(s_disAlgo);
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
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
	
CSVReader csv("datasets/beans/beans_Classified.csv");
    // std::vector<double> vec1;
    // std::vector<double> vec2;
    // getVectorFromInput(vec1);
    // getVectorFromInput(vec2);
    
    // Euclidean euc(vec1,vec2);
    // KNN knn(vec1,euc,csv,3);
    // std::string str = knn.runKNN();





	
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
	filePath = argv[2];
	
	
	



	return 0;
}
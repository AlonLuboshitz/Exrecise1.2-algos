#include <iostream>
#include "mainHeader.h"

int main() {
	std::vector<double> v1 = {1, 2, 3};
	std::vector<double> v2 = {3 , 2 ,1};

	distanceAlgorithems dis(v1, v2);
	std::cout<< dis.euclideanDistance();

	/*
	double x;
	while (1) {
		std::cin >> x;
		if (std::cin.get() == ' ') {
			std::cin.clear();
			std::cin.get();
			return 0;
		}
		

		//std::getline(std::cin, x, ' ');
		if (std::cin.good()) {
			v1.push_back(x);
			std::cout << "im good";

			if (std::cin.get() == ' ') {
				std::cin.clear();
				std::cin.get();
				return 0;
			}



			//continue;
		}
		else if (std::cin.get() == ' ') {
			//continue;
		}
		else if (std::cin.get() == '\n') {
			//break;
		}
		else if (std::cin.fail() || std::cin.bad()) {
			std::cin.clear();
			std::cin.get();
			std::cout << "fail - invalid value. please input a numerical value.";
		}
		else {
			std::cin.clear();
			std::cin.get();
			std::cout << " else- invalid value. please input a numerical value.";
			
		}

	}*/

}
#include <iostream>
#include "mainHeader.h"
#include <vector>
#include <sstream>
#include<string>
#include <cstdlib>

//this function checks if the string from the string stream is a valid double
//returns true if the string is a double
//returns false if not
bool is_number(const std::string& s) {
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0';
}

//this function gets a refrence to a vector
// reads input from the user using cin and get line which returns the string input which ends with '\n'
// using the strean string >> operator gets one "word" - string seperater with spaces in the line 
// checks if the string is a valid double using is_number function
// puts each valis double in the vector
// if there is an invalid "word", starting from the beggining
void getVectorFromInput(std::vector<double> vec ){
	double x;
	std::string input;
	std::getline(std::cin, input);
	std::stringstream stream(input);
	std::string num;
	while (stream >> num) {
		if (is_number(num)) {
			x = std::stod(num);
			vec.push_back(x);
		}
		else {
			vec.clear();
			std::cout<<"invalid input. please try again.\n";
			std::getline(std::cin, input);
			stream.str(std::string());
			stream<<input;
		
		}
	}
}

int main() {
	std::vector<double> v1;
	std::vector<double> v2;

	getVectorFromInput(v1);
	getVectorFromInput(v2);

	
}
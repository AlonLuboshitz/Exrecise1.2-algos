#include "inputValidation.h"
//this function gets a refrence to a vector
// reads input from the user using cin and get line which returns the string input which ends with '\n'
// using the strean string >> operator gets one "word" - string seperater with spaces in the line 
// checks if the string is a valid double using is_number function
// puts each valis double in the vector
// if there is an invalid "word", starting from the beggining
void getVectorFromInput(std::vector<double>& vec ){
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
			stream.str(" ");
			stream.clear();
			std::cout<<"invalid input. please try again.\n";
			std::getline(std::cin, input);
			stream << input;
		
		}
	}
}

// prints a set number of values after decimal point depanding on double or int num.
void printDecimal(double x) {
	if ((int)x == x) {
		std::fixed(std::cout);
		std::cout.precision(1);
		std::cout<<x<<std::endl;
	}
	else {
		std::fixed(std::cout);
		std::cout.precision(16);
		std::cout<<x<<std::endl;
	}
} 


//this function checks if the string from the string stream is a valid double
//returns true if the string is a double
//returns false if not
bool is_number(const std::string& s) {
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0';
}


//gets vectors from input using getVectorFromInput function. 
//if the vectors are not the same size, asks the user to insert 2 vectors again
// continue until the 2 vectors are the same size.
void isSameSize(std::vector<double>& v1, std::vector<double>& v2) {
    while (1) {
	getVectorFromInput(v1);
	getVectorFromInput(v2);
	if (v1.size() == v2.size()) {
		break;
	}else {
		v1.clear();
		v2.clear();
		std::cout <<"vectors are not the same size. please insert new 2 same sized vectors.\n";
	}
	}

}
//checks if every string in vector of string is considered as double
bool allDoubleVector(const std::vector<std::string> vec) {
	std::vector<std::string>::const_iterator vectorIterator = vec.cbegin();
   for (vectorIterator; vectorIterator != vec.cend(); ++vectorIterator){
		if (! is_number(*vectorIterator)){
			return false;
		}
   } return true;
}
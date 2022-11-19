#include <cmath>
#include "distanceAlgorithems.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

// distanceAlgorithems::distanceAlgorithems(std::vector<double> vec1,  std::vector<double> vec2) {
	
// 	 m_vec1 = vec1;
// 	m_vec2 = vec2;
// 	m_diffVec = deductionF(m_vec1, m_vec2);
// }
std::vector<double> m_vec1;
	std::vector<double> m_vec2;
	std::vector<double> m_diffVec;
void initDistanceVec(std::vector<double> vec1, std::vector<double> vec2) {
	m_vec1 = vec1;
	m_vec2 = vec2;
	m_diffVec = deductionF(m_vec1,m_vec2);
}
double manhatanDistance() {
	double s = AbsSumIndividualeVector(m_diffVec);
	return s;
}
double cevicheDistance() {
	double max = -1;
    for (std::vector<double>::const_iterator it = m_diffVec.cbegin(); it != m_diffVec.cend(); ++it){
        if (fabs(*it) > max) {
			max = *it;
		}
    }
    return max;
}
double canberraDistance() {
	double sum = 0;
	std::vector<double>::const_iterator itdiff = m_diffVec.cbegin();
	std::vector<double>::const_iterator itv1 = m_vec1.cbegin();
	std::vector<double>::const_iterator itv2 = m_vec2.cbegin();
	for (itdiff; itdiff != m_diffVec.cend(); ++ itdiff) {
		double s = fabs(*itv1) + fabs(*itv2);
		if (s == 0) {
			++itv1,++itv2;
		}
		else {
			sum += (fabs(*itdiff) / s);
		}
	}
return sum;
}
double minkovskyDistance(double p) {
double sum = 0;
	if (p==1) {
		sum = manhatanDistance();
		return sum;
	}
	else //p==2
	 {
		sum = euclideanDistance();
		return sum;
	}
	// else {
	// std::vector<double>::iterator itdiff = m_diffVec.begin();
	// for (itdiff; itdiff != m_diffVec.cend(); ++itdiff) {
	// 	double addedvalue;
	// 	int n = floor(p);
	// 	double y = p - n;
		
	// 	addedvalue = pow(*itdiff, n) * pow(*itdiff, y);
	// 	sum += addedvalue;
	// }
	// sum = pow(sum, (1 / p));
	
	// }
	return sum;
}




double euclideanDistance() {
double sum = 0;
std::vector<double>::iterator iter = m_diffVec.begin();
	for (iter; iter != m_diffVec.end(); ++iter) {
		sum += pow(*iter,2);
	}
	return sqrt(sum);
}
const std::vector<double> deductionF(const std::vector<double> v1,const std::vector<double> v2) {
    if (v1.size() != v2.size()) {
        std::cout<< "cant deduct diffrenet size vectors";
   }
    //init deduction vector with zeros
    std::vector<double> deductV(v1.size(), 0);
    //init iterators.
    std::vector<double>::const_iterator itV1 = v1.cbegin();
    std::vector<double>::const_iterator itV2 = v2.cbegin();
    std::vector<double>::iterator itdeducV = deductV.begin();
    int i = 1;
    for (itV1; itV1 != v1.cend(); ++itV1) {
        std::cout << "deducting v1 - v2 in "<<i<<" place " << *itV1<<" - "<< *itV2<<std::endl;
        double s = *itV1 - *itV2;
        *itdeducV = s;
        ++itV2;
        ++itdeducV;
        i++;
    }
    const std::vector<double> returnedvector = deductV;
    return returnedvector;
}

const double AbsSumIndividualeVector(std::vector<double> v1){
    double sum = 0;
    for (std::vector<double>::const_iterator it = v1.cbegin(); it != v1.cend(); ++it){
        sum = sum + fabs(*it);
    }
    return sum;
}

void PrintVec(std::vector<double> v1) {
    for (std::vector<double>::const_iterator it = v1.cbegin();
     it != v1.cend(); ++it){
       std::cout << *it << " ,";
    }
    std::cout<<std::endl;
}
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
	initDistanceVec(v1,v2);
	std::cout<<euclideanDistance()<<std::endl;
	std::cout<<manhatanDistance()<<std::endl;
	std::cout<<cevicheDistance()<<std::endl;
    std::cout<<canberraDistance()<<std::endl;
    std::cout<<minkovskyDistance(1.2)<<std::endl;

	
}
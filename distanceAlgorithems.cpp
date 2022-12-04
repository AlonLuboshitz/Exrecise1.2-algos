
#include "distanceAlgorithems.h"
#include "VectorManipulator.h"

distanceAlgorithems::distanceAlgorithems(std::vector<double> vec1, std::vector<double> vec2) {
	m_vec1 = vec1;
	m_vec2 = vec2;
	m_diffVec = deductionF(vec1, vec2);
}
//eucalidean distance 
double distanceAlgorithems::calculatedistance() {
double sum = 0;
std::vector<double>::iterator iter = m_diffVec.begin();
	for (iter; iter != m_diffVec.end(); ++iter) {
		sum += pow(*iter,2);
	}
	return sqrt(sum);
}

double distanceAlgorithems::manhatanDistance() {
	double s = AbsSumIndividualeVector(m_diffVec);
	return s;
}

double distanceAlgorithems::cevicheDistance() {
	double max = -1;
    for (std::vector<double>::const_iterator it = m_diffVec.cbegin(); it != m_diffVec.cend(); ++it){
        if (fabs(*it) > max) {
			max = *it;
		}
    }
    return max;
}

double distanceAlgorithems::canberraDistance() {
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

double distanceAlgorithems::minkovskyDistance(double p) {
double sum = 0;
	if (p==1) {
		sum = manhatanDistance();
		return sum;
	}
	else if (p==2)
	 {
		sum = euclideanDistance();
		return sum;
	}
	else return 0;
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

// double distanceAlgorithems::euclideanDistance() {
// double sum = 0;
// std::vector<double>::iterator iter = m_diffVec.begin();
// 	for (iter; iter != m_diffVec.end(); ++iter) {
// 		sum += pow(*iter,2);
// 	}
// 	return sqrt(sum);
// }


// deducts one vector from another.
// const std::vector<double> distanceAlgorithems::deductionF(const std::vector<double> v1,const std::vector<double> v2) {
//     if (v1.size() != v2.size()) {
//         std::cout<< "cant deduct diffrenet size vectors";
//    }
//     //init deduction vector with zeros
//     std::vector<double> deductV(v1.size(), 0);
//     //init iterators.
//     std::vector<double>::const_iterator itV1 = v1.cbegin();
//     std::vector<double>::const_iterator itV2 = v2.cbegin();
//     std::vector<double>::iterator itdeducV = deductV.begin();
//     int i = 1;
//     for (itV1; itV1 != v1.cend(); ++itV1) {
//         //std::cout << "deducting v1 - v2 in "<<i<<" place " << *itV1<<" - "<< *itV2<<std::endl;
//         double s = *itV1 - *itV2;
//         *itdeducV = s;
//         ++itV2;
//         ++itdeducV;
//         i++;
//     }
//     const std::vector<double> returnedvector = deductV;
//     return returnedvector;
// }



//main calls getVectorFromInput twice inorder to get 2 vectors from the users
//than it checks if the 2 vectors are the same size
// if not it displays an error messege, and starts from the begginig.
// after validation sends vectors to algos distances.
// int main() {
// 	std::vector<double> v1;
// 	std::vector<double> v2;
	
// 	while (1) {
// 	getVectorFromInput(v1);
// 	getVectorFromInput(v2);
// 	if (v1.size() == v2.size()) {
// 		break;
// 	}else {
// 		v1.clear();
// 		v2.clear();
// 		std::cout <<"vectors are not the same size. please insert new 2 same sized vectors.\n";
// 	}
// 	}

// 	initDistanceVec(v1,v2);
// 	printDecimal(euclideanDistance());
// 	printDecimal(manhatanDistance());
// 	printDecimal(cevicheDistance());
// 	printDecimal(canberraDistance());
// 	printDecimal(minkovskyDistance(2));
// 	return 0;
// }


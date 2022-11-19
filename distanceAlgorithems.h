#include <iostream>
#include <vector>
class distanceAlgorithems {
private:
	std::vector<double> m_vec1;
	std::vector<double> m_vec2;
	std::vector<double> diffVec;


	//vectorManipulator m_vecMan;
	//add vector manipulator
public:
	//std::vector<double> diffVec = { 0 };
	distanceAlgorithems(const std::vector<double>& vec1, const std::vector<double>& vec2);
	double euclideanDistance();
};
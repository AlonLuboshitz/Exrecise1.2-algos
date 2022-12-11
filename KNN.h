#ifndef KNN_H
#define KNN_H
#include <vector>
#include <string>
#include "distanceAlgorithems.h"
#include <utility>
#include <map>
#include "inputValidation.h"
#include <limits>
#include <bits/stdc++.h>
#include "VectorManipulator.h"
#include "CSVReader.h"

class KNN {
private:
std::vector<double> m_inputVector;
CSVReader* m_csvReader;
std::vector<std::string> m_tempVector; 
unsigned int m_k;
distanceAlgorithems* m_disAlgo;
// map?
unsigned int m_sizeOfInputVec;
//std::vector<std::pair<std::string,std::vector<double>>> pairsOfData;
struct neighbor {
    std::string label;
std::vector<double> data;
double distance;
};
std::vector<neighbor> neighbors;
bool init;
std::map<std::string, int> labelsMap;
    
//bool getNextVector();
int tempVectorValidation();
std::string getLabel(int index);
void sortNeighbors();
//void insertPair(const std::string name, const std::vector<double>);
void insertNeighbors(const std::string name, const std::vector<double>);
void eraseStringFromTemp(int index);
bool compareNeighbors(const neighbor& n1, const neighbor& n2);
void calculateNeighborsDistances();
std::string findKNearest();
void initiation();


public: 
KNN() = delete;
KNN (std::vector<double> inputVector,distanceAlgorithems& disAlgo, CSVReader& csvReader, const unsigned int k);
std::string runKNN();
void setDistanceAlgorithem(distanceAlgorithems& disAlgo);
void setNewFile(std::string path);
void setInputVector(std::vector<double> inputVector);
};

#endif

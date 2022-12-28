#include "KNN.h"


KNN::KNN(CSVReader& csvReader){
    m_csvReader = &csvReader;
    initiation();
    init = false;
}
KNN::KNN (const std::vector<double> inputVector, distanceAlgorithems* disAlgo, CSVReader& csvReader ,unsigned int k) {
    m_inputVector = inputVector;
    m_disAlgo = disAlgo;
    if (k>0) {
        m_k = k;
    }
    m_csvReader = &csvReader;
    m_sizeOfInputVec = m_inputVector.size();
    init = true;
}
KNN::~KNN() {
    delete m_disAlgo;
}


/**
* comperator - compares 2 neighbors according to their distance
*/
bool KNN::compareNeighbors(const neighbor& n1, const neighbor& n2){
return(n1.distance < n2.distance);
}


/**runs test-
 * if there's only one string that is not double in the vector, considers it as the vector's label
 * and return its index
 * if the test failes- return -1
**/
int KNN::tempVectorValidation() {
    //int sizeOfTemp = m_tempVector.size();
    std::string tempLabel;
    int numOfStrings = 0;
    int labelIndex = 0;
    int i = -1;
    //size of temp should ve size of input's variables + string name
   std::vector<std::string>::const_iterator tempIterator = m_tempVector.cbegin();
   std::string temp;
   std::string clearedTemp;
   for (tempIterator; tempIterator != m_tempVector.cend(); ++tempIterator) {
        i++;
        temp = *tempIterator;
        stringCleaner(temp);
        //if its not double- it's considered as the name of the vector's label
        if (! is_number(temp)) {
            tempLabel = *tempIterator;
            numOfStrings++;
            labelIndex = i;
             // if there is more than one label, return error
            if (numOfStrings > 1) {
            return -1;
            }
        }
    }
    //if no strings found
    if (numOfStrings == 0){
        return -1;
    }
    return labelIndex;
}
/**
 * gets label (string) according to an index of the tempVector
*/
std::string KNN:: getLabel(int index){
    std::string label = m_tempVector.at(index);
    return label;
}

void KNN::insertNeighbors(const std::string name, const std::vector<double> vec){
    neighbor n;
    n.label = name;
    n.data = vec;
    n.distance = 0;
    neighbors.push_back(n);
}

/**
 * erases string from temp vector at given index
*/
void KNN::eraseStringFromTemp(int index){
    std::vector<std::string>::iterator indexIterator;
    indexIterator = m_tempVector.begin() + index;
    m_tempVector.erase(indexIterator);
}


/**
 * runs on all neighbors- 
 * if the data vector is the same size of the input vector- 
 * calculate the vector's distance from the input vector, according to the current distance algorithem
 * (else - the distance is set to be numeric_limits<double>::max (max value for double))
*/
void KNN::calculateNeighborsDistances(){
    std::vector<neighbor>::iterator neighborsIterator = neighbors.begin();
   for (neighborsIterator; neighborsIterator != neighbors.cend(); ++neighborsIterator) {
    if ((*neighborsIterator).data.size() == m_sizeOfInputVec) {
        (*neighborsIterator).distance = (*m_disAlgo).calculatedistance(m_inputVector, (*neighborsIterator).data);
    }
    else {
        (*neighborsIterator).distance = std::numeric_limits<double>::max();
    }
}
}

/**
 * sorts all the neighbors according to their distance from the input vector
*/
void KNN::sortNeighbors(){
    std::sort(KNN::neighbors.begin(), KNN::neighbors.end(), [](const KNN::neighbor& n1, const KNN::neighbor& n2) -> bool 
    {
    return(n1.distance < n2.distance);
    });
}

/**
 * runs on the K neighbors with the smallest distance from the input vector
 * inserts to map - key: label, value: quantity of vectors with the same label
 * if there is already the same label in the map - adds plus 1 to the quantity
 * else- create a new key with the kabel, with the quantity of 1
 * gets the label with the highest quantity (highest valuse in map will be first as default)
 * clears map
 * returns label
*/
std::string KNN::findKNearest(){
    // if the smallest distance is infinity 
    if (neighbors.at(0).distance == std::numeric_limits<double>::max()){
        return "no neighbors found";
    }
    int loops = neighbors.size();
    if (m_k < neighbors.size()) {
        loops = m_k;
    }
    labelsMap.insert(std::pair<std::string, int>(neighbors.at(0).label, 1));
    //runs k-1 loops
    for (int i = 1; i < loops; i++){
        // if we got to a neighbor which its distance from the input is infinity- break
        if (neighbors.at(i).distance == std::numeric_limits<double>::max()){
            break;
        }
        std::string tempLabel = neighbors.at(i).label;
        //if the map finds a key the same as the neighbor's label-
         //it increases its value by one (there is one more vector with this label)
       if (labelsMap.find(tempLabel) != labelsMap.end()){
            labelsMap.at(tempLabel)++;
       }
       // else- inserts the new label with the count of 1
       else {
        labelsMap.insert(std::pair<std::string, int>(tempLabel, 1));
       }
    }
    std::string kLabel =labelsMap.begin()->first;
    labelsMap.clear();
    return kLabel;
}

/**
 * gets info from csv reader ,line by line, and storage each vector as a neighbor: 
 * 1. get first data vector fron csv reader
 * 2. validate if the vector has only one label, if not continue to next vector.
 * 3. get label of the vector
 * 4. erase label from the vector
 * 5. convert the vector with variables only to a vector of doubles
 * 6. insert the data double vector and its label to a struct of a neighbor
 * 7. change the flag init to false -> there is no need to get the data from the file twice
*/
void KNN::initiation() {
    while ((*m_csvReader).getNewLine(m_tempVector)) {
    int index = tempVectorValidation();
    if (index < 0) {
        continue;
    }
    std::string label = getLabel(index);
    eraseStringFromTemp(index);
    std::vector<double> doubleVector = convertVectorToDoubles(m_tempVector);
    insertNeighbors(label, doubleVector);
}
init = false;
}

/**
 * 1. initiation - reading and storing the data from CSV 
 * 2. calculate the distance from each vector to the input vector
 * 3. sort all the neighbors
 * 4. get the most common label from the K nearest neighbors
*/
std::string KNN::runKNN() {
if (init){
    initiation();
}
if (neighbors.empty()){
        std::cout<< "no valid neighbors";
        return "-1";
 }
calculateNeighborsDistances();
sortNeighbors();
std::string kLabel = findKNearest();
return kLabel;
}
/**
 * setter- gets new distance algorithem
 * set m_disAlgo to the new distance algorithem
 * calculets new distances according to the new algorithem
*/
void KNN::setDistanceAlgorithem(distanceAlgorithems* disAlgo){
    m_disAlgo = disAlgo;
    calculateNeighborsDistances();
}
/**
 * setter- gets new file path as a string
 * set new file in the csv reader
 * clears the neighbors vector
 * init and storage the new file in the neighbors vector
*/
void KNN::setNewFile(std::string path){
    (*m_csvReader).setNewFile(path);
    neighbors.clear();
    initiation();
}
/**
 * setter- gets new input vector
 * sets m_inputVector to the new input vector
 * sets the m_sizeOfInputVector to the size of the new input vector 
*/
void KNN::setInputVector(std::vector<double> inputVector){
    m_inputVector = inputVector;
    m_sizeOfInputVec = inputVector.size();
   // calculateNeighborsDistances();
}

void KNN::setK(int k){
    if (k > 0){
        m_k = k;
    }
    else k = 1;
}

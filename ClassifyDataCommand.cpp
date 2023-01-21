#include "ClassifyDataCommand.h"

ClassifyDataCommand::ClassifyDataCommand(CSVReader& train, CSVReader& test,
 distanceAlgorithems*& dis,std::string& result, int& k,defualtIO& io) {
     m_train = &train;
    m_test = &test;
    m_validResult = false;
    m_distancealgo = dis;
    m_k = &k;
    m_result = &result;
    m_io = &io;
}
void ClassifyDataCommand::setParameters(int k, std::string algo) {
    if (k > 0) {
        m_Knn.setK(k);
    }
    distanceAlgorithems* temp = distAlgoFactory(algo);
    if (temp != NULL) {
        delete (m_distancealgo);
        (m_distancealgo) = temp;
    } 
}
void ClassifyDataCommand::setKNN(){
m_Knn.setCSVFile(m_train);
m_Knn.setK((*m_k));
m_Knn.setDistanceAlgorithem((m_distancealgo));
}
void ClassifyDataCommand::execute(){
    if ((*m_train).isFileSet() && (*m_test).isFileSet()) {
        setKNN();
       setResult();
       (*m_io).write("msg classifying data complete \nxxx");
    }
    else {
        (*m_io).write("msg please upload data \nxxx");
    }


}
void ClassifyDataCommand::getParameters(){
    
}
void ClassifyDataCommand::setFiles(CSVReader& train, CSVReader& test) {
    m_train = &train;
    m_test = &test;
}
std::string ClassifyDataCommand::getResultString() {
    return (*m_result);
}
void ClassifyDataCommand::setResult() {
    
    (*m_result).clear();
    std::vector<double> vectoc;
    std::vector<std::string> vectocheck;
    int i = 1;
    while (m_test->getNewLine(vectocheck)) {
        vectoc.clear();
        vectoc = convertVectorToDoubles(vectocheck);
        (*m_result).append("msg ");
        (*m_result).append(std::to_string(i));
        (*m_result).append(" ");
        m_Knn.setInputVector(vectoc);
        (*m_result).append(m_Knn.runKNN());
        (*m_result).append("\n");
        i++;
    }
    (*m_result).append("Done.\nxxx");
}

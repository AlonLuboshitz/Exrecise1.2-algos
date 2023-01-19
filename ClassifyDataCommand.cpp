#include "ClassifyDataCommand.h"

ClassifyDataCommand::ClassifyDataCommand() {
    m_distancealgo = distAlgoFactory("AUC");
    m_Knn.setDistanceAlgorithem(m_distancealgo);
    m_result = "";
}
void ClassifyDataCommand::setParameters(std::string parameters) {


}
void ClassifyDataCommand::execute(){
m_Knn.setCSVFile(m_train);
setResult();
}
void ClassifyDataCommand::getParameters(){
    
}
void ClassifyDataCommand::setFiles(CSVReader& train, CSVReader& test) {
    m_train = &train;
    m_test = &test;
}
std::string ClassifyDataCommand::getResultString() {
    return m_result;
}
void ClassifyDataCommand::setResult() {
    m_Knn.setK(5);
    m_result.clear();
    std::vector<double> vectoc;
    std::vector<std::string> vectocheck;
    int i = 1;
    while (m_test->getNewLine(vectocheck)) {
        vectoc.clear();
        vectoc = convertVectorToDoubles(vectocheck);
        m_result.append(std::to_string(i));
        m_result.append(" ");
        m_Knn.setInputVector(vectoc);
        m_result.append(m_Knn.runKNN());
        m_result.append("\n");
        i++;
    }
    m_result.append("Done.\n");
}

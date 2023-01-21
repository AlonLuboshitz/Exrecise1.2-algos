#ifndef CLASSIFYDATACOMMAND_H
#define CLASSIFYDATACOMMAND_H

#include "Command.h"
#include "KNN.h"
class ClassifyDataCommand: public Command{
    private:
    bool m_validResult;
    KNN m_Knn;
    distanceAlgorithems* m_distancealgo;
    CSVReader* m_train;
    CSVReader* m_test;
    std::string* m_result;
    int* m_k;
    void setParameters(int k, std::string algo);
    void setKNN(); 
    public:
    void setResult();
    void setFiles(CSVReader& train, CSVReader& test);
    std::string getResultString();
    ClassifyDataCommand(CSVReader& train, CSVReader& test,
    distanceAlgorithems*& dis,std::string& result, int& k,defualtIO& io);
    ~ClassifyDataCommand() = default;
    void execute();
    void getParameters();
};

#endif
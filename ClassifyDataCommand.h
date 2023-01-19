#ifndef CLASSIFYDATACOMMAND_H
#define CLASSIFYDATACOMMAND_H

#include "Command.h"
#include "KNN.h"
class ClassifyDataCommand: public Command{
    private:
    KNN m_Knn;
    CSVReader* m_train;
    CSVReader* m_test;
    std::string m_result;
    
    public:
    void setResult();
    void setFiles(CSVReader& train, CSVReader& test);
    std::string getResultString();
    ClassifyDataCommand();
    ~ClassifyDataCommand() = default;
    void execute();
    void getParameters();
};

#endif
#ifndef CLASSIFYDATACOMMAND_H
#define CLASSIFYDATACOMMAND_H

#include "Command.h"
#include "KNN.h"
#include "UploadDataCommand.h"
#include "SettingCommand.h"
class ClassifyDataCommand: public Command{
    private:
    bool m_upcommand;
    bool m_setcommand;
    KNN* m_Knn;
    distanceAlgorithems* m_distancealgo;
    CSVReader* m_train;
    CSVReader* m_test;
    UploadDataCommand* m_upload_command;
    SettingCommand* m_setting_command;
    int m_k;
    void setParameters(int k, std::string algo);
    void setKNN(); 
    void setFiles(CSVReader& train, CSVReader& test);
    void setParams();
    public:
    void setResult();
    ClassifyDataCommand(UploadDataCommand* up_command,SettingCommand* setcommand,defualtIO& io);
    ~ClassifyDataCommand();
    void execute();
    using Command::valid;
    using Command::getMsg;
};

#endif
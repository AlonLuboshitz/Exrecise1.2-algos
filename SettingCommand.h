#ifndef SETTINGCOMMAND_H
#define SETTINGCOMMAND_H

#include "Command.h"
#include "DistanceAlgorithemsHeader.h"
class SettingCommand: public Command{
    private:
    int* m_k;
    distanceAlgorithems* m_algo;
    std::string m_msg ,m_disAlgo,m_error_msg;
    void setMsg();
    public:
    bool setParameters(std::string parameteres);
    std::string getMsg();
    SettingCommand(distanceAlgorithems*& algo,int& k, defualtIO& io);
    ~SettingCommand() = default;
    void execute();
    void getParameters();
};

#endif
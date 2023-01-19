#ifndef SETTINGCOMMAND_H
#define SETTINGCOMMAND_H

#include "Command.h"
#include "DistanceAlgorithemsHeader.h"
class SettingCommand: public Command{
    private:
    int m_k;
    std::string m_msg ,m_disAlgo,m_error_msg;
    
    public:
    bool setParameters(std::string parameteres);
    std::string getMsg();
    SettingCommand();
    ~SettingCommand() = default;
    void execute();
    void getParameters();
};

#endif
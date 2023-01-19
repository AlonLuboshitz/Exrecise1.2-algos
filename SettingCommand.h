#ifndef SETTINGCOMMAND_H
#define SETTINGCOMMAND_H

#include "Command.h"
#include "DistanceAlgorithemsHeader.h"
class SettingCommand: public Command{
    private:
    int m_k;
    std::string m_msg;
    distanceAlgorithems* m_disAlgo;
    public:
    SettingCommand();
    ~SettingCommand() = default;
    void execute();
    void getParameters();
};

#endif
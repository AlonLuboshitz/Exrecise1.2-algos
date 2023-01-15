#ifndef SETTINGCOMMAND_H
#define SETTINGCOMMAND_H

#include "Command.h"

class SettingCommand: public Command{
    private:

    public:
    SettingCommand() = default;
    ~SettingCommand() = default;
    void execute();
    void getParameters();
};

#endif
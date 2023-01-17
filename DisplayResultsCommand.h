#ifndef DISPLATRESULTSCOMMAND_H
#define DISPLATRESULTSCOMMAND_H

#include "Command.h"

class DisplayResultsCommand: public Command{
    private:

    public:
    DisplayResultsCommand() = default;
    ~DisplayResultsCommand() = default;
    void execute();
    void getParameters();
};

#endif
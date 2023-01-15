#ifndef CLASSIFYDATA_H
#define CLASSIFYDATA_H

#include "Command.h"

class ClassifyDataCommand: public Command{
    private:

    public:
    ClassifyDataCommand() = default;
    ~ClassifyDataCommand() = default;
    void execute();
    void getParameters();
};

#endif
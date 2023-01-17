#ifndef UPLOADDATACOMMAND_H
#define UPLOADDATACOMMAND_H

#include "Command.h"

class UploadDataCommand: public Command{
    private:

    public:
    UploadDataCommand() = default;
    ~UploadDataCommand() = default;
    void execute();
    void getParameters();
};

#endif
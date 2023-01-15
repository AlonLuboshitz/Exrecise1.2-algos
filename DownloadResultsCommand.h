#ifndef DOWNLOADRESULTSCOMMAND_H
#define DOWNLOADRESULTSCOMMAND_H

#include "Command.h"

class DownloadResultsCommand: public Command{
    private:

    public:
    DownloadResultsCommand() = default;
    ~DownloadResultsCommand() = default;
    void execute();
    void getParameters();
};

#endif
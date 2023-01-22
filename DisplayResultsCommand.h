#ifndef DISPLATRESULTSCOMMAND_H
#define DISPLATRESULTSCOMMAND_H

#include "Command.h"
#include "ClassifyDataCommand.h"
#include "UploadDataCommand.h"

class DisplayResultsCommand: public Command{
    private:
    UploadDataCommand* m_upload_command;
    ClassifyDataCommand* m_classify;
     using Command::valid;
    using Command::getMsg;
    public:
    DisplayResultsCommand(UploadDataCommand& uploadCommand,ClassifyDataCommand& classify,defualtIO& io);
    ~DisplayResultsCommand() = default;
    void execute();
   

};

#endif
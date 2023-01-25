#ifndef DOWNLOADRESULTSCOMMAND_H
#define DOWNLOADRESULTSCOMMAND_H

#include "Command.h"
#include "ClassifyDataCommand.h"
#include "UploadDataCommand.h"

class DownloadResultsCommand: public Command{
    private:
    UploadDataCommand* m_upload_command;
    ClassifyDataCommand* m_classify;
     using Command::valid;
    using Command::getMsg;
    
    public:
    DownloadResultsCommand(UploadDataCommand* uploadCommand,ClassifyDataCommand* classify,defualtIO& io);
    ~DownloadResultsCommand() = default;
    void execute();
};

#endif
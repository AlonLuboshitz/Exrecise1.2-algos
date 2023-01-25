#include "DownloadResultsCommand.h"

DownloadResultsCommand::DownloadResultsCommand(UploadDataCommand* uploadCommand,ClassifyDataCommand* classify,defualtIO& io) {
     m_classify = classify;
    m_upload_command = uploadCommand;
    m_discription = "download results";
    m_io = &io;
}


void DownloadResultsCommand::execute(){
  m_msg.clear();
       if (m_upload_command->valid()) {
        if (m_classify->valid()) {
            std::string toadd = m_classify->getMsg();
            m_msg.append("outputfile ");
            m_msg.append(toadd);
            m_valid = true;
        }
        else {
            m_msg = "msg please classify the dataxxx\n";
        }
    }
    else {//no data uplaoded.
        m_msg = "msg please upload dataxxx\n";
}
m_io->write(m_msg);
}

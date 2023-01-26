#include "DownloadResultsCommand.h"

DownloadResultsCommand::DownloadResultsCommand(UploadDataCommand* uploadCommand,ClassifyDataCommand* classify,defualtIO& io) {
     m_classify = classify;
    m_upload_command = uploadCommand;
    m_discription = "download results";
    m_io = &io;
}


void DownloadResultsCommand::execute(){
  m_msg.clear();
 // m_msg.append("message__ ");
       if (m_upload_command->valid()) {
        if (m_classify->valid()) {
            std::string toadd = m_classify->getMsg();
            //m_msg.append("outputFile ");
            m_io->write("outputFile");
            m_io->write(toadd);
            m_valid = true;
        }
        else {
            m_msg = "message__ please classify the data";
        }
    }
    else {//no data uplaoded.
        m_msg = "message__ please upload data";
}
m_io->write(m_msg);
}

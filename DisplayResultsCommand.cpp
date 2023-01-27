#include "DisplayResultsCommand.h"


DisplayResultsCommand::DisplayResultsCommand(UploadDataCommand* uploadCommand,ClassifyDataCommand* classify,defualtIO& io) {
    m_valid = false;
    m_io = &io;
    m_classify = classify;
    m_upload_command = uploadCommand;
    //catch and realse;
    m_discription = "display results";
}
void DisplayResultsCommand::execute(){
    m_msg.clear();
    m_msg.append("message__ ");
    if (m_upload_command->valid()) {
        if (m_classify->valid()&&(!m_upload_command->ifNewFile())) {
            std::string toadd = m_classify->getMsg();
           // m_msg.append("msg ");
            m_msg.append(toadd);
            m_msg.append("Done.");
            m_valid = true;
        }
        else {
            m_valid= false;
            m_msg = "please classify the data";
        }
    }
    else {//no data uplaoded.
    m_valid = false;
        m_msg = "please upload data";
}
m_io->write(m_msg);
}
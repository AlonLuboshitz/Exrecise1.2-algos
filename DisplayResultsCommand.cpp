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
    if (m_upload_command->valid()) {
        if (m_classify->valid()) {
            std::string toadd = m_classify->getMsg();
            m_msg.append("msg ");
            m_msg.append(toadd);
            m_msg.append("Done.\nxxx");
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
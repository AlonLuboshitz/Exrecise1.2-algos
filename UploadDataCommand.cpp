#include "UploadDataCommand.h"
#include <cstring>

UploadDataCommand::UploadDataCommand(CSVReader& train, CSVReader& test, defualtIO& io) {
    m_discription = "upload an unclassified csv data file";
    m_train = &train;
    m_test = &test;
    m_io = &io;
    m_valid = false;
    }

void UploadDataCommand:: execute(){
    //get two files
    int i = 1;
    while (i < 3) {
        //train file
        if (i == 1) {
            (*m_io).write("msg Please upload your local train CSV file.xxx\noutputfilexxx\n");
            (*m_train).setNewFileData((*m_io).read(),true);
            (*m_io).write("msg Upload complete.xxx\n");
            i++;
        }
        //test file
        if (i == 2) {
            (*m_io).write("msg Please upload your local test CSV file.xxx\noutputfilexxx\n");
            (*m_test).setNewFileData((*m_io).read(),true);
            (*m_io).write("msg Upload complete.xxx\n");
            i++;
        }
    }
    m_valid = true;
    //go to menu;
}

void validfileData(std::string data) {

}
CSVReader* UploadDataCommand::getTrain() {
return m_train;
}
    CSVReader* UploadDataCommand::getTest() {
return m_test;
    }
#include "UploadDataCommand.h"
#include <cstring>

UploadDataCommand::UploadDataCommand(defualtIO& io) {
    m_discription = "upload an unclassified csv data file";
    m_train = new CSVReader;
    m_test = new CSVReader;
    m_io = &io;
    m_valid = false;
    m_newFile = false;
    }
UploadDataCommand::~UploadDataCommand() {
    delete m_train;
    delete m_test;
}
void UploadDataCommand:: execute(){
    //get two files
    int i = 1;
    while (i < 3) {
        //train file
        if (i == 1) {
             (*m_io).write("inputFile Please upload your local train CSV file");
            //(*m_io).write("Please upload your local train CSV file");
            std::string input = m_io->read();
            if (input == "error") {
                m_valid= false;
                return;
            }
            else {
            (*m_train).setNewFileData(input,true);
            (*m_io).write("message__ Upload complete.");
            i++;
            }
        }
        //test file
        if (i == 2) {
            (*m_io).write("inputFile Please upload your local test CSV file");
            std::string input = m_io->read();
            if (input == "error") {
                m_valid= false;
                return;
            }
            else {
            (*m_test).setNewFileData(input,true);
            (*m_io).write("message__ Upload complete.");
            i++;
            m_newFile = true;
            }
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
bool UploadDataCommand::ifNewFile() {
    return m_newFile;
}
void UploadDataCommand::setNewFile() {
m_newFile = true;
}
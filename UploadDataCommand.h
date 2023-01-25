#ifndef UPLOADDATACOMMAND_H
#define UPLOADDATACOMMAND_H
#include "Command.h"
#include "CSVReader.h"
class UploadDataCommand: public Command{
    private:
    std::string m_trainfileData,m_testfileData;
    CSVReader* m_train;
    CSVReader* m_test;
    void validfileData(std::string data);
    public:
    UploadDataCommand(defualtIO& io);
    ~UploadDataCommand();
    void execute();
    using Command::valid;
    CSVReader* getTrain();
    CSVReader* getTest();

};

#endif
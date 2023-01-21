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
    UploadDataCommand(CSVReader& train, CSVReader& test, defualtIO& io);
    ~UploadDataCommand() = default;
    void execute();
    void getParameters();
};

#endif
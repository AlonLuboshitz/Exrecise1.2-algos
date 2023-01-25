#include "Command.h"
#include "standartIO.h"
#include "CSVReader.h"
#include "UploadDataCommand.h"
#include "distanceAlgorithems.h"
#include "SettingCommand.h"
#include "ClassifyDataCommand.h"
#include "DisplayResultsCommand.h"
#include "DownloadResultsCommand.h"
=======
#include "Test.h"
#include "Cli.h"
int main () {
    std::vector<Command*> commands;
    standartIO io;
    UploadDataCommand* up = new UploadDataCommand(io);
    SettingCommand* set = new SettingCommand(io);
   ClassifyDataCommand* classify = new ClassifyDataCommand(up,set,io);
   DisplayResultsCommand* display = new DisplayResultsCommand(up,classify,io);
     commands.push_back(up);
    commands.push_back(set);
    commands.push_back(classify);
    commands.push_back(display);
    Cli cli(commands,"Welcome to the KNN Classifier Server. Please choose an option: \n");
    std::cout<<cli.getMenu();
    cli.run();
    for (int i = 0; i <= commands.size(); i ++) {
        delete commands[i];
    }
    commands.clear();
}

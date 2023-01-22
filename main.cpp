#include "Command.h"
#include "standartIO.h"
#include "CSVReader.h"
#include "UploadDataCommand.h"
#include "distanceAlgorithems.h"
#include "SettingCommand.h"
#include "ClassifyDataCommand.h"
#include "DisplayResultsCommand.h"
#include "DownloadResultsCommand.h"
int main () {
    CSVReader test,train;
    standartIO io;
    UploadDataCommand up(train,test,io);
    up.execute();
    SettingCommand set(io);
    std::string s="0";
    int i =1;
    ClassifyDataCommand clsi(up,set,io);
    DisplayResultsCommand display(up,clsi,io);
    DownloadResultsCommand down(up,clsi,io);
    while(i<10 ) {

          set.execute();
    clsi.execute();
    display.execute();
    down.execute();
    i++;
    }

}

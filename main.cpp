#include "Command.h"
#include "standartIO.h"
#include "CSVReader.h"
#include "UploadDataCommand.h"
#include "distanceAlgorithems.h"
#include "SettingCommand.h"
#include "ClassifyDataCommand.h"
#include "Manhatan.h"
int main () {
    CSVReader test,train;
    standartIO io;
    UploadDataCommand up(train,test,io);
    up.execute();
    int k = 1;
    distanceAlgorithems* dis = new distanceAlgorithems;
    SettingCommand set(dis,k,io);
    std::string result;
    int i =1;
    ClassifyDataCommand clsi(train,test,dis,result,k,io);
    while(i< 4) {
          set.execute();
    clsi.execute();
    std::cout<<result;
    }

}

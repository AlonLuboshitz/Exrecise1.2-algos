#ifndef STANDARTIO_H
#define STANDARTIO_H
#include <iostream>
#include <sstream>
#include "defualtIO.h"
class standartIO : public defualtIO
{
private:
    /* data */
public:
void write(std::string str);
std::string read();
    standartIO() = default;
    ~standartIO() = default;
};
std::string standartIO::read() {
    std::string word,line,read;
   std::getline(std::cin,line);
   return line;
//    std::stringstream s(line);
//    while(s>>word) {
//     read.append(word);
//     read.append(" \n");
//    }
//     return read;
}
void standartIO::write(std::string data) {
 std::cout<<data;
}

#endif
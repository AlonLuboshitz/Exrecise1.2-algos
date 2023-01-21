#ifndef DEFUALTIO_H
#define DEFUALTIO_H
#include <string>
class defualtIO
{
private:
   
public:
    defualtIO() = default;
    ~defualtIO() = default;
    virtual void write(std::string str) = 0;
    virtual std::string read() = 0;

};

#endif
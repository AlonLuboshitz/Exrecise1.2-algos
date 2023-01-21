#ifndef COMMAND_H
#define COMMAND_H
#include "defualtIO.h"
class  Command
{
private:
    /* data */
protected:
std::string m_discription; 
defualtIO* m_io;
//std::list<Parameter> m_ParameterList; 
//defualtIo;  
public:
    Command() = default;
     ~Command() = default;
   // void sendCurrentParameters();
    virtual void execute() = 0;
    virtual void getParameters() = 0;
};


#endif
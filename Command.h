#ifndef COMMAND_H
#define COMMAND_H
#include "string"

class  Command
{
private:
    /* data */
protected:
std::string m_discription; 
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
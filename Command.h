#ifndef COMMAND_H
#define COMMAND_H
#include "defualtIO.h"
class  Command
{
private:
    /* data */
protected:
bool m_valid;
std::string m_discription; 
std::string m_msg;
defualtIO* m_io;
virtual bool valid();
    virtual std::string getMsg();
//std::list<Parameter> m_ParameterList; 
//defualtIo;  
public:
    Command() = default;
     ~Command() = default;
   // void sendCurrentParameters();
    virtual void execute() = 0;
    std::string getName();
    
   
};


#endif
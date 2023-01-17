#ifndef COMMAND_H
#define COMMAND_H

class  Command
{
private:
    /* data */
public:
     Command() = default;
    ~ Command() = default;

    virtual void execute();
    virtual void getParameters();
};


#endif
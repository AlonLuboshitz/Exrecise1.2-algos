#ifndef CLI_H
#define CLI_H
#include "Command.h"
#include <vector>
class Cli
{
private:
     std::vector<Command*> m_commands;
     std::string m_cli_name;
     int m_commands_size;
     bool validUserinput(std::string command_num);
     void runCommand(int command_num);
public:
    Cli(std::vector<Command*> command,std::string name);
    ~Cli() = default;
    std::string getMenu();
    void run();
};


#endif 
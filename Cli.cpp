#include "Cli.h"
#include "inputValidation.h"
Cli::Cli(std::vector<Command*> command,std::string name,defualtIO& io) {
    m_commands = command;
    m_cli_name = name;
    m_commands_size = command.size();
    m_io = &io;
}
std::string Cli::getMenu() {
    std::string menu = "";
    menu.append(m_cli_name);
    menu.append("\n");
    int i = 1;
    std::vector<Command*>::iterator iter = m_commands.begin();
    while (iter != m_commands.end()) {
        menu.append(std::to_string(i));
        menu.append(". ");
        menu.append((*iter)->getName());
        menu.append("\n");
        i++;
        iter ++;
    }
    menu.append("8. exit");
    return menu;

}
void Cli::run() {
    std::string input = std::to_string(m_commands_size + 9);
    int num = -1;
    //user input isnt 8
    while (input != "8") {
        m_io->write(getMenu());
        input = m_io->read();
        if (input == "8") {
            break;
        }
        if (validUserinput(input,num)) {
            runCommand(num);
        }
        //invalid input
        else {
            m_io->write("message__ invalid input");
        }
    }
    m_io->write("exit");
    return;
}
/*
check for more then one argument
*/
bool Cli::moreThenOneArg(std::string input){
std::stringstream stream(input);
int count = 0;
std::string arg;
while (std::getline(stream,arg,',')) {
    count ++;
    if (count > 1) {
        return false;
    }
}
count =0;
arg.clear();
std::stringstream stream2(input);
while (stream2 >> arg) {
    count ++;
    if(count > 1) {
        return false;
    }
}
return true;
}
/*
checks input from user is in double then int, then if two numbers equal.
if not then number is double no valid.
check if its the command range.
*/
bool Cli::validUserinput(std::string command_num,int& num) {
    //checks for num of args.
    if (!moreThenOneArg(command_num)) {
        return false;
    }
    double idouble;
    try {
idouble = std::stod(command_num);
    }
    catch(std::invalid_argument const& ex)
        {
             return false;
        }
        catch(std::out_of_range const& ex)
        {
             return false;
        }
    int i;
     try
        {
            i = std::stoi(command_num);
        }
        catch(std::invalid_argument const& ex)
        {
             return false;
        }
        catch(std::out_of_range const& ex)
        {
             return false;
        }
        if ( (double)i != idouble) {
            return false;
        }
        if (i<=0 || i > m_commands_size){
            return false;
        }
        num = i;
        return true;
}
/* runs one command form vector.
the int is from 1 - vector size (amount of commands)
vectors start from 0 so minus 1.
*/
void Cli::runCommand(int num_command) {
    m_commands[num_command - 1]->execute();
}
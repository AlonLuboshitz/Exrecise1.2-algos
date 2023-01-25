#include "Cli.h"
#include "inputValidation.h"
Cli::Cli(std::vector<Command*> command,std::string name) {
    m_commands = command;
    m_cli_name = name;
    m_commands_size = command.size();
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
    return menu;

}
void Cli::run() {
    for (int i = 1; i <= m_commands_size; i++) {
        runCommand(i);
    }
}

/*
checks input from user is in command range.
*/
bool Cli::validUserinput(std::string command_num) {
    //isKaninteger check if int and bigger then 0.
    if (isKAnInteger(command_num)) {
        int number_of_command = std::stoi(command_num);
        //make sure number is commands range.
        if (number_of_command <= m_commands_size) {
            return true;
        }
        return false;
    }
    return false;
}
/* runs one command form vector.
the int is from 1 - vector size (amount of commands)
vectors start from 0 so minus 1.
*/
void Cli::runCommand(int num_command) {
    m_commands[num_command - 1]->execute();
}

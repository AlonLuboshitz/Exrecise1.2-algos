#include "Command.h"
// void Command::sendCurrentParameters() {
//     std::string toSend = "";
    /*send current parameters to io
    append parameters to string.
std::list<Parameter>::iterator it = m_ParameterList.begin();
for (it; it != m_ParameterList.end(); it ++) {
    toSend.append;
}
io.write(tosend)
*/
//}
// Command::Command() {}
// Command::~Command(){}
// void Command::execute(){}
// void Command::getParameters(){}
bool Command::valid() {
    return m_valid;
}
std::string Command::getMsg() {
    return m_msg;
}
std::string Command::getName() {
    return m_discription;
}
#include "SettingCommand.h"
SettingCommand::SettingCommand() {
    m_k = 5;
    m_disAlgo = new Euclidean();
    m_discription = "algorithems settings";
    m_msg = "The current KNN Parameters are: ";
    //m_ParameterList = {new K,new distanceAlgo};
}
void SettingCommand::execute(){
    //sendCurrentParameters();
    getParameters();
}
void SettingCommand::getParameters(){
std::string input = ""; //io.read();

}


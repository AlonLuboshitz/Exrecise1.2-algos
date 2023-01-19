#include "SettingCommand.h"
#include "inputValidation.h"
SettingCommand::SettingCommand() {
    m_error_msg ="";
    m_k = 5;
    m_disAlgo = "AUC";
    m_discription = "algorithems settings";
    m_msg = "The current KNN Parameters are: ";
    //m_ParameterList = {new K,new distanceAlgo};
}
std::string SettingCommand::getMsg() {
    return m_error_msg;
}

void SettingCommand::execute(){
    //sendCurrentParameters();
    std::string fromio;
    //if parameters arnt curret return to k=5,AUC
    if (!setParameters(fromio)) {
        m_k = 5;
        m_disAlgo = "AUC";
        //send m_error_msg
    }
    getParameters();
}
void SettingCommand::getParameters(){
std::string input = ""; //io.read();
}
bool SettingCommand::setParameters(std::string parameters) {
    //what if more then two arguments?
    m_error_msg.clear();
    bool valid;
    int count = 1;
std::string word;
 std::stringstream stream(parameters);

 while (count < 3) {
    //first arguments
    std::getline(stream,word, ' ');
    if (count == 1) { 
        if (isKAnInteger(word)){
            m_k = std::stod(word);
            count ++; 
            valid = true;
    }
        else { m_error_msg.append("invalid value for K ");
        count ++;
        valid = false;
        }
     }
     //count >1 ; ==2
     else if (count == 2) {
        if (distAlgoFactory(word) == NULL) {
            valid = false;
            count ++;
            m_error_msg.append("invalid value for metric ");
            break;
        }
        else { count ++;
        if (!valid) { break;}
        valid = true;
        m_disAlgo = word;}

     }
     //more then two arguments
     else {
        
        m_error_msg.clear();
        m_error_msg.append("more then two arguments! ");
        valid = false;
        break;
     }
    

 }
 if (!valid) {
 m_error_msg.append("\n");

 }
 return valid;
}

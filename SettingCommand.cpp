#include "SettingCommand.h"
#include "inputValidation.h"
SettingCommand::SettingCommand(distanceAlgorithems*& algo,int& k, defualtIO& io) {
    m_error_msg ="";
    m_k = &k;
    (*m_k) = 5;
    m_disAlgo = "AUC";
    m_algo = algo;
    m_discription = "algorithems settings";
    m_io = &io;
    
    //m_ParameterList = {new K,new distanceAlgo};
}
std::string SettingCommand::getMsg() {
    return m_error_msg;
}
void SettingCommand::setMsg() {
    m_msg.clear();
    m_msg.append("msg The current KNN Parameters are: ");
    m_msg.append("K = ");
    m_msg.append(std::to_string((*m_k)));
    m_msg.append(", distance metric = ");
    m_msg.append(m_disAlgo);
    m_msg.append("xxx\n");
}
void SettingCommand::execute(){
    //set parameters and send.
    setMsg();
    (*m_io).write(m_msg);
    std::string fromio = (*m_io).read();
    //if parameters arnt curret return to k=5,AUC
    //delete old pointer and set new
    if (!setParameters(fromio)) {
        (*m_k) = 5;
        m_disAlgo = "AUC";
        (*m_io).write(m_error_msg);
       //distanceAlgorithems* temp = distAlgoFactory("AUC");
        delete (m_algo);
        (m_algo) = distAlgoFactory("AUC");
    }
    //parameters ok go to menu
}
void SettingCommand::getParameters(){
std::string input = ""; //io.read();
}
bool SettingCommand::setParameters(std::string parameters) {
    //what if more then two arguments?
    m_error_msg.clear();
    if (parameters == "") {
        return true;
    }
    m_error_msg.append("msg");
    bool valid;
    int count = 1;
std::string word;
 std::stringstream stream(parameters);

 while (count < 3) {
    //first arguments
    std::getline(stream,word, ' ');
    if (count == 1) { 
        if (isKAnInteger(word)){
            (*m_k) = std::stod(word);
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
        //sets tmp pointer to check the validation of algofactory.
        //if null doesnt need to be ariased.
        distanceAlgorithems* temp = distAlgoFactory(word);
        if (temp == NULL) {
            valid = false;
            count ++;
            m_error_msg.append("invalid value for metric ");
            delete temp;
            break;
        }
        else { count ++;
        if (!valid) { break;}
        valid = true;
        m_disAlgo = word;
        delete temp;
        //not null erase old data
        delete (m_algo);
        (m_algo) = distAlgoFactory(word);}

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
 m_error_msg.append("\nxxx");

 }
 return valid;
}

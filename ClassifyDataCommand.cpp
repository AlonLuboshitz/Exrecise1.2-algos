#include "ClassifyDataCommand.h"

ClassifyDataCommand::ClassifyDataCommand(UploadDataCommand& command,SettingCommand& setcommand,defualtIO& io) {
     m_train = NULL;
    m_test = NULL;
    m_valid = false;
    m_distancealgo = new distanceAlgorithems;
    m_io = &io;
    m_upload_command = &command;
    m_setting_command = &setcommand;
}
void ClassifyDataCommand::setParams() {
    m_k = m_setting_command->getK();
    delete m_distancealgo;
    m_distancealgo = distAlgoFactory(m_setting_command->getAlgo());
    m_train = m_upload_command->getTrain();
    m_test = m_upload_command->getTest();

}
void ClassifyDataCommand::setKNN(){
m_Knn.setCSVFile(m_train);
m_Knn.setK(m_k);
m_Knn.setDistanceAlgorithem((m_distancealgo));
}
void ClassifyDataCommand::execute(){
    m_msg.clear();
    if ((*m_upload_command).valid()) {
        setParams();
        setKNN();
        setResult();
        (*m_io).write("msg classifying data complete \nxxx");
        m_valid = true;
    }
    else {
        m_msg = "msg please upload data \nxxx";
        (*m_io).write(m_msg);
        m_valid = false;
    }


}

void ClassifyDataCommand::setResult() {
    
    m_msg.clear();
    std::vector<double> vectoc;
    std::vector<std::string> vectocheck;
    int i = 1;
    while (m_test->getNewLine(vectocheck)) {
        vectoc.clear();
        vectoc = convertVectorToDoubles(vectocheck);
        m_msg.append(std::to_string(i));
        m_msg.append(" ");
        m_Knn.setInputVector(vectoc);
        m_msg.append(m_Knn.runKNN());
        m_msg.append("\n");
        i++;
    }
    
}

// void ClassifyDataCommand::setParameters(int k, std::string algo) {
//     if (k > 0) {
//         m_Knn.setK(k);
//     }
//     distanceAlgorithems* temp = distAlgoFactory(algo);
//     if (temp != NULL) {
//         delete (m_distancealgo);
//         (m_distancealgo) = temp;
//     } 
// }

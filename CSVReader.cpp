#include "CSVReader.h"
CSVReader::CSVReader(std::string filename) {
    while (!validateCSVfile(filename)) {
        std::cin>>filename;
    }
    m_fileName = filename;
    readFromFile();
}
bool CSVReader::validateCSVfile(std::string filename) {
    std::string csv;
    csv.assign(filename.end()-4,filename.end());
    if (csv != ".csv") {
        std::cout<<"not a csv file please enter a diffrenet file"<<std::endl;
        return false;
    }
    else {
        return true;
    }
}
void CSVReader::setNewFile(std::string filename) {
    if (validateCSVfile(filename)) {
        m_fileName = filename;
    }
}
void CSVReader::setIterator() {
    m_vectorLine_iterator = m_lineVector.begin();
}
void CSVReader::readFromFile() {
    //resets the vector of the class to hold the lines from the file.
    m_lineVector.clear();
    //init strings for line from file, words between commas in lines.
    std::string line,word;
    std::vector<std::string> vectorFromLine;
    //init file streamer with csv file.
    std::fstream csvfile(m_fileName, std::ios::in);
    //check file has been associated with the fstream
    if (csvfile.is_open()) {
        //as long is it possible assign the line from the file into line string.
        while(std::getline(csvfile,line)) {
        //clear the vector to accpet the line details.
         vectorFromLine.clear();
        //init stringstream to seprate words from commas.
        std::stringstream wordStreamer(line);
        while (std::getline(wordStreamer,word,',')){            
            vectorFromLine.push_back(word);
        }
        //puts line as vector into vector of lines.
        m_lineVector.push_back(vectorFromLine);
        }
    }
    //sets the m_iterator
    setIterator();
    csvfile.close();
}
bool CSVReader::getNewLine(std::vector<std::string>& lineToGet) {
  std::vector<std::vector<std::string>>::const_iterator itToEnd = m_lineVector.end();
  if (m_vectorLine_iterator == itToEnd) {
    setIterator();
     return false;
  }
  else {
    //clear reff vec
  lineToGet.clear();
    //copies m_vector[i] place into line to get.
  lineToGet = *m_vectorLine_iterator;
  m_vectorLine_iterator++;  
  return true;
  }
}
//main example.

// int main() {
//     std::string filename = "iris_classified.csv";
//     CSVReader csv(filename);
//     std::vector<std::string> vec;
//     while (csv.getNewLine(vec)) {
//         //
//     }
    
// }
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
// this class is a file streamer class to read csv files.
// it has filename memeber or a path, a vector of lines from file stored as string vectors.
// private function to validate the file enter is csv type.
// and private function to init the vector of lines.
// it can set a new file and has a function to read line by line the file and convert
// the line readed into a vector.
class CSVReader {
    private:
    std::string m_fileName;
    std::vector<std::vector<std::string>> m_lineVector;
    std::vector<std::vector<std::string>>::iterator m_vectorLine_iterator;
    //reset iterator to the beginning of the m_lineVector
    void setIterator();
    //puts all line from file into m_lineVector
    void readFromFile();
    //fuction check if last four letters in string are ".csv" make sure the file is csv type.
    bool validateCSVfile(std::string filename);
    public: 
    //ctor with filename\ path
    CSVReader(std::string filename);
    //sets a new filename into the filename memeber of csv
    void setNewFile(std::string filename);
    //reads a new vector from linesVector into vector given by reff. 
    //returns true if there are more line(vectors)
    //returns false if there are no more lines to read from.
    bool getNewLine(std::vector<std::string>& lineToGet);
};
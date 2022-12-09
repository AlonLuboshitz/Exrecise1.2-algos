#include "distanceAlgorithems.h"
#include "inputValidation.h"
#include "Euclidean.h"
#include "Manhatan.h"
#include "Canberra.h"
#include "check.h"
#include "Minkovsky.h"

#include <map>
#include <iostream>


int main() {
	std::vector<std::string> vec = {"hi", "gili", "hi", "whats", "gili"};
	std::vector<std::string>::const_iterator indexIterator;
	indexIterator = vec.begin() + 2;
    vec.erase(indexIterator);
	std::map<std::string, int> map;
	map.insert(std::pair<std::string, int>(vec.at(0), 1));
    //runs k-1 loops

    for (int i = 1; i < 4; i++){
        std::string tempLabel = vec.at(i);
        //if the map finds a key the same as the neighbor's label-
         //it increases its value by one (there is one more vector with this label)
       if (map.find(tempLabel) != map.end()){
            map.at(tempLabel)++;
       }
       // else- inserts the new label with the count of 1
       else {
        map.insert(std::pair<std::string, int>(tempLabel, 1));
       }
    }
	std::string str = map.begin()->first;
	map.clear();
	std::string str2 = str;


	return 0;
}
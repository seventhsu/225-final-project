#pragma once

//C Imports
#include <climits>
#include <cstdlib>

//C++ Imports
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Graph {
public:
    Graph(const string& file ame);
private:
    vector<vector<int16_t>> adjMatrix;
    unordered_map<string, int> researcherToIndex;
    //set<string> vertexSet; i thought of using a set as a class variable, but I we will not really need it besides in the constructor
    // borrowed this split string from mp_schedules
    vector<string> SplitString(const string& inputString, const string& separator)
        vector<string> fields;
        size_t pos = 0;
        while ((pos = str.find(separator)) != string::npos) {
            fields.push_back(str.substr(0,pos));
            str.erase(0, pos + 1);  
        }
        fields.push_back(str);
        return fields;
    }
}
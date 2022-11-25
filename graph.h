// we took this from the lab_ml directory
#pragma once

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::string;
using std::to_string;
using std::vector;
using std::pair;
using std::make_pair;
using std::unordered_map;
using namespace std;

class Graph {

    vector<vector<int16_t>> adjMatrix;
    map<string, int> researcherToIndex;
    //set<string> vertexSet; i thought of using a set as a class variable, but I we will not really need it besides in the constructor
    // borrowed this split string from mp_schedules
    int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
        std::string str = str1;
        std::string::size_type pos;
        while((pos=str.find(sep)) != std::string::npos) {
            fields.push_back(str.substr(0,pos));
            str.erase(0,pos+1);  
        }
        fields.push_back(str);
        return fields.size();
    }

    public:

    Graph(string & filename);

};

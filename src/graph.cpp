#include "graph.h"

Graph::Graph(const string& filename) {
    unordered_set<string> vertexSet; //Stores a set of vertices
    ifstream wf1(filename);
    string currentLine;
    // for this first iteration through the file, we want to just find the number of vertices so that we can create our adj matrix
    // this is the same format used in lab_dict
    if (wordsFile.is_open()) {
        while (getline(wordsFile, currentLine)) {
            vector<string> splittedWords = SplitString(line1, "\t");
            if (splittedWords.size() != 2) {
                continue;
            }
            // i'll use a set to store the vertices just for ease as this insert is an O(1) operation
            vertexSet.insert(vertexSet.begin(), splittedWords.begin(), splittedWords.begin() + 1);
        }
    }

    // now we create our vector, it will have a default of 0 (all vertices are unconnected at the start)
    vector<vector<int16_t>> matrix(vertexSet.size(), vector<int16_t>(vertexSet.size(), 0)); //
    adjMatrix = matrix;
    wf1.close();
    //now, we will populate our map using the set (we map each vertex to a unique index)
    int index = 0;
    for (string vertex : vertexSet) {
        researcherToIndex[vertex] = index, index++;
    }
    // for the second iteration through the file, we will now add in the edges
    ifstream wf2(filename);
    string line2;
    if (wf2.is_open()) {
        while (getline(wf2, line2)) {
            vector<string> splittedWords;
            SplitString(line2, '\t', splittedWords);
            if (splittedWords.size() != 2) {
                continue;
            }
            int firstIndex = researcherToIndex[splittedWords[0]];
            int secondIndex = researcherToIndex[splittedWords[1]];
            adjMatrix[firstIndex][secondIndex] += 1, adjMatrix[secondIndex][firstIndex] += 1; // increment by 1 to take weights into account
        }
    }
    wf2.close();
}

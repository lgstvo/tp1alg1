#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "headers/graph.hpp"

using namespace std;

int main(){

    int numberOfCD, numberOfPV, temperatureDecay;
    string entry;

    cin >> numberOfCD >> numberOfPV >> temperatureDecay;

    vector <vector<int>> graphTree;

    cin.ignore(INT64_MAX, '\n');
    for(int i = 0; i < numberOfCD+numberOfPV; i++){
        vector <int> connections;

        getline(cin, entry);
        istringstream iss(entry);

        for(string entry; iss >> entry;){
            connections.push_back(stoi(entry));
        }

        graphTree.push_back(connections);
    }

    GraphTree tree(graphTree);
    vector<int> result = tree.dfs();

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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

    GraphTree tree(graphTree, numberOfCD, numberOfPV, temperatureDecay);
    vector<int> result = tree.bfs();
    sort(result.begin(), result.end());

    cout << result.size() << endl;

    if(!result.size()){
        cout << '*' << endl;
        cout << 0 << endl;
    }
    else{
        for(auto it = result.begin(); it != result.end(); it++){
            cout << *it << ' ';
        }
        cout << endl << tree.hasRecurrentPV();
    }

    return 0;
}
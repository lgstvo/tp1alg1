#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

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

    return 0;
}
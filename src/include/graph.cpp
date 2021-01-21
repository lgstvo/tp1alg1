#include "headers/graph.hpp"
#include <stack>
#include <cstdlib>
#include <iostream>

GraphTree::GraphTree(std::vector<std::vector<int>> adjencyList){
    this->adjencyList = adjencyList;
}

std::vector<std::vector<int>> GraphTree::getAdjencyList(){
    return this->adjencyList;
}

int GraphTree::getCD(){
    return this->CD;
}

int GraphTree::getPV(){
    return this->PV;
}

int GraphTree::getTemperatureDecay(){
    return this->temperatureDecay;
}

void GraphTree::setCD(int CD){
    this->CD = CD;
}

void GraphTree::setPV(int PV){
    this->PV = PV;
}

void GraphTree::setTemperatureDecay(int temperatureDecay){
    this->temperatureDecay = temperatureDecay;
}

void GraphTree::setAdjencyList(std::vector<std::vector<int>> adjencyList){
    this->adjencyList = adjencyList;
}

std::vector<int> GraphTree::dfs(std::vector<bool> explored){
    // Valores de indice dos PVs são os indices originais + nCD
    std::vector<int> reachedPV;

    for(int i = 0; i < getCD(); i++){
        std::stack<int> notVisited;
        std::vector<std::vector<int>> adjencyList = getAdjencyList();
        int currentExploration;
        for(auto it = adjencyList[i].begin(); it != adjencyList[i].end(); it++){
            notVisited.push(*it);
        }

        while(!(notVisited.empty())){
            currentExploration = notVisited.top();
            notVisited.pop();

            if(explored[currentExploration -1 + getCD()] == 0){
                explored[currentExploration -1 + getCD()] = 1;
                std::vector<int> edges = adjencyList[currentExploration -1 + getCD()];
                for(auto it = edges.begin(); it != edges.end(); it++){
                    notVisited.push(*it);
                }
            }
        }
    }
    

    return reachedPV;
}

std::vector<int> GraphTree::dfs(){
    int numbersOfNodes = (int) getAdjencyList().size();
    std::vector<bool> explored(numbersOfNodes, 0);
    std::vector<int> reachedPV = dfs(explored);

    return reachedPV;
}
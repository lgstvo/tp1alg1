#include "headers/graph.hpp"

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

std::vector<int> GraphTree::dfs(){
    std::vector<int> reachedPV;
    return reachedPV;
}
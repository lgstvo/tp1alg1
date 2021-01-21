#include "headers/graph.hpp"

GraphTree::GraphTree(std::vector<std::vector<int>> adjencyList){
    this->adjencyList = adjencyList;
}

std::vector<std::vector<int>> GraphTree::getAdjencyList(){
    return this->adjencyList;
}

void GraphTree::setAdjencyList(std::vector<std::vector<int>> adjencyList){
    this->adjencyList = adjencyList;
}

std::vector<int> GraphTree::dfs(int decay){
    std::vector<int> reachedPV;
    return reachedPV;
}
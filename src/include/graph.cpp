#include "../headers/graph.hpp"
#include <cstdlib>
#include <queue>

GraphTree::GraphTree(std::vector<std::vector<int>> adjencyList, int CD, int PV, int temperatureDecay){
    this->adjencyList = adjencyList;
    this->CD = CD;
    this->PV = PV;
    this->temperatureDecay = temperatureDecay;
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
    int deploymentRange = 30/getTemperatureDecay();

    for(int i = 0; i < getCD(); i++){
        std::vector<std::vector<int>> adjencyList = getAdjencyList();
        std::queue<int> primaryQueue;
        std::queue<int> decendentQueue;
        
        for(auto it = adjencyList[i].begin(); it != adjencyList[i].end(); it++){
            primaryQueue.push(*it);
        }

        for(int j = deploymentRange; j > 0; j--){
            while(!(primaryQueue.empty())){
                int element = primaryQueue.front();
                if(element != 0){
                    int elementIndex = element -1 + getCD();
                    primaryQueue.pop();
                    
                    if(!(explored[elementIndex])){
                        reachedPV.push_back(element);
                        explored[elementIndex] = 1;
                        std::vector<int> edges = adjencyList[elementIndex];
                        for(auto it = edges.begin(); it != edges.end(); it++){
                            decendentQueue.push(*it);
                        }
                    }
                }

            }
            // swap queues
            primaryQueue.swap(decendentQueue);
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
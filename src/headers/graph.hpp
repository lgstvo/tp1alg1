#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

class GraphTree{
    private:
        std::vector<std::vector<int>> adjencyList;

    public:
        GraphTree(std::vector<std::vector<int>>);

        std::vector<std::vector<int>> getAdjencyList();
        void setAdjencyList(std::vector<std::vector<int>>);
        std::vector<int> dfs(int);

};

#endif
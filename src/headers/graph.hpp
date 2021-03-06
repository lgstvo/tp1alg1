#ifndef GRAPH
#define GRAPH
#include <cstdlib>
#include <vector>

class GraphTree{
    private:
        std::vector<std::vector<int>> adjencyList;
        int CD;
        int PV;
        int temperatureDecay;

    public:
        GraphTree(std::vector<std::vector<int>>, int, int, int);

        std::vector<std::vector<int>> getAdjencyList();
        int getCD();
        int getPV();
        int getTemperatureDecay();

        void setCD(int);
        void setPV(int);
        void setTemperatureDecay(int);
        void setAdjencyList(std::vector<std::vector<int>>);

        std::vector<int> bfs();
        std::vector<int> bfs(std::vector<bool>);

        bool hasRecurrentPV();

};

#endif
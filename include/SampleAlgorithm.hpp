#pragma once 

#include "Maze.hpp"
#include "PathfindingAlgorithm.hpp"
#include <vector>
#include <string>

class threeNumbers
{
    public:
    int y;
    int x;
    int counter;
    threeNumbers(int y, int x, int counter):y(y),x(x),counter(counter){};
};

class SampleAlgorithm : public PathfindingAlgorithm
{
    public:
    void solve(Maze board);
    void showCorrectPath(std::vector<threeNumbers> & queue,int y,int x,std::vector<std::vector<std::string>> & board,Maze & maze);
};
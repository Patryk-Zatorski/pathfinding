#pragma once 

#include <vector>
#include <string>
#include "Maze.hpp"

class PathfindingAlgorithm
{
    public:
    virtual void solve(Maze maze)=0;
    void view(std::vector<std::vector<std::string>> board,Maze& maze) const;
};
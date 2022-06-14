#pragma once 

#include <vector>
#include "MazeGenerator.hpp"
#include <string>

class DepthFirstGenerator:public MazeGenerator{
    public:
    std::vector<std::vector<std::string>> generate(int height, int width) const;
    void recursiveImplementation(std::vector<std::vector<std::string>> & board, int i, int a, int height, int width) const;
};
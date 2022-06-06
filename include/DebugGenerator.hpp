#pragma once 

#include <vector>
#include "MazeGenerator.hpp"
#include <string>

class DebugGenerator:public MazeGenerator{
    public:
    std::vector<std::vector<std::string>> generate(int height, int width) const;
};
#pragma once 

#include <vector>
#include <string>

class MazeGenerator{
    public:
    void view(const int height,const int width,const std::vector<std::vector<std::string>> & board)const;
    virtual std::vector<std::vector<std::string>> generate(int height, int width) const=0;
};
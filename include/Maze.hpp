#pragma once

#include <vector>
#include <string>
#include "MazeGenerator.hpp"

class Maze {
    private:
    int height;
    int width;
    std::vector<std::vector<std::string>> board;
    public:
    Maze(int height, int width, MazeGenerator &generator);
    int getHeight();
    int getWidth();
    std::vector<std::vector<bool>> getBoard();
};
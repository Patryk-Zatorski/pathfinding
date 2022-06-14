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
    int getHeight() const;
    int getWidth() const;
    std::vector<std::vector<std::string>> getBoard() const;
};
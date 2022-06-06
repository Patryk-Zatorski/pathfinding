#include "Maze.hpp"
#include "MazeGenerator.hpp"
#include <vector>

using namespace std;

Maze::Maze(int height, int width, MazeGenerator& generator): height(height), width(width)
{
    board=generator.generate(height,width);
}
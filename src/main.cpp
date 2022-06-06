#include "Maze.hpp"
#include "MazeGenerator.hpp"
#include "DebugGenerator.hpp"

using namespace std;

int main(){
    
    DebugGenerator debug;
    Maze(10,50,debug);
    return 0;
}
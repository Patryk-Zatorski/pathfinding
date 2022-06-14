#include "Maze.hpp"
#include "MazeGenerator.hpp"
#include "DebugGenerator.hpp"
#include "DepthFirstGenerator.hpp"
#include "PathfindingAlgorithm.hpp"
#include "SampleAlgorithm.hpp"
#include <iostream>
#include <string>
#include <memory>

//using namespace std;

std::unique_ptr<MazeGenerator> chooseMaze(std::string userInput)
{
    if(userInput=="debug") return std::make_unique<DebugGenerator>();
    if(userInput=="depth") return std::make_unique<DepthFirstGenerator>();
    return std::make_unique<DepthFirstGenerator>();
}

std::unique_ptr<PathfindingAlgorithm> chooseAlgorithm(std::string userInput)
{
    if(userInput=="sample") return std::make_unique<SampleAlgorithm>();
    return std::make_unique<SampleAlgorithm>();
}

int main(){
    
    std::string userInput;
    while(userInput!="debug"&&userInput!="depth")
    {
        std::cout<<"Choose maze generation algorithm[debug/depth]: ";
        std::cin>>userInput;
    }
    Maze maze(41,151,*chooseMaze(userInput));
    while(userInput!="sample")
    {
        std::cout<<"Choose maze pathfinding algorithm[sample]: ";
        std::cin>>userInput;
    }
    
    (*chooseAlgorithm(userInput)).solve(maze);
    return 0;
}
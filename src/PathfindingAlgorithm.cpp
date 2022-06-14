#include "Maze.hpp"
#include "PathfindingAlgorithm.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void PathfindingAlgorithm::view(vector<vector<string>> board, Maze& maze)const
{
    int height = maze.getHeight();
    int width = maze.getWidth();

    system("clear");
    for(int i=0;i<height;i++)
    {
        string outputString="";
        for(int a=0;a<width;a++)
        {
            if(board[i][a]=="wall"){outputString+="\033[47m ";}
            else if(board[i][a]=="finish"){outputString+="\033[44m ";}
            else if(board[i][a]=="start"){outputString+="\033[42m ";}
            else if(board[i][a]=="searched"){outputString+="\033[100m ";}
            else if(board[i][a]=="correct"){outputString+="\033[42m ";}
            else{outputString+="\033[0m ";}
        }
        outputString+="\033[0m ";
        cout<<outputString<<endl;
        outputString="";
    }
    usleep(10000);
}
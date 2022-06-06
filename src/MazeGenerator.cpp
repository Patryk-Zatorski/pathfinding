#include "MazeGenerator.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void MazeGenerator::view(const int height,const int width,const std::vector<std::vector<string>> & board)const
{
    system("clear");
    for(int i=0;i<height;i++)
    {
        string outputString="";
        for(int a=0;a<width;a++)
        {
            if(board[i][a]=="wall"){outputString+="\033[47m ";}
            else if(board[i][a]=="finish"){outputString+="\033[44m ";}
            else if(board[i][a]=="start"){outputString+="\033[42m ";}
            else{outputString+="\033[0m ";}
        }
        outputString+="\033[0m ";
        cout<<outputString<<endl;
        outputString="";
    }
    usleep(10000);
}
#include "DebugGenerator.hpp"
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> DebugGenerator::generate(int height, int width) const
{
    //#############
    //#  #     #  #    
    //#  #  #  #  #    
    //#  #  #  #  #    
    //#  #  #  #  #    
    //#           #   
    //#############

    vector<vector<string>> board;
    
    board.resize(height);
    //generating borders
    for(int i=0;i<height;i++)
    {
        board[i].resize(width);
        for(int a=0;a<width;a++)
        {
            if(a==0||a==width-1||i==0||i==height-1){board[i][a]="wall";}else{board[i][a]=="free";}
        }
    }

    //generating vertical lines
    for(int i=1;i<height-1;i++)
    {
        for(int a=1;a<width-1;a++)
        {
            if(a%4==2&&i<height-2){board[i][a]="wall";}
            if(a%4==0&&i>1&&i<height-2){board[i][a]="wall";}
        }
        this->view(height,width,board);
    }

    board[1][1]="start";
    board[height-2][width-2]="finish";
  
  this->view(height,width,board);  
    return board;
}
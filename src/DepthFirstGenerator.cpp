#include "DepthFirstGenerator.hpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


void DepthFirstGenerator::recursiveImplementation(vector<vector<string>> & board, int i, int a, int height, int width) const
{
    //cout<<board[i][a]<<" "<<i<<" "<<a<<endl;
    int numberOfNeighbours;
    do
    {
        board[i][a]="visited";
        vector<int>col;
        vector<int>row;
        col.reserve(4);
        row.reserve(4);
        numberOfNeighbours=0;
        //count unvisited neighbours
        if(a+3<width)
        {
            //cout<<board[i][a+2];
            if(board[i][a+2]!="visited"&&board[i][a+2]!="wall")
            {
                //cout<<"if2";
                row.push_back(i);
                col.push_back(a+2);
                numberOfNeighbours++;
            }
        }
        if(a-3>=0)
        {
            if(board[i][a-2]!="visited"&&board[i][a-2]!="wall")
            {
                row.push_back(i);
                col.push_back(a-2);
                numberOfNeighbours++;
            }
        }
        if(i+3<height)
        {
            if(board[i+2][a]!="visited"&&board[i+2][a]!="wall")
            {
                row.push_back(i+2);
                col.push_back(a);
                numberOfNeighbours++;
            }
        }
        if(i-3>=0)
        {
            if(board[i-2][a]!="visited"&&board[i-2][a]!="wall")
            {

                row.push_back(i-2);
                col.push_back(a);
                numberOfNeighbours++;
            }
        }
        if(numberOfNeighbours>0){
            int chosen=rand()%(col.size());
            //cout<<"chosen"<<chosen<<endl;
            //cout<<col[0]<<col[1]<<col[2];
            board[(i+row[chosen])/2][(a+col[chosen])/2]="visited";
            this->view(height,width,board);
            recursiveImplementation(board,row[chosen],col[chosen],height,width);
            row.erase(row.begin()+chosen);
            col.erase(col.begin()+chosen);
            numberOfNeighbours--;
        }
    }while(numberOfNeighbours>0);

}

vector<vector<string>> DepthFirstGenerator::generate(int height, int width) const
{
    srand(time(0));
    
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

    //generate grid
    for(int i=1;i<height-1;i++)
    {
        for(int a=1;a<width-1;a++)
        {
            if(a%2==0||i%2==0){board[i][a]="wall";}
        }
    }

    this->recursiveImplementation(board,1,1,height,width);

    for(int i=1;i<height-1;i++)
    {
        for(int a=1;a<width-1;a++)
        {
            if(board[i][a]=="visited"){board[i][a]="free";}
        }
    }
    board[1][1]="start";
    board[height-2][width-2]="finish";
    this->view(height,width,board);
    return board;
}
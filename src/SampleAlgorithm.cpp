#include <vector>
#include <string>
#include "Maze.hpp"
#include "SampleAlgorithm.hpp"
#include <iostream>

using namespace std;

void SampleAlgorithm::solve(Maze maze)
{
    vector<vector<string>> board = maze.getBoard();
    int height = maze.getHeight();
    int width = maze.getWidth();

    vector<threeNumbers>queue;

    for(int i=0;i<height;i++)
    {
        for(int a=0;a<width;a++)
        {
            if(board[i][a]=="finish") {queue.push_back(threeNumbers(i,a,0));break;}
        }
    }
    int startX,startY;
    for(int i=0;i<height;i++)
    {
        for(int a=0;a<width;a++)
        {
            if(board[i][a]=="start") {startX=a;startY=i;break;}
        }
    }
    
    bool shouldTheSearchContinue=true;
    int iterator=-1;
    while(shouldTheSearchContinue)
    {
        iterator++;
        if(queue[iterator].x>0)
        {
            if(board[queue[iterator].y][queue[iterator].x-1]=="free"||board[queue[iterator].y][queue[iterator].x-1]=="start")
            {
                queue.push_back(threeNumbers(queue[iterator].y,queue[iterator].x-1,iterator+1));
                board[queue[iterator].y][queue[iterator].x-1]="searched";
            }
        }
        if(queue[iterator].x<width-1)
        {
            if(board[queue[iterator].y][queue[iterator].x+1]=="free"||board[queue[iterator].y][queue[iterator].x+1]=="start")
            {
                queue.push_back(threeNumbers(queue[iterator].y,queue[iterator].x+1,iterator+1));
                board[queue[iterator].y][queue[iterator].x+1]="searched";
            }
        }
        if(queue[iterator].y>0)
        {
            if(board[queue[iterator].y-1][queue[iterator].x]=="free"||board[queue[iterator].y-1][queue[iterator].x]=="start")
            {
                queue.push_back(threeNumbers(queue[iterator].y-1,queue[iterator].x,iterator+1));
                board[queue[iterator].y-1][queue[iterator].x]="searched";
            }
        }
        if(queue[iterator].y<height-1)
        {
            if(board[queue[iterator].y+1][queue[iterator].x]=="free"||board[queue[iterator].y+1][queue[iterator].x]=="start")
            {
                queue.push_back(threeNumbers(queue[iterator].y+1,queue[iterator].x,iterator+1));
                board[queue[iterator].y+1][queue[iterator].x]="searched";
            }
        }

        if(queue.size()>0)
        {
            if(queue[queue.size()-1].x==startX&&queue[queue.size()-1].y==startY)
            {shouldTheSearchContinue=false;}
        }
        if(queue.size()>1)
        {
            if(queue[queue.size()-2].x==startX&&queue[queue.size()-2].y==startY)
            {shouldTheSearchContinue=false;}
        }
        if(queue.size()>2)
        {
            if(queue[queue.size()-3].x==startX&&queue[queue.size()-3].y==startY)
            {shouldTheSearchContinue=false;}
        }
        if(queue.size()>3)
        {
            if(queue[queue.size()-4].x==startX&&queue[queue.size()-4].y==startY)
            {shouldTheSearchContinue=false;}
        }
    board[startY][startX]="start";
    view(board,maze);
    //cout<<queue.size();
    }

    showCorrectPath(queue,startY,startX,board,maze);
}

void SampleAlgorithm::showCorrectPath(std::vector<threeNumbers> & queue,int y,int x,std::vector<std::vector<std::string>> & board,Maze & maze)
{
    vector<threeNumbers> possibleSolution;
    size_t queueLength=queue.size();
    int searchRange=queue.size();

    for(int i=0;i<searchRange;i++)
    if(queue.size()>i)
    {
        if(queue[queue.size()-i-1].x==x+1&&queue[queue.size()-i-1].y==y)
        {
            possibleSolution.push_back(queue[queue.size()-1-i]);
            //queue.erase(queue.begin()+(queueLength-1-i));
        }
        if(queue[queue.size()-i-1].x==x&&queue[queue.size()-i-1].y==y+1)
        {
            possibleSolution.push_back(queue[queue.size()-1-i]);
            //queue.erase(queue.begin()+(queueLength-1-i));
        }
        if(queue[queue.size()-i-1].x==x-1&&queue[queue.size()-i-1].y==y)
        {
            possibleSolution.push_back(queue[queue.size()-1-i]);
            //queue.erase(queue.begin()+(queueLength-1-i));
        }
        if(queue[queue.size()-i-1].x==x&&queue[queue.size()-i-1].y==y-1)
        {
            possibleSolution.push_back(queue[queue.size()-1-i]);
            //queue.erase(queue.begin()+(queueLength-1-i));
        }
        if(i==searchRange&&possibleSolution.size()==0)searchRange+=4;
    }
    /*if(queueLength>1)
    {
        if(queue[queue.size()-2].x==x&&queue[queue.size()-2].y==y)
        {
            possibleSolution.push_back(queue[queue.size()-2]);
            queue.erase(queue.begin()+(queueLength-2));
        }
    }
    if(queueLength>2)
    {
        if(queue[queue.size()-3].x==x&&queue[queue.size()-3].y==y)
        {
            possibleSolution.push_back(queue[queue.size()-3]);
            queue.erase(queue.begin()+(queueLength-3));
        }
    }
    if(queueLength>3)
    {
        if(queue[queue.size()-4].x==y&&queue[queue.size()-4].y==y)
        {
            possibleSolution.push_back(queue[queue.size()-4]);
            queue.erase(queue.begin()+(queueLength-4));
        }
    }*/
    int lowestCounter=999999999;
    threeNumbers lowest(1,1,lowestCounter);

    if(possibleSolution.size()>0)
    {
        if(possibleSolution[possibleSolution.size()-1].counter<lowestCounter)
        {
            lowestCounter=possibleSolution[possibleSolution.size()-1].counter;
            lowest=possibleSolution[possibleSolution.size()-1];
        }
    }
    if(possibleSolution.size()>1)
    {
        if(possibleSolution[possibleSolution.size()-2].counter<lowestCounter)
        {
            lowestCounter=possibleSolution[possibleSolution.size()-2].counter;
            lowest=possibleSolution[possibleSolution.size()-2];
        }
    }
    if(possibleSolution.size()>2)
    {
        if(possibleSolution[possibleSolution.size()-3].counter<lowestCounter)
        {
            lowestCounter=possibleSolution[possibleSolution.size()-3].counter;
            lowest=possibleSolution[possibleSolution.size()-3];
        }
    }
    if(possibleSolution.size()>3)
    {
        if(possibleSolution[possibleSolution.size()-4].counter<lowestCounter)
        {
            lowestCounter=possibleSolution[possibleSolution.size()-4].counter;
            lowest=possibleSolution[possibleSolution.size()-4];
        }
    }
    
    if(board[lowest.y][lowest.x]!="finish")
    {
        board[lowest.y][lowest.x]="correct";
        view(board,maze);
        //cout<<queue.size();
        showCorrectPath(queue,lowest.y,lowest.x,board,maze);
    }
    
}
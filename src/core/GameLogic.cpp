#include "GameLogic.h"
#include "Global.h"


#define COLUMN 7
#define ROW 6


void GameLogic::reset_board(BoardPiece board[6][7])
{
    
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            board[i][j] = 0;
        }
    }

}

bool GameLogic::CheckIfWin(int board[7][6]) 
{

    int keeptrack;

    for(int i = ROW - 1; i > 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if(board[i][j] == 1)
            {
                keeptrack++;
            }
            if (board[i][j] == 2)
            {
                keeptrack = 0;
            }
            if (keeptrack == 4)
            {
                return true;
            }
        }
    }



    for(int i = ROW; i > 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if(board[i][j] == 2)
            {
                keeptrack++;
            }
            if (board[i][j] == 1)
            {
                keeptrack = 0;
            }
            if (keeptrack == 4)
            {
                return true;
            }
        }
    }

    keeptrack == 0;
    int add = 0;
    int another = 0;


//Checks wins for red on diagnal from right to left
for (int k = 0; k < 4; k ++)
{
    for (int i = ROW; i >= 4; i--)
    { 

        if (i = ROW)
            {
                another++;
            }
            else
            {
                another = 0;
            }

        for (int j = k; j < COLUMN - another; j++)
        {
           
            if(board[i-add][j] == 1)
            {
                keeptrack++;
            }
            else
            {
                keeptrack = 0;
            }
            if (keeptrack == 4)
            {
                return true;
            }
            if (i - add > 0)
            {
                add++;
            }
            else
            {
                break;
            }
        }
    }
}

//Checks wins for red on diagnal from left to right
for (int k = 0; k < 4; k ++)
{
    for (int i = ROW; i >= 4; i--)
    { 
        
        if (i = ROW)
            {
                another++;
            }
            else
            {
                another = 0;
            }

        for (int j = COLUMN; j > another; j--)
        {
           
            if(board[i-add][j] == 1)
            {
                keeptrack++;
            }
            else
            {
                keeptrack = 0;
            }
            if (keeptrack == 4)
            {
                return true;
            }
            if (i - add > 0)
            {
                add++;
            }
            else
            {
                break;
            }
        }
    }
}

    return false;
}


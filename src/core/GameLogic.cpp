#include "GameLogic.h"
#include "Global.h"


#define COLUMN 7
#define ROW 6


void GameLogic::reset_board(int board[7][6])
{
    
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            board[j][i] = 0;
        }
    }

}

bool GameLogic::CheckIfWin(int board[7][6]) 
{

    int keeptrack;
    // CHECKS IF RED WINS ON A ROW
    for(int i = ROW; i > 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if(board[j][i] == 1)
            {
                keeptrack++;
            }
            if (board[j][i] == 2 || board[j][i] == 0)
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
    // CHECKS IF YELLOW WINS ON A ROW
    for(int i = ROW; i > 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if(board[j][i] == 2)
            {
                keeptrack++;
            }
            if (board[j][i] == 1 || board[j][i] == 0)
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

    // CHECK IS RED WINS ON A COLUMN
    for(int i = 0; i > COLUMN; i++)
    {
        for (int j = ROW; j > 0; j--)
        {
            if(board[j][i] == 2)
            {
                keeptrack++;
            }
            if (board[j][i] == 1 || board[j][i] == 0)
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

    // CHECK IS YELLOW WINS ON A COLUMN
  for(int i = 0; i > COLUMN; i++)
    {
        for (int j = ROW; j > 0; j--)
        {
            if(board[j][i] == 1)
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
        }
    }

    keeptrack == 0;
    int add = 0;
    int another = 0;

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

    return false;
}


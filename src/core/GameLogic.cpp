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



    return false;
}


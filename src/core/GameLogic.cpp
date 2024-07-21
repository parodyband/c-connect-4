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
            board[i][j].SetOwner(0);
        }
    }

}

bool GameLogic::CheckIfWin(BoardPiece board[6][7])
{

    int keeptrackRed = 0;
    int keeptrackBlue = 0;

    // CHECKS WINS ON A ROW
    for(int i = ROW; i > 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if(board[i][j].GetOwner() == 1)
            {
                keeptrackRed++;
            }
            else 
            {
                keeptrackRed = 0;
            }
            if(board[i][j].GetOwner() == 2)
            {
                keeptrackBlue++;
            }
            else
            {
                keeptrackBlue = 0;
            }
            if (keeptrackRed == 4)
            {
                return true;
            }
            if (keeptrackBlue == 4)
            {
                return true;
            }
        }
    }

    keeptrackBlue = 0;
    keeptrackRed = 0;

    //CHECKS WINS ON A COLUMN
    for(int i = 0; i < COLUMN; i++)
    {
        for (int j = ROW-1; j >= 0; j--)
        {
            if(board[j][i].GetOwner() == 1)
            {
                keeptrackRed++;
            }
            else
            {
                keeptrackRed = 0;
            }
            if (keeptrackRed == 4)
            {
                return true;
            }
            if(board[j][i].GetOwner() == 2)
            {
                keeptrackBlue++;
            }
            else
            {
                keeptrackBlue = 0;
            }
            if (keeptrackBlue == 4)
            {
                return true;
            }
        }
    }

    keeptrackBlue = 0;
    keeptrackRed = 0;
    int add = 0;
    int another = 0;

//CHECKS WINS ON A DIAGNAL FROM LEFT TO RIGHT
for (int k = 0; k < 4; k ++)
{
    for (int i = ROW-1; i >= 3; i--)
    { 
        add = 0;

        if (i == ROW-1 && k == 0)
        {
            another++;
        }
        else
        {
            another = 0;
        }

        for (int j = k; j < COLUMN - another; j++)
        {
           
            if(board[i-add][j].GetOwner() == 1)
            {
                keeptrackRed++;
            }
            else
            {
                keeptrackRed = 0;
            }

            if (keeptrackRed == 4)
            {
                return true;
            } 

            if(board[i-add][j].GetOwner() == 2)
            {
                keeptrackBlue++;
            }
            else
            {
                keeptrackBlue = 0;
            }

            if (keeptrackBlue == 4)
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


    keeptrackBlue = 0;
    keeptrackRed = 0;
    add = 0;
    another = 0;

//CHECK WINS DIAGONALLY FROM RIGHT TO LEFT
for (int k = 0; k < 4; k ++)
{
    for (int i = ROW-1; i >= 3; i--)
    { 
        add = 0;

        if (i == ROW - 1 && k == 0)
        {
            another++;
        }
        else
        {
            another = 0;
        }

        for (int j = (COLUMN-1) - k; j >= another; j--)
        {
           
            if(board[i-add][j].GetOwner() == 1)
            {
                keeptrackRed++;
            }
            else
            {
                keeptrackRed = 0;
            }

            if (keeptrackRed == 4)
            {
                return true;
            }

            if(board[i-add][j].GetOwner() == 2)
            {
                keeptrackBlue++;
            }
            else
            {
                keeptrackBlue = 0;
            }

            if (keeptrackBlue == 4)
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


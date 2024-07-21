//
// Created by AustinCrane-Work on 7/20/2024.
//

#ifndef CONNECTFOUR_GAMELOGIC_H
#define CONNECTFOUR_GAMELOGIC_H
#include "Board.h"
#include "BoardPiece.h"

class GameLogic {
public:
    static bool CheckIfWin(BoardPiece board[6][7]);
    static void reset_board(BoardPiece board[6][7]);
};


#endif //CONNECTFOUR_GAMELOGIC_H

//
// Created by AustinCrane-Work on 7/20/2024.
//

#ifndef CONNECTFOUR_GAMELOGIC_H
#define CONNECTFOUR_GAMELOGIC_H
#include "Board.h"

class GameLogic {
public:
    static bool CheckIfWin(int board[7][6]);
    static void reset_board(int board[7][6]);
};


#endif //CONNECTFOUR_GAMELOGIC_H

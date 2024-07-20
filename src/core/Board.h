#ifndef CONNECTFOUR_BOARD_H
#define CONNECTFOUR_BOARD_H


#include "raylib.h"

class Board {
public:
    Board(Texture2D* boardTexture, Texture2D* checkerTexture);

    void Update();
private:
    Texture2D* boardTexture;
    Texture2D* checkerTexture;
    void UpdateBoard();
};


#endif //CONNECTFOUR_BOARD_H

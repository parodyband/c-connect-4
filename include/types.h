#ifndef CONNECTFOUR_TYPES_H
#define CONNECTFOUR_TYPES_H

#include "BoardPiece.h"

static const int board_width = 7;
static const int board_height = 6;

typedef struct ScreenParams {
    int screenWidth;
    int screenHeight;
    int actualWidth;
    int actualHeight;
    float screenScaleFactor;
    int monitorID;
    int refreshRate;
} ScreenParams;

typedef struct Time {
    float deltaTime;
    float gameTime;
} Time;

class GameState {
public:
    GameState() {
        currentPlayer = 1;
        isDragging = false;
        draggingColumn = -1;
        draggingRow = -1;
        for (int i = 0; i < board_width; i++) {
            for (int j = 0; j < board_height; j++) {
                board[i][j] = BoardPiece();
                board[i][j].SetCol(i);
                board[i][j].SetRow(j);
            }
        }
    }
    BoardPiece board[board_width][board_height] = {};
    int currentPlayer;
    bool isDragging;
    int draggingColumn;
    int draggingRow;
};

#endif //CONNECTFOUR_TYPES_H
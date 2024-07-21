#ifndef CONNECTFOUR_TYPES_H
#define CONNECTFOUR_TYPES_H

#include "BoardPiece.h"

static const int rows = 6;
static const int columns = 7;

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
    }
    BoardPiece board[rows][columns] = {};
    int currentPlayer;
    bool isDragging;
    int draggingColumn;
    int draggingRow;
};

#endif //CONNECTFOUR_TYPES_H
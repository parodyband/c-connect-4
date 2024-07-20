#ifndef CONNECTFOUR_TYPES_H
#define CONNECTFOUR_TYPES_H

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

typedef struct GameState {
    int board[board_width][board_height];
    int currentPlayer;
} GameState;

#endif //CONNECTFOUR_TYPES_H
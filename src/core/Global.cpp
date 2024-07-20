#include "Global.h"
#include "Renderer.h"

// Define global variables
ScreenParams GLOBAL_SCREEN_PARAMS;
Time GLOBAL_TIME;
Renderer* MAIN_RENDERER = new Renderer();
Camera2D* MAIN_CAMERA = new Camera2D();
GameState GAME_STATE;
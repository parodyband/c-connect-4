#ifndef CONNECTFOUR_GLOBAL_H
#define CONNECTFOUR_GLOBAL_H
#include "raylib.h"
#include "types.h"

// Forward declare Renderer class
class Renderer;

// Declare global variables
extern ScreenParams GLOBAL_SCREEN_PARAMS;
extern Time GLOBAL_TIME;

extern Renderer* MAIN_RENDERER;
extern Camera2D* MAIN_CAMERA;

#endif // CONNECTFOUR_GLOBAL_H

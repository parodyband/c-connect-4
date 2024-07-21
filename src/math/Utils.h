#ifndef CONNECTFOUR_UTILS_H
#define CONNECTFOUR_UTILS_H


#include "raylib.h"
#include "raymath.h"
#include "Global.h"



class Utils {
public:
    static Vector2 MousePosition() {
        return Vector2Scale(GetMousePosition(), GLOBAL_SCREEN_PARAMS.screenScaleFactor);
    };
};


#endif //CONNECTFOUR_UTILS_H

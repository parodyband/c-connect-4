#include <cstdio>
#include "raylib.h"
#include "types.h"
#include "Global.h"
#include "Renderer.h"
#include "Entity.h"
#include "Bag.h"
#include "Board.h"


int main() {
    GLOBAL_SCREEN_PARAMS = (ScreenParams) {1280, 720,1280, 720, 1,0, 60};
    GLOBAL_TIME = (Time) {0, 0};
    GAME_STATE = (GameState) {{{0}}, 0};

    InitWindow(GLOBAL_SCREEN_PARAMS.screenWidth, GLOBAL_SCREEN_PARAMS.screenHeight, "Connect 4");
    InitAudioDevice();

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

    GLOBAL_SCREEN_PARAMS.refreshRate = GetMonitorRefreshRate(GLOBAL_SCREEN_PARAMS.monitorID);
    SetTargetFPS(GLOBAL_SCREEN_PARAMS.refreshRate);

    RenderTexture2D FullScreenTexture = LoadRenderTexture(GLOBAL_SCREEN_PARAMS.screenWidth,
                                                          GLOBAL_SCREEN_PARAMS.screenHeight);
    Texture2D bagTexture = LoadTexture("resources/bag.png");
    Texture2D boardPieceTexture = LoadTexture("resources/board_piece.png");
    Texture2D checkerTexture = LoadTexture("resources/checker.png");


    Bag bag = Bag((Vector2) {-310, 150}, 1.0f, true, bagTexture, 0.0f, WHITE);
    Board board = Board(&boardPieceTexture,&checkerTexture);

    MAIN_CAMERA->zoom = 1.5f;

    bool isFullscreen = false;

    while (!WindowShouldClose()) {
        GLOBAL_TIME.deltaTime = GetFrameTime();
        GLOBAL_TIME.gameTime += GLOBAL_TIME.deltaTime;

        if (IsKeyPressed(KEY_F11) || IsKeyPressed(KEY_ENTER) && IsKeyDown(KEY_LEFT_ALT) || IsKeyPressed(KEY_ENTER) && IsKeyDown(KEY_RIGHT_ALT)){
            isFullscreen = !isFullscreen;
            int monitor = GetCurrentMonitor();
            if (isFullscreen) {
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                ToggleFullscreen();

            } else {
                ToggleFullscreen();
                SetWindowSize(GLOBAL_SCREEN_PARAMS.screenWidth, GLOBAL_SCREEN_PARAMS.screenHeight);
            }
            GLOBAL_SCREEN_PARAMS.actualWidth = GetScreenWidth();
            GLOBAL_SCREEN_PARAMS.actualHeight = GetScreenHeight();
            GLOBAL_SCREEN_PARAMS.screenScaleFactor = (float) GLOBAL_SCREEN_PARAMS.screenWidth /
                                                     (float) GLOBAL_SCREEN_PARAMS.actualWidth;
        }

        MAIN_CAMERA->offset = (Vector2){ (float)GLOBAL_SCREEN_PARAMS.screenWidth / 2.0f, (float)GLOBAL_SCREEN_PARAMS.screenHeight / 2.0f };
        MAIN_CAMERA->target = (Vector2){ 0, 0 };

        BeginTextureMode(FullScreenTexture);
        ClearBackground(DARKDARKBLUE);

        BeginMode2D(*MAIN_CAMERA);
        board.Update();
        MAIN_RENDERER->Draw();
        EndMode2D();

        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(
                FullScreenTexture.texture,
                (Rectangle) {0.0f, 0.0f, (float) FullScreenTexture.texture.width,
                             (float) -FullScreenTexture.texture.height},
                (Rectangle) {0.0f, 0.0f, (float) GetScreenWidth(), (float) GetScreenHeight()},
                (Vector2) {0.0f, 0.0f},
                0.0f,
                WHITE
        );
        DrawFPS(10, 10);
        int entityCount = MAIN_RENDERER->getEntityCount();
        char charArray[50];
        snprintf(charArray, sizeof(charArray), "Entity Count: %d", entityCount);
        DrawText(charArray, 10, 30, 20, WHITE);
        EndDrawing();
    }

    UnloadTexture(bagTexture);
    UnloadTexture(boardPieceTexture);
    UnloadRenderTexture(FullScreenTexture);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
#include "raylib.h"
#include "Bag.h"
#include "Utils.h"

void Bag::Update() {
    Entity::Update();
    UpdateDragging();
}

void Bag::UpdateDragging() {
    Vector2 mouseWorldPos = GetScreenToWorld2D(Utils::MousePosition(), *MAIN_CAMERA);

    if (IsMouseOver()) {
        setTint(RED);
    } else {
        setTint(WHITE);
    }

    if (checker != nullptr) {
        switch (GAME_STATE->currentPlayer) {
            case 1:
                checker->setTint(RED);
                break;
            case 2:
                checker->setTint(BLUE);
                break;
            default:
                checker->setTint(WHITE);
                break;
        }
    }

    if (IsMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        GAME_STATE->isDragging = true;
        if (canCreateChecker) {
            checker = new Entity(mouseWorldPos, 1, true, checkerTexture, 0, WHITE);
            checker->setOrder(5);
            canCreateChecker = false;
        }
        if (checker != nullptr)
            dragOffset = Vector2Subtract(checker->getPosition(), mouseWorldPos);
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        GAME_STATE->isDragging = false;
        canCreateChecker = true;
        if (checker != nullptr) {
            delete checker;
            checker = nullptr;
        }
        for (int i = 5; i > -1; i--) {
            auto& curPiece = GAME_STATE->board[GAME_STATE->draggingColumn][i];
            if (curPiece.GetOwner() == 0) {
                curPiece.SetCheckerVisible(true);
                curPiece.SetOwner(GAME_STATE->currentPlayer);
                break;
            }
        }
        GAME_STATE->currentPlayer == 1 ? GAME_STATE->currentPlayer = 2 : GAME_STATE->currentPlayer = 1;
    }

    if (GAME_STATE->isDragging && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 newPosition = Vector2Add(mouseWorldPos, dragOffset);
        if (checker != nullptr)
            checker->setPosition(newPosition);
    }
}
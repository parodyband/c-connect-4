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
        switch (GAME_STATE.currentPlayer) {
            case 0:
                checker->setTint(RED);
                break;
            case 1:
                checker->setTint(BLUE);
                break;
            default:
                checker->setTint(WHITE);
                break;
        }
    }

    if (IsMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        dragging = true;
        if (canCreateChecker) {
            checker = new Entity(mouseWorldPos, 1, true, checkerTexture, 0, WHITE);
            checker->setOrder(5);
            canCreateChecker = false;
        }
        if (checker != nullptr)
            dragOffset = Vector2Subtract(checker->getPosition(), mouseWorldPos);
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        dragging = false;
        canCreateChecker = true;
        if (checker != nullptr) {
            delete checker;
            checker = nullptr;
        }
        GAME_STATE.currentPlayer == 1 ? GAME_STATE.currentPlayer = 0 : GAME_STATE.currentPlayer = 1;
    }

    if (dragging && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 newPosition = Vector2Add(mouseWorldPos, dragOffset);
        if (checker != nullptr)
            checker->setPosition(newPosition);
    }
}
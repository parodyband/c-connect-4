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
    }

    if (dragging && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 newPosition = Vector2Add(mouseWorldPos, dragOffset);
        if (checker != nullptr)
            checker->setPosition(newPosition);
    }
}

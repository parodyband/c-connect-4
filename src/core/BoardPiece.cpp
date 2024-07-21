#include "BoardPiece.h"
#include "Utils.h"

BoardPiece::BoardPiece(Vector2 Position, Texture2D boardTexture, Texture2D checkerTexture) {
    this->setPosition(Position);
    this->setTexture(boardTexture);
    this->setScale(1.0f);
    this->setRotation(0.0f);
    this->setTint(WHITE);
    this->setActive(true);
    auto *entity = new Entity(Position, 1.0f, false, checkerTexture, 0.0f, WHITE);
    entity->setOrder(-1);
    checker = entity;
}

void BoardPiece::CheckHover() {
    Vector2 mouseWorldPos = GetScreenToWorld2D(Utils::MousePosition(), *MAIN_CAMERA);
    Rectangle rec = Entity::GetDestRec();
    rec.x -= rec.width / 2;
    rec.y -= rec.height / 2;
    if (CheckCollisionPointRec(mouseWorldPos, rec)) {
        GAME_STATE->draggingColumn = Col;
        GAME_STATE->draggingRow = Row;
    }
}

void BoardPiece::Update() {
    Entity::Update();
    CheckHover();
}

BoardPiece::BoardPiece() = default;

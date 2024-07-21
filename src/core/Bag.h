#ifndef CONNECTFOUR_BAG_H
#define CONNECTFOUR_BAG_H

#include "Entity.h"
#include "Utils.h"

class Bag : public Entity {
public:
    Bag(Vector2 position, float scale, bool active, Texture2D texture, float rotation, Color tint)
            : Entity(position, scale, active, texture, rotation, tint), dragOffset() {
        Entity::setOrder(0);
        checkerTexture = LoadTexture("resources/checker.png");
    }
    ~Bag() {
        UnloadTexture(checkerTexture);
    }

    void Update() override;

    [[nodiscard]] float radius() const {
        return GetDestRec().width / 2;
    }

    [[nodiscard]] bool IsMouseOver() const {
        Vector2 mouseWorldPos = GetScreenToWorld2D(Utils::MousePosition(), *MAIN_CAMERA);
        return CheckCollisionPointCircle(mouseWorldPos, getPosition(), radius());
    }

private:
    Vector2 dragOffset;
    bool canCreateChecker = true;
    Entity* checker = nullptr;
    void UpdateDragging();
    Texture2D checkerTexture{};
};

#endif //CONNECTFOUR_BAG_H

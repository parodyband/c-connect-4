#ifndef CONNECTFOUR_ENTITY_H
#define CONNECTFOUR_ENTITY_H

#include "raylib.h"

class Entity {
public:
    Entity(Vector2 position, float scale, bool active, Texture2D texture, float rotation, Color tint);
    explicit Entity(Texture2D texture);

    Entity();

    ~Entity();

    [[nodiscard]] Vector2 getPosition() const { return position; }
    [[nodiscard]] float getScale() const { return scale; }
    [[nodiscard]] bool isActive() const { return active; }
    [[nodiscard]] Texture2D getTexture() const { return texture; }
    [[nodiscard]] float getRotation() const { return rotation; }
    [[nodiscard]] Color getTint() const { return tint; }
    [[nodiscard]] Rectangle GetSourceRec() const { return sourceRec; }
    [[nodiscard]] Rectangle GetDestRec() const { return destRec; }
    [[nodiscard]] Vector2 GetOrigin() const { return origin; }
    [[nodiscard]] int getOrder() const { return order; }


    void setPosition(Vector2 entityPosition) {
        position = entityPosition;
        UpdateRecs();
    }
    void setScale(float entityScale) {
        scale = entityScale;
        UpdateOrigin();
    }
    void setActive(bool entityActive) { active = entityActive; }
    void setTexture(Texture2D entityTexture) { texture = entityTexture; }
    void setRotation(float entityRotation) { rotation = entityRotation; }
    void setTint(Color entityTint) { tint = entityTint; }
    void setOrder(int entityOrder) { order = entityOrder; }

    virtual void Update();

private:
    int order{};
    Vector2 position{};
    Vector2 origin{};
    float scale{};
    bool active{};
    Texture2D texture{};
    float rotation{};
    Color tint{};
    Rectangle sourceRec{};
    Rectangle destRec{};

    void UpdateOrigin();
    void UpdateRecs();
};

#endif // CONNECTFOUR_ENTITY_H

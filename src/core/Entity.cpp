#include "Entity.h"
#include "Global.h"
#include "Renderer.h"

void Entity::UpdateRecs() {
    auto screenWidth = static_cast<float>(GLOBAL_SCREEN_PARAMS.screenWidth);
    auto screenHeight = static_cast<float>(GLOBAL_SCREEN_PARAMS.screenHeight);

    float scaleX = screenWidth / screenWidth;
    float scaleY = screenHeight / screenHeight;
    float scaleFactor = std::min(scaleX, scaleY);

    destRec = {
            position.x * scaleX,
            position.y * scaleY,
            static_cast<float>(texture.width) * scale * scaleFactor,
            static_cast<float>(texture.height) * scale * scaleFactor
    };
    sourceRec = {0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height)};
}

void Entity::UpdateOrigin() {
    origin = {static_cast<float>(texture.width) * 0.5f, static_cast<float>(texture.height) * 0.5f};
}

void Entity::Update() {
    UpdateRecs();
}

Entity::Entity(Vector2 pos, float scl, bool act, Texture2D tex, float rot, Color tnt)
        : position(pos), scale(scl), active(act), texture(tex), rotation(rot), tint(tnt) {
    Entity::setOrder(0);
    UpdateRecs();
    UpdateOrigin();
    MAIN_RENDERER->RegisterEntity(this);
}

Entity::Entity(Texture2D texture) {
    this->texture = texture;
    this->position = {0, 0};
    this->scale = 1;
    this->rotation = 0;
    this->tint = WHITE;
    this->active = true;
    UpdateRecs();
    UpdateOrigin();
    Entity::setOrder(0);
    MAIN_RENDERER->RegisterEntity(this);
}

Entity::~Entity(){
    MAIN_RENDERER->UnregisterEntity(this);
}
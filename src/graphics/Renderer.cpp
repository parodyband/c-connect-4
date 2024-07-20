// renderer.cpp
#include <algorithm>
#include "Renderer.h"

Renderer::~Renderer() {
    for (Entity* entity : entities) {
        delete entity;
    }
}

void Renderer::Draw() {
    SortEntities();
    for (Entity* entity : entities) {
        if (!entity->isActive()) {
            continue;
        }

        entity->Update();

        Texture2D texture = entity->getTexture();
        float rotation = entity->getRotation();
        Color tint = entity->getTint();

        Rectangle sourceRec = entity->GetSourceRec();
        Rectangle destRec = entity->GetDestRec();
        Vector2 origin = entity->GetOrigin();

        DrawTexturePro(texture, sourceRec, destRec, origin, rotation, tint);
    }
}

void Renderer::RegisterEntity(Entity* entity) {
    entities.push_back(entity);
    entityCount++;
}

void Renderer::UnregisterEntity(Entity *entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    entityCount--;
}

void Renderer::SortEntities() {
    std::sort(entities.begin(), entities.end(), [](Entity* a, Entity* b) {
        return a->getOrder() < b->getOrder();
    });
}

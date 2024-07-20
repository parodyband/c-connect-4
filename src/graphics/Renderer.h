#ifndef CONNECTFOUR_RENDERER_H
#define CONNECTFOUR_RENDERER_H

#include <vector>
#include "../core/Entity.h"

class Renderer {
public:
    ~Renderer();
    void Draw();
    void RegisterEntity(Entity* entity);
    void UnregisterEntity(Entity *entity);
    [[nodiscard]] int getEntityCount() const {
        return entityCount;
    }

private:
    std::vector<Entity*> entities;
    int entityCount = 0;
    void SortEntities();
};

#endif // CONNECTFOUR_RENDERER_H

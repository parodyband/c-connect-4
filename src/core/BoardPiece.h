#ifndef CONNECTFOUR_BOARDPIECE_H
#define CONNECTFOUR_BOARDPIECE_H

#include "Entity.h"

class BoardPiece : public Entity {
public:
    BoardPiece(Vector2 Position, Texture2D boardTexture, Texture2D checkerTexture);
    BoardPiece();
    void SetRow(int row) {
        Row = row;
    }
    void SetCol(int col) {
        Col = col;
    }
    void CheckHover();
    void Update() override;
    void SetCheckerVisible(bool visible) {
        checker->setActive(visible);
    }
    void SetOwner(int owner) {
        if (owner > 2 || owner < 0) {
            return;
        }
        Owner = owner;
        switch (owner) {
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
    int GetOwner() {
        return Owner;
    }

private:
    int Row{};
    int Col{};
    int Owner = 0;
    Entity* checker = nullptr;
};

#endif //CONNECTFOUR_BOARDPIECE_H

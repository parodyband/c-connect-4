#include "Board.h"
#include "Entity.h"

void Board::Update() {

}

Board::Board(Texture2D *boardTexture, Texture2D *checkerTexture){
    this->boardTexture = boardTexture;
    this->checkerTexture = checkerTexture;
    UpdateBoard();
}

void Board::UpdateBoard() {
    Entity* boardPieces[7][6];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            boardPieces[i][j] = new Entity((Vector2) {(float)(i - 3) * 64, (float)((j - 3) * 64) + 64}, 1.0f, true, *boardTexture, 0.0f, WHITE);
            boardPieces[i][j]->setOrder(2);
        }
    }
}


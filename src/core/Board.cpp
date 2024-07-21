#include "Board.h"
#include "BoardPiece.h"
#include "Global.h"

Board::Board(Texture2D boardTexture, Texture2D checkerTexture){
    this->boardTexture = boardTexture;
    this->checkerTexture = checkerTexture;
    UpdateBoard();
}

void Board::UpdateBoard() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            float x = (float)((i - 3) * 64) + 64;
            float y = (float)((j - 3) * 64) + 64;
            GAME_STATE->board[i][j] = BoardPiece(Vector2{x, y}, boardTexture, checkerTexture);
            GAME_STATE->board[i][j].SetRow(j);
            GAME_STATE->board[i][j].SetCol(i);
        }
    }
}

void Board::Update() {

}


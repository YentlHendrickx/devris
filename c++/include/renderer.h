#ifndef RENDERER_H
#define RENDERER_H

#include "board.h"
#include "piece.h"
#include "SDL.h"

class Renderer {
public:
// Passing by const reference to avoid copying objects
    void renderBoard(SDL_Renderer* renderer, Board& board, PieceType type);
    void renderPiece(SDL_Renderer* renderer, const Piece& piece);
};

#endif
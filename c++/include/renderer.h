#ifndef RENDERER_H
#define RENDERER_H

#include "board.h"
#include "piece.h"
#include "SDL.h"

class Renderer {
public:
    void renderBoard(SDL_Renderer* renderer, const Board& board);
    void renderPiece(SDL_Renderer* renderer, const Piece& piece);
};

#endif
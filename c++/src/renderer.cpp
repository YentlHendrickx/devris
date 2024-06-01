#include "renderer.h"
#include<iostream>

void Renderer::renderBoard(SDL_Renderer* renderer, const Board& board) {
    for (size_t y = 0; y < board.getHeight(); y++) {
        for (size_t x = 0; x < board.getWidth(); x++) {
            auto cell = board.getMatrix()[static_cast<int>(y)][static_cast<int>(x)];
            int occupied = cell.first;
            Color color = cell.second;

            if (occupied) {
                // Piece block
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_Rect rect = { static_cast<int>(x) * 30, static_cast<int>(y) * 30, 30, 30 };
                SDL_RenderFillRect(renderer, &rect);
                
                // Draw the border
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
}

void Renderer::renderPiece(SDL_Renderer* renderer, const Piece& piece) {
    Color color = piece.getColor();
    int x = piece.getX();
    int y = piece.getY(); 
    
    // Render the piece
    for (size_t i = 0; i < piece.getHeight(); i++) {
        for (size_t j = 0; j < piece.getWidth(); j++) {
            if (piece.getMatrix()[static_cast<int>(i)][static_cast<int>(j)] == 1) {
                int xPosition = x + j;
                int yPosition = y + i;

                // Piece block
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_Rect rect = {xPosition * 30, yPosition * 30, 30, 30};
                SDL_RenderFillRect(renderer, &rect);

                // Border
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
}
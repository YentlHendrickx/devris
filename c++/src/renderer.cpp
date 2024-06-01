#include "renderer.h"
#include<iostream>


// TODO: Make const ref in future
void Renderer::renderBoard(SDL_Renderer* renderer, Board& board, PieceType type) {
    // FOR DEBUGGING, LET'S CREATE A NEW BOARD INSTEAD OF USING THE ONE PASSED AS ARGUMENT
    // Add pieces to the board
    std::cout << "Creating a new piece" << std::endl;
    Piece piece(type);
    // board.addPiece(piece);

    // Render the board
    // std::vector<Piece> pieces = board.getPieces();
    
    // if (pieces.size() == 0) {
    //     return;
    // }

    // for (size_t i = 0; i < pieces.size(); i++) {
        renderPiece(renderer, piece);
    // }
}

void Renderer::renderPiece(SDL_Renderer* renderer, const Piece& piece) {
    Color color = piece.getColor();
    int x = piece.x();
    int y = piece.y(); 
    
    // Render the piece
    for (int i = 0; i < piece.getHeight() -1; i++) {
        for (int j = 0; j < piece.getWidth() -1; j++) {

            // Render the piece
            if (piece.getMatrix()[i][j] == 1) {
                int xPosition = x + j;
                int yPosition = y + i;

                // Render the piece, SDL
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                // Draw the rectangle
                SDL_Rect rect = {xPosition * 30, yPosition * 30, 30, 30};
                SDL_RenderFillRect(renderer, &rect);

                // Draw the border
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
    
    // Render the piece
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
}
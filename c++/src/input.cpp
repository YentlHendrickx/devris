#include "input.h"
#include<iostream>

// SDL event handling - https://wiki.libsdl.org/SDL_Event
#include<SDL.h>
#include "game.h"

void InputHandler::handleInput(Game& game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            game.close();
        }
        
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    game.close();
                    break;
                case SDLK_RIGHT:
                    std::cout << "Right key pressed" << std::endl;
                    game.movePiece(MoveDirection::RIGHT);
                    break;
                case SDLK_LEFT:
                    std::cout << "Left key pressed" << std::endl;
                    game.movePiece(MoveDirection::LEFT);
                    break;
                case SDLK_DOWN:
                    std::cout << "Down key pressed" << std::endl;
                    game.movePiece(MoveDirection::DOWN);
                    break;
                case SDLK_UP:
                    game.rotatePiece();
                    break; 
            }
        }
    }
}
#include "input.h"
#include<iostream>

// SDL event handling - https://wiki.libsdl.org/SDL_Event
#include<SDL.h>

void InputHandler::handleInput(bool& running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_RIGHT:
                    std::cout << "Right key pressed" << std::endl;
                    break;
                case SDLK_LEFT:
                    std::cout << "Left key pressed" << std::endl;
                    break;
                case SDLK_DOWN:
                    std::cout << "Down key pressed" << std::endl;
                    break;
                case SDLK_UP:
                    std::cout << "Up key pressed" << std::endl;
                    break; 
            }
        }
    }
}
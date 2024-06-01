#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include "input.h"
#include "board.h"
#include "renderer.h"

enum MoveDirection {
    LEFT,
    RIGHT,
    DOWN
};

class Game {
public:
    Game();
    ~Game();

public:
    bool init();
    void run();
    void close();
    void stop();
    
    void movePiece(MoveDirection direction);
    void rotatePiece();
    
private:
    void handleEvents();
    void render();
    void update();
    
private:
    bool _running = true;
    
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
    InputHandler _inputHandler;
    Renderer _gameRenderer;
    Board _board;
};

#endif
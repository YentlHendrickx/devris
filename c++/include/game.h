#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include "input.h"
#include "board.h"
#include "renderer.h"
#include <stdint.h>

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

    void togglePause() { _paused = !_paused; };
    
    void movePiece(MoveDirection direction);
    void rotatePiece();
    void getBoard() { _board.printBoard(); };
    
private:
    void handleEvents();
    void render();
    void update(uint32_t &lastTime);
    
private:
    bool _running = true;
    bool _paused = false;
    
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
    InputHandler _inputHandler;
    Renderer _gameRenderer;
    Board _board;
};

#endif
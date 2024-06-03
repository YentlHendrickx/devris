#include "game.h"
#include<iostream>

Game::Game() : _running(false), _window(nullptr), _renderer(nullptr) {
}

Game::~Game() {
    close();
}

void Game::close() {
    stop();

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    _window = nullptr;
    _renderer = nullptr;
    SDL_Quit();
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL: could not be initialized" << SDL_GetError() << std::endl;
        return false;
    }
    
    _window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!_window) {
        std::cout << "SDL: failed to create window" << SDL_GetError() << std::endl;
        return false;
    }
    
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        std::cout << "SDL: failed to create renderer" << SDL_GetError() << std::endl;
        return false;
    }
    
    _running = true;
    
    return true;
}

void Game::run() {
    uint32_t lastTime = SDL_GetTicks();
    while (_running) {
        handleEvents();
        update(lastTime);
        
        render();
    }
}

void Game::stop() {
    _running = false;
}

void Game::handleEvents() {
    _inputHandler.handleInput(*this);
}

void Game::render() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    _gameRenderer.renderBoard(_renderer, _board);
    _gameRenderer.renderPiece(_renderer, _board.currentPiece());
    SDL_RenderPresent(_renderer);

    SDL_Delay(5);
}

// Main game update loop
void Game::update(uint32_t &lastTime) { 
    if (!_board.currentPiece().isFalling()) {
        _board.addPiece(_board.currentPiece());
        _board.nextPiece();
        
        // Check if we have a line!
        _board.checkLines();
        
        // Check if the new piece can be added to the board
        if (!_board.currentPiece().canMoveTo(_board.currentPiece().getX(), _board.currentPiece().getY(), _board)) {
            // TODO: GAME OVER, better logic!
            stop();
        }
    }

    if (!_paused) {
        if (_board.currentPiece().isFalling()) {
            uint32_t currentTime = SDL_GetTicks();
            if (currentTime - lastTime > 250) {
                lastTime = currentTime;
                _board.currentPiece().moveDown(_board);
            }
        }
    }
}

void Game::movePiece(MoveDirection direction) {
    switch (direction) {
        case MoveDirection::LEFT:
            _board.currentPiece().moveLeft(_board);
            break;
        case MoveDirection::RIGHT:
            _board.currentPiece().moveRight(_board);
            break;
        case MoveDirection::DOWN:
            _board.currentPiece().moveDown(_board);
            break;
    }
}

void Game::rotatePiece() {
    _board.currentPiece().rotate();
}
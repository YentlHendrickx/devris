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
    while (_running) {
        handleEvents();
        // update();
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
    SDL_RenderPresent(_renderer);

    _gameRenderer.renderBoard(_renderer, _board);
    _gameRenderer.renderPiece(_renderer, _board.currentPiece());
    SDL_RenderPresent(_renderer);
    SDL_Delay(150);
}

// Main game update loop
void Game::update() {
    
}

void Game::movePiece(MoveDirection direction) {
    // TODO: Collision detection!
    switch (direction) {
        case MoveDirection::LEFT:
            _board.currentPiece().moveLeft();
            break;
        case MoveDirection::RIGHT:
            _board.currentPiece().moveRight();
            break;
        case MoveDirection::DOWN:
            _board.currentPiece().moveDown();
            break;
    }
}

void Game::rotatePiece() {
    _board.currentPiece().rotate();
}
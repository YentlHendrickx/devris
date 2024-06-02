#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "piece.h"

constexpr int DEF_BOARD_WIDTH = 10;
constexpr int DEF_BOARD_HEIGHT = 20;

typedef std::vector<std::vector<std::pair<int, Color>>> BoardMatrix;

class Board {
public:
    Board();
    Board(int width, int height);
    ~Board();

public:
    size_t getWidth() const { return _gameBoard[0].size(); }
    size_t getHeight() const { return _gameBoard.size(); }
    BoardMatrix getMatrix() const { return _gameBoard; }
    
    void init();
    void clear();
    void addPiece(const Piece& piece);
    Piece& currentPiece() { return _currentPiece; }
    void nextPiece(Piece &piece);

private:
    BoardMatrix _gameBoard;
    Piece _currentPiece;
    Piece _nextPiece;

    int _score;
    int _lines;
    int _level;
    int _speed;
    int _speedCounter;
    bool _gameOver;
    int _boardWidth;
    int _boardHeight;
};


#endif
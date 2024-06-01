#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

constexpr int DEF_BOARD_WIDTH = 10;
constexpr int DEF_BOARD_HEIGHT = 20;

// typedef std::vector<std::vector<int, Color>> BoardMatrix;

class Board {
public:
    Board();
    Board(int width, int height);
    ~Board();

public:
    bool init();
    void clear();
    int getHeight() const;
    int getWidth() const;
    std::vector<Piece> getPieces() const;
    void addPiece(const Piece& piece);

private:
    // BoardMatrix _Placedboard;

    std::vector<Piece> _pieces;
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
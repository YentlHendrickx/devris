#include "piece.h"
#include "board.h"
#include<iostream>

Piece::Piece() : _pieceType(unknownPiece), _pieceRotation(1) {
    initMatrix();
}

Piece::Piece(PieceType type): _pieceType(type), _pieceRotation(1){
    initMatrix();
}

Piece::Piece(const Piece& other) // Copy constructor
    : _pieceType(other._pieceType),
      _piece(other._piece),
      _pieceColor(other._pieceColor),
      _x(other._x),
      _y(other._y) {}

Piece& Piece::operator=(const Piece& other) { // Copy assignment operator
    if (this == &other) return *this;

    _pieceType = other._pieceType;
    _piece = other._piece;
    _pieceColor = other._pieceColor;
    _x = other._x;
    _y = other._y;
    return *this;
}


Piece::~Piece() {}

void Piece::moveLeft(Board &board) {
    if (canMoveTo(_x - 1, _y, board))
        _x--;
}

void Piece::moveRight(Board &board) {
    if (canMoveTo(_x + 1, _y, board)) {
        _x++;
    }
}

void Piece::moveDown(Board &board) {
    if (canMoveTo(_x, _y + 1, board)) {
        _y++;
    } else {
        _pieceFalling = false;
        std::cout << "Piece has landed\n" << std::endl;
    }
}

bool Piece::canMoveTo(int newX, int newY, Board &board) {
    int boardWidth = board.getWidth();
    int boardHeight = board.getHeight();
    auto boardMatrix = board.getMatrix();

    for (int i = 0; i < _piece.size(); ++i) {
        for (int j = 0; j < _piece[i].size(); ++j) {
            if (_piece[i][j] != 0) {
                int boardX = newX + j;
                int boardY = newY + i;

                // Check if the position is out of bounds
                if (boardX < 0 || boardX >= boardWidth || boardY < 0 || boardY >= boardHeight) {
                    return false;
                }

                // Check if the position is already occupied
                if (boardMatrix[boardY][boardX].first != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Piece::rotate(bool clockwise) {
    _pieceRotation = clockwise ? _pieceRotation + 1 : _pieceRotation - 1;
    if (_pieceRotation > 4) {
        _pieceRotation = 1;
    } else if (_pieceRotation < 1) {
        _pieceRotation = 4;
    }
    
    initMatrix();

    int newX = _x;
    int newY = _y;

    while (newX < 0) {
        newX++;
    }

    while (newX + _piece[0].size() > 10) {
        newX--;
    }

    while (newY + _piece.size() > 20) {
        newY--;
    }

    _x = newX;
    _y = newY;
}

void Piece::initMatrix() {
    switch (_pieceType) {
        case oPiece:
            _piece = O_PIECE[_pieceRotation - 1];
            _pieceColor = yellow;
            break;
        case iPiece:
            _piece = I_PIECE[_pieceRotation - 1];
            _pieceColor = cyan;
            break;
        case sPiece:
            _piece = S_PIECE[_pieceRotation - 1];
            _pieceColor = red;
            break;
        case zPiece:
            _piece = Z_PIECE[_pieceRotation - 1];
            _pieceColor = green;
            break;
        case lPiece:
            _piece = L_PIECE[_pieceRotation - 1];
            _pieceColor = orange;
            break;
        case jPiece:
            _piece =  J_PIECE[_pieceRotation - 1];
            _pieceColor = pink;
            break;
        case tPiece:
            _piece = T_PIECE[_pieceRotation - 1];
            _pieceColor = purple;
            break;
        case unknownPiece:
            _piece = UNKNOWN_PIECE[_pieceRotation - 1];
            _pieceColor = white;
            break;
    } 
}
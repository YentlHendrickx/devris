#include "piece.h"
#include<iostream>

Piece::Piece() : _currentPieceType(unknownPiece), _currentPieceRotation(1) {
    initMatrix();
}

Piece::Piece(PieceType type): _currentPieceType(type), _currentPieceRotation(1){
    initMatrix();
}

Piece::Piece(const Piece& other)
    : _currentPieceType(other._currentPieceType),
      _currentPiece(other._currentPiece),
      _currentPieceColor(other._currentPieceColor),
      _x(other._x),
      _y(other._y) {}

Piece& Piece::operator=(const Piece& other) {
    if (this == &other) return *this;

    _currentPieceType = other._currentPieceType;
    _currentPiece = other._currentPiece;
    _currentPieceColor = other._currentPieceColor;
    _x = other._x;
    _y = other._y;
    return *this;
}


Piece::~Piece() {}

void Piece::fall() {
}

void Piece::moveLeft() {
    _x--;

    if (_x < 0) {
        _x = 0;
    }
}

void Piece::moveRight() {
    _x++;
    
    std::cout << "X: " << _x << std::endl;

    // TODO: Actual bounds checking, not hardcoded
    if (_x > 10 - 4) {
        _x = 10 - 4;
    }
}

void Piece::moveDown() {
    _y++;

    // TODO: Actual bounds checking, not hardcoded
    if (_y > 20 - 4) {
        _y = 20 - 4;
    }
}

void Piece::rotate(bool clockwise) {
    int height = _currentPiece.size();
    int width = _currentPiece[0].size();

    // Transpose the matrix
    std::vector<std::vector<int>> transposed(width, std::vector<int>(height, 0));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            transposed[j][i] = _currentPiece[i][j];
        }
    }

    // Create a new matrix for the rotated piece
    std::vector<std::vector<int>> rotated(height, std::vector<int>(width, 0));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (clockwise) {
                rotated[i][j] = transposed[width - 1 - j][i];
            } else {
                rotated[i][j] = transposed[j][height - 1 - i];
            }
        }
    }

    // Update the current piece with the rotated matrix
    _currentPiece = rotated;
}


/* void Piece::initMatrix() {
    _currentPiece = std::vector<std::vector<int>>(4, std::vector<int>(4, 0)); // Clear the matrix before initialization

    switch (_currentPieceType) {
        case oPiece:
            _currentPiece[2][2] = 1;
            _currentPiece[2][3] = 1;
            _currentPiece[3][2] = 1;
            _currentPiece[3][3] = 1;
            _currentPieceColor = red;
            break;
        case iPiece:
            _currentPiece[3][0] = 1;
            _currentPiece[3][1] = 1;
            _currentPiece[3][2] = 1;
            _currentPiece[3][3] = 1;
            _currentPieceColor = green;
            break;
        case sPiece:
            _currentPiece[2][2] = 1;
            _currentPiece[2][3] = 1;
            _currentPiece[3][1] = 1;
            _currentPiece[3][2] = 1;
            _currentPieceColor = blue;
            break;
        case zPiece:
            _currentPiece[2][1] = 1;
            _currentPiece[2][2] = 1;
            _currentPiece[3][2] = 1;
            _currentPiece[3][3] = 1;
            _currentPieceColor = yellow;
            break;
        case lPiece:
            _currentPiece[1][3] = 1;
            _currentPiece[2][3] = 1;
            _currentPiece[3][2] = 1;
            _currentPiece[3][3] = 1;
            _currentPieceColor = orange;
            break;
        case jPiece:
            _currentPiece[1][2] = 1;
            _currentPiece[2][2] = 1;
            _currentPiece[3][2] = 1;
            _currentPiece[3][3] = 1;
            _currentPieceColor = purple;
            break;
        case tPiece:
            _currentPiece[2][1] = 1;
            _currentPiece[2][2] = 1;
            _currentPiece[2][3] = 1;
            _currentPiece[3][2] = 1;
            _currentPieceColor = cyan;
            break;
        case unknownPiece:
            // Easter egg X
            _currentPiece[1][2] = 1;
            _currentPiece[1][3] = 1;
            _currentPiece[2][1] = 1;
            _currentPiece[3][2] = 1;
            _currentPiece[3][3] = 1;
            _currentPieceColor = green;
            break;
    }
}
 */
void Piece::initMatrix() {
    switch (_currentPieceType) {
        case oPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {1, 1},
                {1, 1}
            };
            _currentPieceColor = red;
            break;
        case iPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {1, 1, 1, 1}
            };
            _currentPieceColor = green;
            break;
        case sPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {0, 1, 1},
                {1, 1, 0}
            };
            _currentPieceColor = blue;
            break;
        case zPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {1, 1, 0},
                {0, 1, 1}
            };
            _currentPieceColor = yellow;
            break;
        case lPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {1, 0},
                {1, 0},
                {1, 0}
            };
            _currentPieceColor = orange;
            break;
        case jPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {0, 1},
                {0, 1},
                {1, 1}
            };
            _currentPieceColor = purple;
            break;
        case tPiece:
            _currentPiece = std::vector<std::vector<int>>{
                {0, 1, 0},
                {1, 1, 1}
            };
            _currentPieceColor = cyan;
            break;
        case unknownPiece:
            // Easter egg X
            _currentPiece = std::vector<std::vector<int>>{
                {1, 0, 1},
                {0, 1, 0},
                {1, 0, 1}
            };
            _currentPieceColor = green;
            break;
    }
}
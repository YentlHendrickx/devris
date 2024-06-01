#include "piece.h"

Piece::Piece() {
    _currentPieceType = unknownPiece;
    setMatrix();
}

Piece::Piece(PieceType type) {
    _currentPieceType = type;
    setMatrix();
}

Piece::~Piece() {}

void Piece::fall() {
}

void Piece::move() {
}

void Piece::rotate(bool clockwise) {
}

int Piece::getHeight() const {
    return 4;
}

int Piece::getWidth() const {
    return 4;
}

std::vector<std::vector<int>> Piece::getMatrix() const {
    return _currentPiece;
}

Color Piece::getColor() const {
    return _currentPieceColor;
}

int Piece::x() const {
    return _currentPieceX;
}

int Piece::y() const {
    return _currentPieceY;
}

void Piece::setMatrix() {
    switch (_currentPieceType) {
        // X, Y -> 0, 0 is the top left corner
        // 1 means there is a block, 0 means there is no block
        case oPiece:
            _currentPiece[0][0] = 1;
            _currentPiece[0][1] = 1;
            _currentPiece[1][0] = 1;
            _currentPiece[1][1] = 1;
            _currentPieceColor = red;
            break;
        case iPiece:
            _currentPiece[0][0] = 1;
            _currentPiece[0][1] = 1;
            _currentPiece[0][2] = 1;
            _currentPiece[0][3] = 1;
            _currentPieceColor = green;
            break;
        case sPiece:
            _currentPiece[0][1] = 1;
            _currentPiece[0][2] = 1;
            _currentPiece[1][0] = 1;
            _currentPiece[1][1] = 1;
            _currentPieceColor = blue;
            break;
        case zPiece:
            _currentPiece[0][0] = 1;
            _currentPiece[0][1] = 1;
            _currentPiece[1][1] = 1;
            _currentPiece[1][2] = 1;
            _currentPieceColor = yellow;
            break;
        case lPiece:
            _currentPiece[0][0] = 1;
            _currentPiece[1][0] = 1;
            _currentPiece[2][0] = 1;
            _currentPiece[2][1] = 1;
            _currentPieceColor = orange;
            break;
        case jPiece:
            _currentPiece[0][1] = 1;
            _currentPiece[1][1] = 1;
            _currentPiece[2][0] = 1;
            _currentPiece[2][1] = 1;
            _currentPieceColor = purple;
            break;
        case tPiece:
            _currentPiece[0][0] = 1;
            _currentPiece[0][1] = 1;
            _currentPiece[0][2] = 1;
            _currentPiece[1][1] = 1;
            _currentPieceColor = cyan;
            break;
        case unknownPiece:
            // Easter egg X
            _currentPiece[0][0] = 1;
            _currentPiece[0][2] = 1;
            _currentPiece[1][1] = 1;
            _currentPiece[2][0] = 1;
            _currentPiece[2][2] = 1;
            _currentPieceColor = green;
            break;
    };
}
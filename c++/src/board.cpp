#include "board.h"

Board::Board() {
    _boardWidth = DEF_BOARD_WIDTH;
    _boardHeight = DEF_BOARD_HEIGHT;
}

Board::Board(int width, int height) {
    _boardWidth = width;
    _boardHeight = height;
}

Board::~Board() {}

bool Board::init() {
    return true;
}

int Board::getWidth() const {
    return _boardWidth;
}

int Board::getHeight() const {
    return _boardHeight;
}

std::vector<Piece> Board::getPieces() const {
    return _pieces;
}

void Board::addPiece(const Piece& piece) {
    _pieces.push_back(piece);
}

void Board::clear() {}

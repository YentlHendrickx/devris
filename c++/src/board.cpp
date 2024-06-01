#include "board.h"
#include<iostream>
#include<random>

Board::Board() : _boardWidth(DEF_BOARD_WIDTH), _boardHeight(DEF_BOARD_HEIGHT) {
    init();
}

Board::Board(int width, int height) : _boardWidth(width), _boardHeight(height) {
    init();
}

Board::~Board() {}

void Board::init() {
    _gameBoard = BoardMatrix(_boardHeight, std::vector<std::pair<int, Color>>(_boardWidth, {0, {0, 0, 0}}));
    
    // Random number between 0 and 6
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);

    // Generate 2 pieces, the current piece and the next piece
    _currentPiece = Piece(static_cast<PieceType>(dis(gen)));
    _nextPiece = Piece(static_cast<PieceType>(dis(gen)));
}

void Board::clear() {
    for (auto& row : _gameBoard) {
        for (auto& cell : row) {
            cell = {0, {0, 0, 0}};
        }
    }
}

void Board::addPiece(const Piece& piece) {
    auto matrix = piece.getMatrix();
    int pieceX = piece.getX();
    int pieceY = piece.getY();
    Color pieceColor = piece.getColor();
    
    std::cout << "Piece X: " << pieceX << " Piece Y: " << pieceY << std::endl;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            std::cout << matrix[static_cast<int>(i)][static_cast<int>(j)] << " ";
        }
        std::cout << std::endl;
    }

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            if (matrix[static_cast<int>(i)][static_cast<int>(j)] == 1) {
                int boardX = pieceX + j;
                int boardY = pieceY + i;
                
                if (boardX >= 0 && boardX < _boardWidth && boardY >= 0 && boardY < _boardHeight) {
                    _gameBoard[boardY][boardX] = {1, pieceColor};
                }
            }
        }
    }
}
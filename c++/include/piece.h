#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "pieces.h"

// Forward declaration
class Board;

enum PieceType { oPiece, iPiece, sPiece, zPiece, lPiece, jPiece, tPiece, unknownPiece };

struct Color {
    int r;
    int g;
    int b;
};

class Piece {
public:
    Piece();
    Piece(PieceType type);
    Piece(const Piece& other); // Copy constructor
    Piece& operator=(const Piece& other); // Copy assignment operator
    ~Piece();

private:
    void initMatrix();

    const Color yellow = {255, 255, 0};
    const Color cyan = {0, 255, 255};
    const Color red = {255, 0, 0};
    const Color green = {0, 255, 0};
    const Color orange = {255, 165, 0};
    const Color pink = {255, 192, 203};
    const Color purple = {128, 0, 128};
    const Color white = {255, 255, 255};

public:
    PieceMatrix getMatrix() const { return _piece; }
    int getRotation() const { return _pieceRotation; }
    size_t getHeight() const { return _piece.size(); }
    size_t getWidth() const { return _piece.size(); }
    Color getColor() const { return _pieceColor; }
    int getX() const { return _x; };
    int getY() const { return _y; };
    void setIsFalling(bool falling) { _pieceFalling = falling; }
    void setX(int x) { _x = x; };
    void setY(int y) { _y = y; };
    
    void rotate(bool clockwise = true);
    bool isFalling() const { return _pieceFalling; }

    void moveLeft(Board &board);
    void moveRight(Board &board);
    void moveDown(Board &board);
    bool canMoveTo(int newX, int newY, Board &board);
    
private:
    // Pieces always fall from the top middle of the board
    int _x = 0;
    int _y = 0;
    
    PieceType _pieceType;

    // Actual piece representation, 4x4 matrix
    PieceMatrix _piece;

    // Rotation of the piece, 1-4
    int _pieceRotation = 1;
    Color _pieceColor = {0, 0, 0};

    // Default we set it to true, so it will automatically fall
    bool _pieceFalling = true;
};

#endif
#ifndef PIECE_H
#define PIECE_H
#include <vector>

enum PieceType { oPiece, iPiece, sPiece, zPiece, lPiece, jPiece, tPiece, unknownPiece };
struct Color {
    int r;
    int g;
    int b;
};
typedef std::vector<std::vector<int>> Matrix;

class Piece {
public:
    Piece();
    Piece(PieceType type);
    ~Piece();

private:
    void setMatrix();

    const Color red = {255, 0, 0};
    const Color green = {0, 255, 0};
    const Color blue = {0, 0, 255};
    const Color yellow = {255, 255, 0};
    const Color orange = {255, 165, 0};
    const Color purple = {128, 0, 128};
    const Color cyan = {0, 255, 255};

public:
    int getHeight() const;
    int getWidth() const;
    std::vector<std::vector<int>> getMatrix() const;
    int x() const;
    int y() const;
    Color getColor() const;

    void rotate(bool clockwise = true);
    void move();
    void fall();
    
private:
    // Pieces always fall from the top middle of the board
    int _currentPieceX = 0;
    int _currentPieceY = 0;
    
    PieceType _currentPieceType;

    // Actual piece representation, 4x4 matrix
    Matrix _currentPiece = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));

    // Rotation of the piece, 1-4
    int _currentPieceRotation;
    Color _currentPieceColor = {0, 0, 0};

    // Default we set it to true, so it will automatically fall
    bool _pieceFalling = true;
};

#endif
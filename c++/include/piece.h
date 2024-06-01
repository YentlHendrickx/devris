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
    Piece(const Piece& other); // Copy constructor
    Piece& operator=(const Piece& other); // Copy assignment operator
    ~Piece();

private:
    void initMatrix();

    const Color red = {255, 0, 0};
    const Color green = {0, 255, 0};
    const Color blue = {0, 0, 255};
    const Color yellow = {255, 255, 0};
    const Color orange = {255, 165, 0};
    const Color purple = {128, 0, 128};
    const Color cyan = {0, 255, 255};

public:
    std::vector<std::vector<int>> getMatrix() const { return _currentPiece; }
    int getRotation() const { return _currentPieceRotation; }
    size_t getHeight() const { return _currentPiece.size(); }
    size_t getWidth() const { return _currentPiece.size(); }
    Color getColor() const { return _currentPieceColor; }
    int getX() const { return _x; };
    int getY() const { return _y; };
    void setX(int x) { _x = x; };
    void setY(int y) { _x = y; };

    void rotate(bool clockwise = true);
    void fall();
    void moveLeft();
    void moveRight();
    void moveDown();
    
private:
    // Pieces always fall from the top middle of the board
    int _x = 0;
    int _y = 0;
    
    PieceType _currentPieceType;

    // Actual piece representation, 4x4 matrix
    Matrix _currentPiece;

    // Rotation of the piece, 1-4
    int _currentPieceRotation;
    Color _currentPieceColor = {0, 0, 0};

    // Default we set it to true, so it will automatically fall
    bool _pieceFalling = true;
};

#endif
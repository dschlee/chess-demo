#pragma once
#include <cmath>

// Struct representing the position of pieces on the board
struct Position
{
    int row;
    int col;

    Position(int r = -1, int c = -1)
        : row(r), col(c) {}
};

// Enum representing different types of pieces
enum class PieceType
{
    Pawn = 'P',
    Knight = 'N',
    Bishop = 'B',
    Rook = 'R',
    Queen = 'Q',
    King = 'K'
};

// Enum representing different piece colors
enum class PieceColor
{
    White = 'w',
    Black = 'b'
};

// Abstract base class for a chess piece
class Piece
{
protected:
    Position pos_;
    PieceType piece_type_;
    PieceColor piece_color_;

public:
    // Constructor
    Piece(const Position &pos, PieceType piece_type, PieceColor piece_color_);

    // Virtual destructor
    virtual ~Piece() = default;

    // Pure virtual function to check if a move is valid
    virtual bool can_move(const Position &start, const Position &end) const = 0;

    // Sets the position of the piece
    void set_position(const Position &pos);

    // Sets the color of the piece
    void set_piece_color(const PieceColor piece_color);

    // Gets the current position of the piece
    Position get_position() const;

    // Gets the abbreviation of the piece type
    PieceType get_piece_type() const;

    // Gets the abbrevation of the piece color
    PieceColor get_piece_color() const;
};
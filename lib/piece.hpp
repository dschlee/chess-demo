#pragma once
#include "../lib/position.hpp"

// Forward declaration
class Board;

// Enum representing different types of pieces
enum class PieceType
{
    Knight = 'K',
    Rook = 'R'
};

// Abstract base class for a chess piece
class Piece
{
protected:
    Position pos_;
    PieceType piece_type_;

public:
    // Default constructor with invalid position
    Piece();

    // Constructor
    Piece(const Position &pos, PieceType piece_type);

    // Virtual destructor
    virtual ~Piece() = default;

    // Pure virtual function to check if a move is valid
    virtual bool can_move(const Position &start, const Position &end, const Board &board) const = 0;

    // Pure virtual function to execute the move
    virtual void move(const Position &start, const Position &end, Board &board) = 0;

    // Sets the position of the piece
    void set_position(const Position &pos);

    // Gets the current position of the piece
    Position get_position() const;

    // Gets the abbreviation of the piece type
    char get_piece_type() const;
};
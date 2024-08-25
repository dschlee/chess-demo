#pragma once
#include <cmath>
#include <iostream>

// Struct representing the position of pieces on the board
struct Position
{
    int col;
    int row;

    // Default constructor
    Position(int c = -1, int r = -1)
        : col(c), row(r) {}

    // Constructor from algebraic notation
    Position(const std::string &algebraic)
    {
        if (algebraic.length() == 2 &&
            algebraic[0] >= 'a' &&
            algebraic[0] <= 'h' &&
            algebraic[1] >= '1' &&
            algebraic[1] <= '8')
        {
            col = algebraic[0] - 'a' + 1;
            row = algebraic[1] - '1' + 1;
        }
        else
        {
            std::cout << "Invalid algebraic notation: " << algebraic << "." << std::endl;
            col = -1;
            row = -1;
        }
    }

    // Convert the position to algebraic notation
    std::string to_algebraic() const
    {
        if (col < 1 || col > 8 || row < 1 || row > 8)
        {
            std::cout << "Invalid algebraic notation." << std::endl;
        }

        char col_alg = 'a' + (col - 1); // Convert column number to file character
        char row_alg = '1' + (row - 1); // Convert row number to rank character

        return std::string(1, col_alg) + row_alg;
    }
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
    virtual bool can_move(const Position &start, const Position &end, const Piece *end_piece) const = 0;

    // Virtual function to check if the piece can capture another piece during a move
    virtual bool can_capture(const Piece *end_piece) const;

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

    // // Gets the position in algebraic notation
    // std::string to_algebraic() const;
};
#pragma once
#include <array>
#include "../lib/piece.hpp"

const int BOARD_SIZE = 9;

class Board
{
private:
    std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> board{};

public:
    // Constructor initializes the board with nullptrs
    Board();

    // Default destructor
    ~Board() = default;

    // Gets the piece at a given position
    Piece *get_piece(const Position &pos) const;

    // Sets a piece at a given position
    void set_piece(Piece &piece, const Position &pos);

    // Moves a piece from the start position to the end position
    bool move_piece(const Position &start, const Position &end);

    // Displays the current state of the board
    void draw() const;

    // bool is_position_valid(int piece);
};
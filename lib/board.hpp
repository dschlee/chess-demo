#pragma once
#include <array>
// #include "../lib/piece.hpp"
#include "../lib/rook.hpp"
#include "../lib/knight.hpp"

const int BOARD_SIZE = 9;
const int MAX_PIECES_ROOK = 4;
const int MAX_PIECES_KNIGHT = 4;

class Board
{
private:
    std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> board{};
    std::array<Rook, MAX_PIECES_ROOK> rooks;
    std::array<Knight, MAX_PIECES_KNIGHT> knights;
    int rook_count = 0;
    int knight_count = 0;

    /**
     * Template method to update the position of a piece in the provided array
     * Allows to reuse existing pieces by updating their position
     * instead of creating new ones in their place.
     */
    template <typename T, size_t N>
    void update_piece_pos_in_array(std::array<T, N> &pieces, const Position &pos);

    // Template method to print the arrays of differnt pieces
    template <typename T, size_t N>
    void print_piece_array(std::array<T, N> &pieces);

public:
    // Constructor initializes the board with nullptrs
    Board();

    // Default destructor
    ~Board() = default;

    // Gets the piece at a given position
    Piece *get_piece(const Position &pos) const;

    // Sets a piece at a given position
    void set_piece(char piece_type, Position pos);

    // Prints all the valid pieces on the board
    void print_pieces();

    // Moves a piece from the start position to the end position
    bool move_piece(const Position &start, const Position &end);

    // Displays the current state of the board
    void draw() const;

    // Checks if the given position is within bounds
    bool is_position_on_board(Position &pos);
};
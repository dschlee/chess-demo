#pragma once
#include <array>
#include "../lib/pawn.hpp"
#include "../lib/pawn.hpp"
#include "../lib/knight.hpp"
#include "../lib/bishop.hpp"
#include "../lib/rook.hpp"
#include "../lib/queen.hpp"
#include "../lib/king.hpp"

const int BOARD_SIZE = 9;
const int MAX_PIECES_PAWN = 16;
const int MAX_PIECES_KNIGHT = 4;
const int MAX_PIECES_BISHOP = 4;
const int MAX_PIECES_ROOK = 4;
const int MAX_PIECES_QUEEN = 2;
const int MAX_PIECES_KING = 2;

class Board
{
private:
    std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> board{};
    std::array<Pawn, MAX_PIECES_PAWN> pawns;
    std::array<Knight, MAX_PIECES_KNIGHT> knights;
    std::array<Bishop, MAX_PIECES_ROOK> bishops;
    std::array<Rook, MAX_PIECES_ROOK> rooks;
    std::array<Queen, MAX_PIECES_QUEEN> queens;
    std::array<King, MAX_PIECES_KING> kings;
    int pawn_count = 0;
    int knight_count = 0;
    int bishop_count = 0;
    int rook_count = 0;
    int queen_count = 0;
    int king_count = 0;

    /**
     * Template method to set the position of a piece in the provided array.
     * This brings the piece onto the board.
     * Allows to reuse existing pieces by updating their position
     * instead of creating new ones in their place.
     */
    template <typename T, size_t N>
    void spawn_piece_pos_in_array(std::array<T, N> &pieces, const Position &pos);

    // Template method to print the arrays of differnt pieces
    template <typename T, size_t N>
    void print_piece_array(const std::array<T, N> &pieces) const;

    // Moves the desired piece from the start to the end position
    void move_piece_pos_in_array(Piece *piece, const Position &start, const Position &end);

    // Gets the piece at a given position
    Piece *get_piece(const Position &pos) const;

    // Checks if the given position is within bounds
    bool is_position_on_board(const Position &pos) const;

    // Checks if maximum amount of piece types are on the board
    bool is_max_piece_type_reached(const char piece_type, const int count, const int max) const;

    // Get the unicode characters of the selected piece
    std::string get_piece_unicode(const char piece_type) const;

public:
    // Constructor initializes the board with nullptrs
    Board();

    // Default destructor
    ~Board() = default;

    // Sets a piece at a given position
    void spawn_piece(char piece_type, Position pos);

    // Executes the move move for a piece from the start position to the end position
    void move_piece(const Position &start, const Position &end);

    // Prints all the valid pieces on the board
    void print_active_pieces() const;

    // Displays the current state of the board
    void draw() const;
};
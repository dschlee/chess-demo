#pragma once
#include <array>
#include "../lib/piece.hpp"
#include "../lib/pawn.hpp"
#include "../lib/knight.hpp"
#include "../lib/bishop.hpp"
#include "../lib/rook.hpp"
#include "../lib/queen.hpp"
#include "../lib/king.hpp"

const int BOARD_SIZE = 9;
const int MAX_PIECES_PAWN = 8;
const int MAX_PIECES_KNIGHT = 2;
const int MAX_PIECES_BISHOP = 2;
const int MAX_PIECES_ROOK = 2;
const int MAX_PIECES_QUEEN = 1;
const int MAX_PIECES_KING = 1;

class Board
{
private:
    std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> board{};
    std::array<Pawn, MAX_PIECES_PAWN> pawns_w;
    std::array<Knight, MAX_PIECES_KNIGHT> knights_w;
    std::array<Bishop, MAX_PIECES_ROOK> bishops_w;
    std::array<Rook, MAX_PIECES_ROOK> rooks_w;
    std::array<Queen, MAX_PIECES_QUEEN> queens_w;
    std::array<King, MAX_PIECES_KING> kings_w;
    int pawn_w_count = 0;
    int knight_w_count = 0;
    int bishop_w_count = 0;
    int rook_w_count = 0;
    int queen_w_count = 0;
    int king_w_count = 0;
    std::array<Pawn, MAX_PIECES_PAWN> pawns_b;
    std::array<Knight, MAX_PIECES_KNIGHT> knights_b;
    std::array<Bishop, MAX_PIECES_ROOK> bishops_b;
    std::array<Rook, MAX_PIECES_ROOK> rooks_b;
    std::array<Queen, MAX_PIECES_QUEEN> queens_b;
    std::array<King, MAX_PIECES_KING> kings_b;
    int pawn_b_count = 0;
    int knight_b_count = 0;
    int bishop_b_count = 0;
    int rook_b_count = 0;
    int queen_b_count = 0;
    int king_b_count = 0;

    /**
     * Template method to set the position of a piece in the provided array.
     * This brings the piece onto the board.
     * Allows to reuse existing pieces by updating their position
     * instead of creating new ones in their place.
     */
    template <typename T, size_t N>
    void spawn_piece_pos_in_array(std::array<T, N> &pieces, const PieceColor piece_color, const Position &pos);

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
    bool is_max_piece_type_reached(const PieceType piece_type, const PieceColor piece_color, const int count, const int max) const;

    // Get the unicode characters of the selected piece
    std::string get_piece_unicode(const PieceType piece_type, const PieceColor piece_color) const;

public:
    // Constructor initializes the board with nullptrs
    Board();

    // Default destructor
    ~Board() = default;

    // Sets a piece at a given position
    void spawn_piece(const PieceType piece_type, const PieceColor piece_color, Position pos);

    // Executes the move move for a piece from the start position to the end position
    void move_piece(const Position &start, const Position &end);

    // Prints all the valid pieces on the board
    void print_active_pieces() const;

    // Displays the current state of the board
    void draw() const;
};
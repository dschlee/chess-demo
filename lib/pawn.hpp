#pragma once
#include "../lib/piece.hpp"

class Pawn final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    Pawn();

    // Destructor
    ~Pawn() = default;

    // Check if the move is valid for a Pawn
    virtual bool can_move(const Position &start, const Position &end, const Piece *end_piece) const override;

    // Virtual function to check if the piece can capture another piece during a move
    virtual bool can_capture(const Piece *end_piece) const override;
};
#pragma once
#include "../lib/piece.hpp"

class Rook final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    Rook();

    // Destructor
    ~Rook() = default;

    // Check if the move is valid for a Rook
    virtual bool can_move(const Position &start, const Position &end, const Piece *end_piece) const override;
};
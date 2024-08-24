#pragma once
#include "../lib/piece.hpp"

class Knight final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    Knight();

    // Destructor
    ~Knight() = default;

    // Check if the move is valid for a Knight
    virtual bool can_move(const Position &start, const Position &end, const Piece *end_piece) const override;
};
#pragma once
#include "../lib/piece.hpp"

class Queen final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    Queen();

    // Destructor
    ~Queen() = default;

    // Check if the move is valid for a Queen
    virtual bool can_move(const Position &start, const Position &end, const Piece *end_piece) const override;
};
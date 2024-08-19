#pragma once
#include "../lib/piece.hpp"

class Bishop final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    Bishop();

    // Destructor
    ~Bishop() = default;

    // Check if the move is valid for a Bishop
    virtual bool can_move(const Position &start, const Position &end) const override;
};
#pragma once
#include "../lib/piece.hpp"

class King final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    King();

    // Destructor
    ~King() = default;

    // Check if the move is valid for a King
    virtual bool can_move(const Position &start, const Position &end) const override;
};
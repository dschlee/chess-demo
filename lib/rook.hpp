#pragma once
#include "../lib/piece.hpp"

class Rook final : public Piece
{
public:
    Rook();

    // Constructor
    Rook(const Position &pos);

    // Destructor
    ~Rook() = default;

    // Check if the move is valid for a Rook
    virtual bool can_move(const Position &start, const Position &end, const Board &board) const override;

    // Execute the move for a Rook
    virtual void move(const Position &start, const Position &end, Board &board) override;
};
#pragma once
#include "../lib/piece.hpp"

class Knight final : public Piece
{
public:
    // No-args constructor used for creating default pieces
    Knight();

    // // Proper constructor
    // Knight(const Position &pos);

    // Destructor
    ~Knight() = default;

    // Check if the move is valid for a Knight
    virtual bool can_move(const Position &start, const Position &end, const Board &board) const override;

    // Execute the move for a Knight
    virtual void move(const Position &start, const Position &end, Board &board) override;
};
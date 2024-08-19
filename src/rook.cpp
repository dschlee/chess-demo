#include "../lib/rook.hpp"

Rook::Rook()
    : Piece(Position(), PieceType::Rook) {}

bool Rook::can_move(const Position &start, const Position &end) const
{
    // Rook can only move in a straight line vertically or horizontally
    return (start.row == end.row || start.col == end.col);
}

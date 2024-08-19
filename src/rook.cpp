#include "../lib/rook.hpp"

Rook::Rook()
    : Piece(Position(), PieceType::Rook) {}

bool Rook::can_move(const Position &start, const Position &end) const
{
    // TODO
    return true;
}

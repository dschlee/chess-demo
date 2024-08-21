#include "../lib/pawn.hpp"

Pawn::Pawn()
    : Piece(Position(), PieceType::Pawn, PieceColor::White) {}

bool Pawn::can_move(const Position &start, const Position &end) const
{
    // TODO
    return false;
}

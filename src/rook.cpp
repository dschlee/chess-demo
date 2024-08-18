#include "../lib/rook.hpp"

Rook::Rook(const Position &pos)
    : Piece(pos, PieceType::Rook) {}

bool Rook::can_move(const Position &start, const Position &end, const Board &board) const
{
    // TODO
    return true;
}

void Rook::move(const Position &start, const Position &end, Board &board)
{
    // TODO
}

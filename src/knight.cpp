#include "../lib/knight.hpp"

Knight::Knight()
    : Piece(Position(), PieceType::Knight) {}

// Knight::Knight(const Position &pos)
//     : Piece(pos, PieceType::Knight) {}

bool Knight::can_move(const Position &start, const Position &end, const Board &board) const
{
    // TODO
    return true;
}

void Knight::move(const Position &start, const Position &end, Board &board)
{
    // TODO
}

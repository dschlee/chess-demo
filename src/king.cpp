#include "../lib/king.hpp"

King::King()
    : Piece(Position(), PieceType::King) {}

bool King::can_move(const Position &start, const Position &end) const
{
    // King can move one square in any direction
    int row_diff = abs(end.row - start.row);
    int col_diff = abs(end.col - start.col);
    return (row_diff <= 1 && col_diff <= 1);
}

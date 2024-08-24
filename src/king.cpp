#include "../lib/king.hpp"

King::King()
    : Piece(Position(), PieceType::King, PieceColor::White) {}

bool King::can_move(const Position &start, const Position &end, const Piece *end_piece) const
{
    if (end_piece && !Piece::can_capture(end_piece))
    {
        return false;
    }

    // King can move one square in any direction
    int row_diff = abs(end.row - start.row);
    int col_diff = abs(end.col - start.col);
    return (row_diff <= 1 && col_diff <= 1);
}

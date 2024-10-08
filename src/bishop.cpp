#include "../lib/bishop.hpp"

Bishop::Bishop()
    : Piece(Position(), PieceType::Bishop, PieceColor::White) {}

bool Bishop::can_move(const Position &start, const Position &end, const Piece *end_piece) const
{
    if (end_piece && !Piece::can_capture(end_piece))
    {
        return false;
    }

    // Bishop can only move diagonally
    int row_diff = abs(end.row - start.row);
    int col_diff = abs(end.col - start.col);
    return row_diff == col_diff;
}

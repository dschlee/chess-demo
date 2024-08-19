#include "../lib/bishop.hpp"

Bishop::Bishop()
    : Piece(Position(), PieceType::Bishop) {}

bool Bishop::can_move(const Position &start, const Position &end) const
{
    // Bishop can only move diagonally
    int row_diff = abs(end.row - start.row);
    int col_diff = abs(end.col - start.col);
    return row_diff == col_diff;
}

#include "../lib/queen.hpp"

Queen::Queen()
    : Piece(Position(), PieceType::Queen, PieceColor::White) {}

bool Queen::can_move(const Position &start, const Position &end, const Piece *end_piece) const
{
    if (end_piece && !Piece::can_capture(end_piece))
    {
        return false;
    }

    // Queen can move any number of squares in a straight line vertically, horizontally, or diagonally
    int row_diff = abs(end.row - start.row);
    int col_diff = abs(end.col - start.col);
    return (start.row == end.row || start.col == end.col || row_diff == col_diff);
}

#include "../lib/knight.hpp"

Knight::Knight()
    : Piece(Position(), PieceType::Knight, PieceColor::White) {}

bool Knight::can_move(const Position &start, const Position &end, const Piece *end_piece) const
{
    if (end_piece && !Piece::can_capture(end_piece))
    {
        return false;
    }

    // Knight moves in an "L" shape:
    // it moves two squares in one direction and one square in the perpendicular direction
    int row_diff = abs(end.row - start.row);
    int col_diff = abs(end.col - start.col);
    return (row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2);
}

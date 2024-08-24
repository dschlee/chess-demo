#include "../lib/rook.hpp"

Rook::Rook()
    : Piece(Position(), PieceType::Rook, PieceColor::White) {}

bool Rook::can_move(const Position &start, const Position &end, const Piece *end_piece) const
{
    if (end_piece && !Piece::can_capture(end_piece))
    {
        return false;
    }

    // Rook can only move in a straight line vertically or horizontally
    return (start.row == end.row || start.col == end.col);
}

#include "../lib/pawn.hpp"

Pawn::Pawn()
    : Piece(Position(), PieceType::Pawn, PieceColor::White) {}

bool Pawn::can_move(const Position &start, const Position &end, const Piece *end_piece) const
{
    if (end_piece && !Piece::can_capture(end_piece))
    {
        return false;
    }

    int row_diff = end.row - start.row;
    int col_diff = abs(end.col - start.col);

    // Pawn moves one square forward (assuming white moves up the board and black moves down)
    if (piece_color_ == PieceColor::White)
    {
        // Move one square forward
        if (row_diff == 1 && col_diff == 0)
        {
            return true;
        }
        // Move two squares forward from the starting position
        else if (start.row == 2 && row_diff == 2 && col_diff == 0)
        {
            return true;
        }
        // Move diagonally only to capture an opponent piece
        else if (row_diff == 1 && col_diff == 1 && end_piece)
        {
            return true;
        }
    }
    else if (piece_color_ == PieceColor::Black)
    {
        // Move one square forward
        if (row_diff == -1 && col_diff == 0)
        {
            return true;
        }
        // Move two squares forward from the starting position
        else if (start.row == 7 && row_diff == -2 && col_diff == 0)
        {
            return true;
        }
        // Move diagonally only to capture an opponent piece
        else if (row_diff == -1 && col_diff == 1 && end_piece)
        {
            return true;
        }
    }

    return false;
}

bool Pawn::can_capture(const Piece *end_piece) const
{

    Position start = pos_;
    Position end = end_piece->get_position();

    int row_diff = end.row - start.row;
    int col_diff = abs(end.col - start.col);

    if (piece_color_ == PieceColor::White)
    {

        // Check if the capture is diagonally one square forward for white
        if (row_diff == 1 && col_diff == 1)
        {
            return Piece::can_capture(end_piece);
        }
    }
    else if (piece_color_ == PieceColor::Black)
    {
        // Check if the capture is diagonally one square forward for black
        if (row_diff == -1 && col_diff == 1)
        {
            return Piece::can_capture(end_piece);
        }
    }
    return false;
}

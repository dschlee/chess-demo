#include "../lib/piece.hpp"

Piece::Piece(const Position &pos, PieceType piece_type)
    : pos_(pos), piece_type_(piece_type) {}

void Piece::set_position(const Position &pos)
{
    pos_ = pos;
}

Position Piece::get_position() const
{
    return pos_;
}

char Piece::get_piece_type() const
{
    return static_cast<char>(piece_type_);
}
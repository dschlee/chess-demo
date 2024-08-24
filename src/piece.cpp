#include "../lib/piece.hpp"

Piece::Piece(const Position &pos, PieceType piece_type, PieceColor piece_color)
    : pos_(pos), piece_type_(piece_type), piece_color_(piece_color) {}

bool Piece::can_capture(const Piece *end_piece) const
{
    if (piece_color_ == end_piece->get_piece_color())
    {
        std::cout << "Invalid: End position is occupied." << std::endl;
        return false;
    }
    return true;
}

void Piece::set_position(const Position &pos)
{
    pos_ = pos;
}

void Piece::set_piece_color(const PieceColor piece_color)
{
    piece_color_ = piece_color;
}

Position Piece::get_position() const
{
    return pos_;
}

PieceType Piece::get_piece_type() const
{
    // return static_cast<char>(piece_type_);
    return piece_type_;
}

PieceColor Piece::get_piece_color() const
{
    // return static_cast<char>(piece_color_);
    return piece_color_;
}
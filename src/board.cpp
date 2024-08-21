#include <iostream>
#include <iomanip>
#include "../lib/board.hpp"

Board::Board()
{
    for (auto &row : board)
    {
        row.fill(nullptr);
    }
}

template <typename T, size_t N>
void Board::spawn_piece_pos_in_array(std::array<T, N> &pieces, const PieceColor piece_color, const Position &pos)
{
    for (auto &piece : pieces)
    {
        // Object is not in the game
        if (piece.get_position().col == -1)
        {
            piece.set_position(pos);
            piece.set_piece_color(piece_color);
            board.at(pos.row).at(pos.col) = &piece;
            std::cout << "Set " << get_piece_unicode(piece.get_piece_type(), piece.get_piece_color())
                      << " (" << pos.row << ", " << pos.col << ")" << std::endl;
            break;
        }
    }
}

template <typename T, size_t N>
void Board::print_piece_array(const std::array<T, N> &pieces) const
{
    for (auto &piece : pieces)
    {
        // Do not print default pieces with position (-1, -1)
        if (piece.get_position().row != -1)
        {
            std::cout << get_piece_unicode(piece.get_piece_type(), piece.get_piece_color()) << " (" << piece.get_position().row << ", " << piece.get_position().col << ")" << std::endl;
        }
    }
}

void Board::move_piece_pos_in_array(Piece *piece, const Position &start, const Position &end)
{
    std::cout << get_piece_unicode(piece->get_piece_type(), piece->get_piece_color())
              << " moved: (" << start.row << ", " << start.col << ") -> ("
              << end.row << ", " << end.col << ")" << std::endl;
    piece->set_position(end);
    board.at(start.row).at(start.col) = nullptr;
    board.at(end.row).at(end.col) = piece;
}

void Board::remove_piece_pos_in_array(Piece *piece)
{
    Position piece_pos = piece->get_position();
    std::cout << get_piece_unicode(piece->get_piece_type(), piece->get_piece_color())
              << " (" << piece_pos.row << ", " << piece_pos.col << ") captured." << std::endl;
    board.at(piece_pos.row).at(piece_pos.col);
    piece->set_position(Position(-1, -1));

    switch (static_cast<char>(piece->get_piece_color()))
    {
    case static_cast<char>(PieceColor::White):
        switch (static_cast<char>(piece->get_piece_type()))
        {
        case static_cast<char>(PieceType::Pawn):
            --pawn_w_count;
            break;
        case static_cast<char>(PieceType::Knight):
            --knight_w_count;
            break;
        case static_cast<char>(PieceType::Bishop):
            --bishop_w_count;
            break;
        case static_cast<char>(PieceType::Rook):
            --rook_w_count;
            break;
        case static_cast<char>(PieceType::Queen):
            --queen_w_count;
            break;
        case static_cast<char>(PieceType::King):
            --king_w_count;
            break;
        }
    case static_cast<char>(PieceColor::Black):
        switch (static_cast<char>(piece->get_piece_type()))
        {
        case static_cast<char>(PieceType::Pawn):
            --pawn_b_count;
            break;
        case static_cast<char>(PieceType::Knight):
            --knight_b_count;
            break;
        case static_cast<char>(PieceType::Bishop):
            --bishop_b_count;
            break;
        case static_cast<char>(PieceType::Rook):
            --rook_b_count;
            break;
        case static_cast<char>(PieceType::Queen):
            --queen_b_count;
            break;
        case static_cast<char>(PieceType::King):
            --king_b_count;
            break;
        }
    }
}

Piece *Board::get_piece(const Position &pos) const
{
    return board.at(pos.row).at(pos.col);
}

bool Board::is_position_on_board(const Position &pos) const
{
    if (pos.row >= 1 &&
        pos.row < BOARD_SIZE &&
        pos.col >= 1 &&
        pos.col < BOARD_SIZE)
    {
        return true;
    }
    return false;
}

bool Board::is_max_piece_type_reached(const PieceType piece_type, const PieceColor piece_color, const int count, const int max) const
{
    if (count >= max)
    {
        std::cout << "Invalid: Maximum number of ";
        switch (static_cast<char>(piece_color))
        {
        case static_cast<char>(PieceColor::White):
            std::cout << "white " << get_piece_unicode(piece_type, PieceColor::White) << " reached." << std::endl;
            return true;
        case static_cast<char>(PieceColor::Black):
            std::cout << "black " << get_piece_unicode(piece_type, PieceColor::White) << " reached." << std::endl;
            return true;
        }
    }
    return false;
}

std::string Board::get_piece_unicode(const PieceType piece_type, const PieceColor piece_color) const
{
    switch (static_cast<char>(piece_color))
    {
    case static_cast<char>(PieceColor::White):
        switch (static_cast<char>(piece_type))
        {
        case static_cast<char>(PieceType::Pawn):
            return "\u2659";
        case static_cast<char>(PieceType::Knight):
            return "\u2658";
        case static_cast<char>(PieceType::Bishop):
            return "\u2657";
        case static_cast<char>(PieceType::Rook):
            return "\u2656";
        case static_cast<char>(PieceType::Queen):
            return "\u2655";
        case static_cast<char>(PieceType::King):
            return "\u2654";
        default:
            return "?";
        }
    case static_cast<char>(PieceColor::Black):
        switch (static_cast<char>(piece_type))
        {
        case static_cast<char>(PieceType::Pawn):
            return "\u265F";
        case static_cast<char>(PieceType::Knight):
            return "\u265E";
        case static_cast<char>(PieceType::Bishop):
            return "\u265D";
        case static_cast<char>(PieceType::Rook):
            return "\u265C";
        case static_cast<char>(PieceType::Queen):
            return "\u265B";
        case static_cast<char>(PieceType::King):
            return "\u265A";
        default:
            return "?";
        }
    default:
        return "?";
    }
}

void Board::spawn_piece(const PieceType piece_type, const PieceColor piece_color, Position pos)
{
    // Check if the position is valid
    if (!is_position_on_board(pos))
    {
        std::cout << "Invalid: Spawn position is out of bounds." << std::endl;
        return;
    }

    // Check if the position is already occupied by another piece
    Piece *piece = get_piece(pos);
    if (piece)
    {
        std::cout << "Invalid: Position is occupied." << std::endl;
        return;
    }

    // Check if the maximum amount of allowed pieces are in the game for the specified type and color
    switch (static_cast<char>(piece_color))
    {
    case static_cast<char>(PieceColor::White):
        switch (static_cast<char>(piece_type))
        {
        case static_cast<char>(PieceType::Pawn):
            if (!is_max_piece_type_reached(piece_type, piece_color, pawn_w_count, MAX_PIECES_PAWN))
            {
                spawn_piece_pos_in_array(pawns_w, PieceColor::White, pos);
                ++pawn_w_count;
            }
            return;
        case static_cast<char>(PieceType::Knight):
            if (!is_max_piece_type_reached(piece_type, piece_color, knight_w_count, MAX_PIECES_KNIGHT))
            {
                spawn_piece_pos_in_array(knights_w, PieceColor::White, pos);
                ++knight_w_count;
            }
            return;
        case static_cast<char>(PieceType::Bishop):
            if (!is_max_piece_type_reached(piece_type, piece_color, bishop_w_count, MAX_PIECES_BISHOP))
            {
                spawn_piece_pos_in_array(bishops_w, PieceColor::White, pos);
                ++bishop_w_count;
            }
            return;
        case static_cast<char>(PieceType::Rook):
            if (!is_max_piece_type_reached(piece_type, piece_color, rook_w_count, MAX_PIECES_ROOK))
            {
                spawn_piece_pos_in_array(rooks_w, PieceColor::White, pos);
                ++rook_w_count;
            }
            return;
        case static_cast<char>(PieceType::Queen):
            if (!is_max_piece_type_reached(piece_type, piece_color, queen_w_count, MAX_PIECES_QUEEN))
            {
                spawn_piece_pos_in_array(queens_w, PieceColor::White, pos);
                ++queen_w_count;
            }
            return;
        case static_cast<char>(PieceType::King):
            if (!is_max_piece_type_reached(piece_type, piece_color, king_w_count, MAX_PIECES_KING))
            {
                spawn_piece_pos_in_array(kings_w, PieceColor::White, pos);
                ++king_w_count;
            }
            return;
        default:
            std::cout << "Invalid piece type." << std::endl;
            return;
        }
    case static_cast<char>(PieceColor::Black):
        switch (static_cast<char>(piece_type))
        {
        case static_cast<char>(PieceType::Pawn):
            if (!is_max_piece_type_reached(piece_type, piece_color, pawn_b_count, MAX_PIECES_PAWN))
            {
                spawn_piece_pos_in_array(pawns_b, PieceColor::Black, pos);
                ++pawn_b_count;
            }
            return;
        case static_cast<char>(PieceType::Knight):
            if (!is_max_piece_type_reached(piece_type, piece_color, knight_b_count, MAX_PIECES_KNIGHT))
            {
                spawn_piece_pos_in_array(knights_b, PieceColor::Black, pos);
                ++knight_b_count;
            }
            return;
        case static_cast<char>(PieceType::Bishop):
            if (!is_max_piece_type_reached(piece_type, piece_color, bishop_b_count, MAX_PIECES_BISHOP))
            {
                spawn_piece_pos_in_array(bishops_b, PieceColor::Black, pos);
                ++bishop_b_count;
            }
            return;
        case static_cast<char>(PieceType::Rook):
            if (!is_max_piece_type_reached(piece_type, piece_color, rook_b_count, MAX_PIECES_ROOK))
            {
                spawn_piece_pos_in_array(rooks_b, PieceColor::Black, pos);
                ++rook_b_count;
            }
            return;
        case static_cast<char>(PieceType::Queen):
            if (!is_max_piece_type_reached(piece_type, piece_color, queen_b_count, MAX_PIECES_QUEEN))
            {
                spawn_piece_pos_in_array(queens_b, PieceColor::Black, pos);
                ++queen_b_count;
            }
            return;
        case static_cast<char>(PieceType::King):
            if (!is_max_piece_type_reached(piece_type, piece_color, king_b_count, MAX_PIECES_KING))
            {
                spawn_piece_pos_in_array(kings_b, PieceColor::Black, pos);
                ++king_b_count;
            }
            return;
        default:
            std::cout << "Invalid piece type." << std::endl;
            return;
        }
    default:
        std::cout << "Invalid piece color." << std::endl;
        return;
    }
}

void Board::move_piece(const Position &start, const Position &end)
{
    std::cout << "Command: (" << start.row << ", " << start.col << ") -> ("
              << end.row << ", " << end.col << ")" << std::endl;

    // Ensure the start and end positions are valid
    if (!is_position_on_board(start))
    {
        std::cout << "Invalid: Start position is out of bounds." << std::endl;
        return;
    }
    else if (!is_position_on_board(end))
    {
        std::cout << "Invalid: End position is out of bounds." << std::endl;
        return;
    }

    // Get the pointer of the considered piece at the start position
    Piece *piece = get_piece(start);
    Piece *end_piece = get_piece(end);

    // Ensure there is a piece at the start position
    if (!piece)
    {
        std::cout << "Invalid: No piece at the start position." << std::endl;
        return;
    }

    // Check if the move is valid according to the piece's movement rules
    if (!piece->can_move(start, end))
    {
        std::cout << "Invalid: Move not possible for " << get_piece_unicode(piece->get_piece_type(), piece->get_piece_color()) << " ." << std::endl;
        return;
    }

    // Path checking logic for pieces that move in a line
    if (start.row == end.row) // Horizontal move
    {
        int step = (end.col > start.col) ? 1 : -1;
        for (int col = start.col + step; col != end.col; col += step)
        {
            if (board.at(start.row).at(col) != nullptr)
            {
                std::cout << "Invalid: Path blocked." << std::endl;
                return;
            }
        }
    }
    else if (start.col == end.col) // Vertical move
    {
        int step = (end.row > start.row) ? 1 : -1;
        for (int row = start.row + step; row != end.row; row += step)
        {
            if (board.at(row).at(start.col) != nullptr)
            {
                std::cout << "Invalid: Path blocked." << std::endl;
                return;
            }
        }
    }
    else if (abs(end.row - start.row) == abs(end.col - start.col)) // Diagonal move
    {
        int row_step = (end.row > start.row) ? 1 : -1;
        int col_step = (end.col > start.col) ? 1 : -1;
        int row = start.row + row_step;
        int col = start.col + col_step;

        while (row != end.row && col != end.col)
        {
            if (board.at(row).at(col) != nullptr)
            {
                std::cout << "Invalid: Path blocked." << std::endl;
                return;
            }
            row += row_step;
            col += col_step;
        }
    }

    // Capture piece of other color at end position if applicable
    if (end_piece)
    {
        // Both pieces are of the same color
        if (piece->get_piece_color() == end_piece->get_piece_color())
        {
            std::cout << "Invalid: End position is occupied." << std::endl;
            return;
        }
        // Capture opponent piece
        else
        {
            remove_piece_pos_in_array(end_piece);
        }
    }

    // Perform the move
    move_piece_pos_in_array(piece, start, end);
}

void Board::print_active_pieces() const
{
    std::cout << std::endl
              << "White pieces on the board:" << std::endl;
    print_piece_array(pawns_w);
    print_piece_array(bishops_w);
    print_piece_array(knights_w);
    print_piece_array(rooks_w);
    print_piece_array(queens_w);
    print_piece_array(kings_w);
    std::cout << std::endl
              << "Black pieces on the board:" << std::endl;
    print_piece_array(pawns_b);
    print_piece_array(bishops_b);
    print_piece_array(knights_b);
    print_piece_array(rooks_b);
    print_piece_array(queens_b);
    print_piece_array(kings_b);
}

void Board::draw() const
{
    const std::string horizontal_line = "   +---+---+---+---+---+---+---+---+";

    std::cout << std::endl
              << std::endl;

    for (int i = BOARD_SIZE - 1; i >= 1; --i)
    {
        std::cout << horizontal_line << std::endl;

        // Print row number
        std::cout << " " << i << " ";

        for (int j = 1; j < BOARD_SIZE; ++j)
        {
            Piece *piece = board.at(j).at(i);

            std::cout << "|";

            if (piece == nullptr)
            {
                std::cout << "   ";
            }
            else
            {
                std::string pieceUnicode = get_piece_unicode(piece->get_piece_type(), piece->get_piece_color());
                std::cout << " " << pieceUnicode << " ";
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << horizontal_line << std::endl;

    // Print column labels at the bottom
    std::cout << "   ";
    for (int col = 1; col < BOARD_SIZE; ++col)
    {
        std::cout << "  " << col << " ";
    }
    std::cout << std::endl
              << std::endl;
}
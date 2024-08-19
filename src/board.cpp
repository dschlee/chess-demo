#include <iostream>
#include "../lib/board.hpp"

Board::Board()
{
    for (auto &row : board)
    {
        row.fill(nullptr);
    }
}

template <typename T, size_t N>
void Board::spawn_piece_pos_in_array(std::array<T, N> &pieces, const Position &pos)
{
    for (auto &piece : pieces)
    {
        // Object is not in the game
        if (piece.get_position().col == -1)
        {
            std::cout << "Set " << piece.get_piece_type()
                      << "(" << pos.row << ", " << pos.col << ")" << std::endl;
            piece.set_position(pos);
            board.at(pos.row).at(pos.col) = &piece;
            break;
        }
    }
}

template <typename T, size_t N>
void Board::print_piece_array(std::array<T, N> &pieces)
{
    for (auto &piece : pieces)
    {
        // Do not print default pieces with position (-1, -1)
        if (piece.get_position().row != -1)
        {
            std::cout << piece.get_piece_type() << "(" << piece.get_position().row << ", " << piece.get_position().col << ")" << std::endl;
        }
    }
}

void Board::move_piece_pos_in_array(Piece *piece, const Position &start, const Position &end)
{
    piece->set_position(end);
    board.at(start.row).at(start.col) = nullptr;
    board.at(end.row).at(end.col) = piece;
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

bool Board::is_max_piece_type_reached(const char piece_type, const int count, const int max) const
{
    if (count >= max)
    {
        std::cout << "Maximum number of " << piece_type << " reached." << std::endl;
        return true;
    }
    return false;
}

void Board::spawn_piece(char piece_type, Position pos)
{
    // Check if the position is valid
    if (!is_position_on_board(pos))
    {
        return;
    }

    // Check if the position is already occupied by another piece
    Piece *piece = get_piece(pos);
    if (piece)
    {
        std::cout << "Invalid: Position is occupied." << std::endl;
        return;
    }

    switch (piece_type)
    {
    case 'B':
        if (!is_max_piece_type_reached(piece_type, bishop_count, MAX_PIECES_BISHOP))
        {
            spawn_piece_pos_in_array(bishops, pos);
            ++bishop_count;
        }
        break;
    case 'K':
        if (!is_max_piece_type_reached(piece_type, knight_count, MAX_PIECES_KNIGHT))
        {
            spawn_piece_pos_in_array(knights, pos);
            ++knight_count;
        }
        break;
    case 'R':
        if (!is_max_piece_type_reached(piece_type, rook_count, MAX_PIECES_ROOK))
        {
            spawn_piece_pos_in_array(rooks, pos);
            ++rook_count;
        }
        break;
    default:
        std::cout << "Invalid piece type." << std::endl;
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

    // Ensure there is no piece at the end position
    if (end_piece)
    {
        std::cout << "Invalid: End position is occupied." << std::endl;
        return;
    }

    // Check if the move is valid according to the piece's movement rules
    if (!piece->can_move(start, end))
    {
        std::cout << "Invalid: Move not possible for " << piece->get_piece_type() << "." << std::endl;
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

    // Perform the move
    move_piece_pos_in_array(piece, start, end);
    std::cout << piece->get_piece_type()
              << " moved: (" << start.row << ", " << start.col << ") -> ("
              << end.row << ", " << end.col << ")" << std::endl;
}

void Board::print_pieces()
{
    std::cout << std::endl
              << "Pieces on the board:" << std::endl;
    print_piece_array(bishops);
    print_piece_array(rooks);
    print_piece_array(knights);
}

void Board::draw() const
{
    std::cout << std::endl;
    int row = 8;
    // char col = 'a';
    int col = 1;
    for (int i = BOARD_SIZE - 1; i >= 0; --i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            // std::cout << i << j << ", ";

            if (i == 0 && j == 0)
            {
                std::cout << "  ";
            }
            else if (i == 0)
            {
                std::cout << col++ << ' ';
            }
            else if (j == 0)
            {
                std::cout << row-- << ' ';
            }
            else if (board.at(j).at(i) == nullptr)
            {
                std::cout << ". ";
            }
            else
            {
                std::cout << board.at(j).at(i)->get_piece_type() << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

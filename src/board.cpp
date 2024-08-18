#include <iostream>
#include "../lib/board.hpp"

Board::Board()
{
    for (auto &row : board)
    {
        row.fill(nullptr);
    }
}

Piece *Board::get_piece(const Position &pos) const
{
    // TODO
    return nullptr;
}

// void Board::set_piece(Piece &piece, const Position &pos)
// {
//     if (pos.row >= 0 && pos.row < BOARD_SIZE && pos.col >= 0 && pos.col < BOARD_SIZE)
//     {
//         board.at(pos.row).at(pos.col) = &piece;
//     }
// }

void Board::set_piece(char piece_type, Position pos)
{
    if (!is_position_on_board(pos))
    {
        return;
    }

    switch (piece_type)
    {
    case 'R':
        if (rook_count >= MAX_PIECES_ROOK)
        {
            std::cout << "Maximum amount of rooks reached." << std::endl;
            break;
        }
        update_piece_pos_in_array(rooks, pos);
        std::cout << "Rook set on (" << pos.row << ", " << pos.col << ")" << std::endl;
        ++rook_count;
        break;
    case 'K':
        if (knight_count >= MAX_PIECES_ROOK)
        {
            std::cout << "Maximum amount of Knight reached." << std::endl;
            break;
        }
        update_piece_pos_in_array(knights, pos);
        std::cout << "Knight set on (" << pos.row << ", " << pos.col << ")" << std::endl;
        ++knight_count;
        break;
    default:
        std::cout << "Invalid piece type" << std::endl;
    }
}

template <typename T, size_t N>
void Board::update_piece_pos_in_array(std::array<T, N> &pieces, const Position &pos)
{
    for (auto &piece : pieces)
    {
        // Object is not in the game
        if (piece.get_position().col == -1)
        {
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

void Board::print_pieces()
{
    std::cout << std::endl
              << "Pieces on the board:" << std::endl;
    print_piece_array(rooks);
    print_piece_array(knights);
}

bool Board::move_piece(const Position &start, const Position &end)
{
    // TODO
    return true;
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

bool Board::is_position_on_board(Position &pos)
{
    if (pos.row >= 1 &&
        pos.row < BOARD_SIZE &&
        pos.col >= 1 &&
        pos.col < BOARD_SIZE)
    {
        return true;
    }
    std::cout << "Position invalid: Position out of bounds." << std::endl;
    return false;
}

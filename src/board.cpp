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

void Board::set_piece(Piece &piece, const Position &pos)
{
    if (pos.row >= 0 && pos.row < BOARD_SIZE && pos.col >= 0 && pos.col < BOARD_SIZE)
    {
        board.at(pos.row).at(pos.col) = &piece;
    }
}

bool Board::move_piece(const Position &start, const Position &end)
{
    // TODO
    return true;
}

void Board::draw() const
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board.at(i).at(j) == nullptr)
            {
                std::cout << ". ";
            }
            else
            {
                std::cout << board[i][j]->get_piece_type() << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// void Board::print_pieces()
// {
//     // TODO
//     std::cout << "[ ";
//     for (auto &piece : pieces_)
//     {
//         std::cout << piece << " ";
//     }
//     std::cout << "]" << std::endl;
// }

// void Board::add_piece(int piece)
// {
//     // TODO it should accept (char piece_abb, char board_x, int board_y) [e.g. Na1, Rb1]
//     // Invoke the constructor of class Piece here with vec.emplace_back(<constructor_initialization_list>)

//     // TODO guard check if entered piece_abbrevation and coordinates are valid -> call is_position_valid()

//     pieces_.emplace_back(piece);
// }

// bool Board::move_piece(int piece)
// {
//     // TODO
//     return true;
// }

// bool Board::is_position_valid(int piece)
// {
//     // TODO
//     return true;
// }

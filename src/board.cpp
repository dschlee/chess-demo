#include <iostream>
#include "../lib/board.hpp"

Board::Board()
{
    for (auto &row : board)
    {
        row.fill(nullptr);
    }
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
        }
        std::cout << std::endl;
    }
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

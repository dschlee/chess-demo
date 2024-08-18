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
        if (rook_count < MAX_PIECES_ROOK)
        {
            rooks.at(rook_count) = Rook(pos);
            board.at(pos.row).at(pos.col) = &rooks.at(rook_count);
            std::cout << "Rook set on (" << pos.row << ", " << pos.col << ")" << std::endl;
            ++rook_count;
        }
        break;
    case 'K':
        std::cout << "Knight" << std::endl;
        break;
    default:
        std::cout << "Invalid piece type" << std::endl;
    }
}

void Board::print_pieces()
{
    std::cout << std::endl
              << "Pieces on the board:" << std::endl;
    for (auto rook : rooks)
    {
        // Do not print default pieces with position (-1, -1)
        if (rook.get_position().row != -1)
        {
            std::cout << rook.get_piece_type() << "(" << rook.get_position().row << ", " << rook.get_position().col << ")" << std::endl;
        }
    }
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

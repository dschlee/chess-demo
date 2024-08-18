#include <iostream>
#include "../lib/board.hpp"
#include "../lib/piece.hpp"
#include "../lib/rook.hpp"
#include "../lib/knight.hpp"

int main()
{
    Board board;
    board.draw();

    board.set_piece('R', Position(1, 1));
    board.set_piece('K', Position(1, 2));

    board.print_pieces();

    board.draw();
    std::cout << std::endl;
    return 0;
}

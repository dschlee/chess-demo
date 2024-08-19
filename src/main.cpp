#include <iostream>
#include "../lib/board.hpp"
#include "../lib/piece.hpp"
#include "../lib/rook.hpp"
#include "../lib/knight.hpp"

int main()
{
    Board board;
    board.draw();

    board.spawn_piece('R', Position(1, 1));
    board.spawn_piece('K', Position(1, 2));
    board.print_pieces();
    board.draw();

    board.move_piece(Position(1, 1), Position(3, 1));
    board.print_pieces();
    board.draw();

    std::cout << std::endl;
    return 0;
}

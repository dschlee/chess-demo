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
    board.spawn_piece('B', Position(1, 2));
    board.print_pieces();
    board.draw();

    board.move_piece(Position(1, 1), Position(1, 5));
    board.draw();

    board.move_piece(Position(1, 1), Position(5, 1));
    board.draw();

    board.move_piece(Position(1, 1), Position(3, 1));
    board.draw();

    board.move_piece(Position(5, 1), Position(2, 3));
    board.draw();

    board.move_piece(Position(5, 1), Position(5, 6));
    board.draw();

    board.move_piece(Position(1, 2), Position(1, 1));
    board.draw();

    board.move_piece(Position(1, 2), Position(2, 3));
    board.draw();

    board.move_piece(Position(2, 3), Position(5, 6));
    board.draw();

    board.move_piece(Position(2, 3), Position(-1, 0));
    board.draw();

    board.move_piece(Position(0, 3), Position(-1, 0));
    board.draw();

    board.print_pieces();

    std::cout << std::endl;
    return 0;
}

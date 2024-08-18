#include <iostream>
#include "../lib/board.hpp"
#include "../lib/piece.hpp"
#include "../lib/rook.hpp"
#include "../lib/knight.hpp"

int main()
{
    Board board;
    board.draw();
    // Rook rook(Position(1, 1));
    // Knight knight(Position(0, 2));

    // board.set_piece(rook);
    // board.set_piece(knight);

    board.set_piece('R', Position(1, 2));
    board.set_piece('R', Position(5, 2));

    board.print_pieces();

    board.draw();
    std::cout << std::endl;
    return 0;
}

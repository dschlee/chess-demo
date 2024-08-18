#include <iostream>
#include "../lib/board.hpp"
#include "../lib/piece.hpp"
#include "../lib/rook.hpp"
#include "../lib/knight.hpp"

int main()
{
    Board board;
    board.draw();
    Rook rook(Position(1, 1));

    board.set_piece(rook, Position(8, 8));

    // TODO position should only be defined once!

    board.draw();
    std::cout << std::endl;
    return 0;
}

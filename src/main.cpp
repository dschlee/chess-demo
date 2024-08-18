#include <iostream>
#include "../lib/board.hpp"
#include "../lib/piece.hpp"
#include "../lib/rook.hpp"
#include "../lib/knight.hpp"

int main()
{
    Board board;
    board.draw();
    // board.add_piece(5);
    // board.add_piece(32);
    // board.print_pieces();

    std::cout << std::endl;
    return 0;
}

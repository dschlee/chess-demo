#pragma once
#include <array>
#include "../lib/piece.hpp"

const int BOARD_SIZE = 8;

class Board
{
private:
    std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> board{};

public:
    Board();
    ~Board() = default;
    void draw() const;
    // bool is_position_valid(int piece);
};
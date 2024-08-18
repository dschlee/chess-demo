#pragma once

struct Position
{
    int row;
    int col;

    Position(int r = -1, int c = -1)
        : row(r), col(c) {}
};

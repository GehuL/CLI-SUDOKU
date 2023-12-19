#include "sudoku.h"

bool is_valid(const Sudoku& sudoku, unsigned x, unsigned y, unsigned value)
{
    if (sudoku.grid().at(y*9 + x) != 0)
        return false;

    for (int i = 0; i < 9; i++)
    {
        if (sudoku.grid().at(y*9 + i) == value)
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (sudoku.grid().at(i*9 + x) == value)
            return false;
    }

    unsigned x_square = x / 3;
    unsigned y_square = y / 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (sudoku.grid().at( (y_square + i)*3 + x_square + x ) == value)
                return false;
        }

    return true;
}

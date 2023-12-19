#include "sudoku.h"

namespace sudoku
{
    bool is_valid(const Sudoku& sudoku, unsigned x, unsigned y, unsigned value)
    {
        if (sudoku.at(x, y) != 0)
            return false;

        for (int i = 0; i < 9; i++)
        {
            if (sudoku.at(i, y) == value)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (sudoku.at(x, i) == value)
                return false;
        }

        unsigned x_square = x / 3;
        unsigned y_square = y / 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (sudoku.at(x_square + j, y_square + i ) == value)
                    return false;
            }

        return true;
    }

    bool solve_recursive(Sudoku& sudoku, unsigned x, unsigned y)
    {
        for (int value = 1; value < 10; value++)
        {
            if (sudoku.set(x, y, value))
                return solve_recursive(sudoku, (x + 1)%9, (y+1)%9 );
        }

        sudoku.set(x, y, 0);
        return false;
    }
}

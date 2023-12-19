#include "sudoku.h"

#include <math.h>
#include <assert.h>
#include <random>
#include <time.h>

namespace sudoku
{
    Sudoku::Sudoku(Difficulty difficulty)
    {
        _grid.fill(0);

        srand( time( NULL ) );
        int case_nbr = static_cast<int>(difficulty);
        // assert(case_nbr < _sudoku.size() && "Number of generated values can't be equal or greater than the grid size");

        while(case_nbr > 0)
        {
            int value = rand() % 9 + 1;

            unsigned posx, posy, pos;
            pos = rand() % _grid.size();
            to_point(pos, &posx, &posy);

            if(set(posx, posy, value))
                case_nbr--;
        }
    }

    bool Sudoku::set(int x, int y, unsigned int value)
    {
        if (is_valid(*this, x, y, value))
        {
            _grid.at(y*9 + x) = value;
            return true;
        }

        return false;
    }

    void Sudoku::to_point(unsigned pos, unsigned* posx, unsigned* posy) const
    {
        int len = static_cast<int>(sqrt(_grid.size()));

        *posx = pos % len;
        *posy = pos / len;
    }

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

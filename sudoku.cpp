#include "sudoku.h"

#include <math.h>
#include <assert.h>
#include <random>
#include <time.h>

namespace esirem
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

    void Sudoku::to_point(unsigned pos, unsigned* posx, unsigned* posy) const
    {
        int len = static_cast<int>(sqrt(_grid.size()));

        *posx = pos % len;
        *posy = len / (pos - *posx) - 1;
    }

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

}

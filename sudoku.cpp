#include "sudoku.h"
#include <assert.h>
#include <random>
#include <time.h>

namespace sudoku
{
    Sudoku::Sudoku(Difficulty difficulty)
    {
        _grid.fill(0);

        srand( time( NULL ) );
        int case_nbr = 34; //static_cast<int>(difficulty);
        assert(case_nbr < _grid.size() && "Number of generated values can't be equal or greater than the grid size");

        while(case_nbr > 0)
        {
            int value = rand() % 9 + 1;
            unsigned posx, posy, pos = rand() % _grid.size();
            to_point(pos, &posx, &posy);

            if(set(posx, posy, value))
                case_nbr--;
        }
    }

    bool Sudoku::set(int x, int y, unsigned int value)
    {
        int pos = linearize(x, y);
        if(!is_valid(*this, x, y, value))
            return false;
        _grid.at(pos) = value;
        return true;
    }

    unsigned int Sudoku::at(int x, int y) const
    {
        int pos = linearize(x, y);
        return _grid.at(pos);
    }

    int Sudoku::linearize(int x, int y) const
    {
        return length() * y + x; 
    }

    void Sudoku::to_point(unsigned pos, unsigned* posx, unsigned* posy) const
    {
        int len = length();

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
                if (sudoku.at(x_square * 3 + j, y_square * 3 + i ) == value)
                    return false;
            }

        return true;
    }

    bool solve(Sudoku& sudoku)
    {
        return solve_recursive(sudoku, 0, 0);
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

    std::ostream& operator<<(std::ostream& ios, const Sudoku& sudoku)
    {
        int len = sudoku.length();

        for(int a = 0; a < len * 2 + 1; a++)
            if(a % 6 == 0)
                ios << '+';
             else
                ios << '-';
        
        ios << std::endl;
        for(int i = 0; i < len; i++)
        {
            ios << '|';
            for(int j = 0; j < len; j++)
            {
                auto k = sudoku.at(i, j);
                
                if(k != 0)
                    ios << k;
                else
                    ios << ' ';
       
                if((j + 1)% 3 != 0)
                    ios << ' ';
                
                if((j + 1) % 3 == 0)
                    ios << '|';
            }
            ios << '\n';

            if((i + 1) % 3 == 0)
            {
                for(int a = 0; a < len * 2 + 1; a++)
                {
                    if(a % 6 == 0)
                        ios << '+';
                    else
                        ios << '-';
                }
                ios << std::endl;
            }

        }
        return ios;
    }

}

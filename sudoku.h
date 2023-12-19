#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <array>
#include <iostream>

namespace sudoku
{
    enum class Difficulty
    {
        BEGINNER = 0,
        EASY,
        NORMAl,
        HARD,
        EXPERT
    };

    class Sudoku
    {
        public:
            Sudoku(Difficulty difficulty);

            unsigned int at(int x, int y) const;
            bool set(int x, int y, unsigned int value);

            inline int linearize(int x, int y) const;
            inline void to_point(unsigned linear, unsigned* x, unsigned* y) const;

        private:
            std::array<unsigned int, 81> _grid;
    };

    bool is_valid(const Sudoku& sudoku, unsigned x, unsigned y, unsigned value);


    bool solve_recursive(Sudoku& sudoku, unsigned x, unsigned y);

    // - If the sudoku is solvable, we return true and sudoku is now the solution
    // - If the sudoku is unsolvable, we return false and sudoku is the sale as before
    bool solve(Sudoku& sudoku) { return solve_recursive(sudoku, 0, 0); }

    std::iostream& operator<<(std::iostream& ios, const Sudoku& sudoku);
}

#endif

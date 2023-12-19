#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <array>
#include <iostream>

namespace esirem
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
            const std::array<unsigned int, 81>& grid() { return _grid; }

            bool set(int x, int y, unsigned int value);

            inline int linearize(int x, int y) const;

        private:
            std::array<unsigned int, 81> _grid;
    };

    bool is_valid(const Sudoku& sudoku, unsigned x, unsigned y, unsigned value);

    // Sudoku solve(const Sudoku& sudoku);
    void solve(Sudoku& sudoku);

    std::iostream& operator<<(std::iostream& ios, const Sudoku& sudoku);
}

#endif

#include <array>

class Sudoku
{
    public:
        Sudoku(unsigned difficulty);

        const std::array<unsigned, 81>& grid() const { return _grid; }

    private:
        std::array<unsigned, 81> _grid;
};

bool is_valid(const Sudoku& sudoku, unsigned x, unsigned y, unsigned value);

// Sudoku solve(const Sudoku& sudoku);
void solve(Sudoku& sudoku);

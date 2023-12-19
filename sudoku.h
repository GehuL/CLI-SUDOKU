class Sudoku
{
    public:
        Sudoku(unsigned difficulty);

        const std::array<81, unsigned>& grid() { return _grid; }

    private:
        std::array<81, unsigned> _grid;
}

bool is_valid(const Sudoku& sudoku, unsigned x, unsigned y, unsigned value);

// Sudoku solve(const Sudoku& sudoku);
void solve(Sudoku& sudoku);

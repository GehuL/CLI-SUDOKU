#include "sudoku.h"

#include <iostream>
#include "sudoku.h"

int main(int argc, char* argv[])
{
    sudoku::Sudoku sudoku(sudoku::Difficulty::EASY);
    std::cout << sudoku << std::endl;
    return 0;
}

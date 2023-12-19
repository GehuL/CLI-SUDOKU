#include <iostream>
#include "sudoku.h"

int main(int argc, char* argv[])
{
    sudoku::Sudoku sudoku(sudoku::Difficulty::BEGINNER);
    
    std::cout << "Hello World !" << std::endl;

    return 0;
}

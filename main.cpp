// http://www.opensky.ca/~jdhildeb/software/sudokugen/
#include <iostream>
#include <string>
#include <memory>

#include "PuzzleReader.h"
#include "SudokuGrid.h"
#include "Solver.h"

int main() {
    std::string inp_path = "../puzzle_dashes.csv";

    PuzzleReader puz_rd(inp_path);
    PuzzleReader::BasicGrid basic_grid = puz_rd.get_grid();

    std::shared_ptr<SudokuGrid> sudo_grid(new SudokuGrid((basic_grid)));
    sudo_grid->print_grid();

    Solver sudo_solve(sudo_grid);

    int iter_ct = 0;

    while (sudo_solve.update() > 0)
    {
        iter_ct++;
        std::cout << "Iteration " << iter_ct << "\n\n";
        sudo_grid->print_grid();
        std::cout << std::endl;
    }

    return 0;
}
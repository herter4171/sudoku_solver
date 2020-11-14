// http://www.opensky.ca/~jdhildeb/software/sudokugen/
#include <iostream>
#include <string>


#include "PuzzleReader.h"
#include "SudokuGrid.h"

int main() {
    std::string inp_path = "../puzzle_dashes.csv";

    PuzzleReader puz_rd(inp_path);
    PuzzleReader::BasicGrid basic_grid = puz_rd.get_grid();

    SudokuGrid sudo_grid(basic_grid);
    sudo_grid.print_grid();

    for (auto &p_cell: sudo_grid._get_square(4))
    {
        std::cout << p_cell->get_val() << " ";
    }

    return 0;
}
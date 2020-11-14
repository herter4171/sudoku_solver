//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_SUDOKUGRID_H
#define SUDOKU_SOLVER_SUDOKUGRID_H

#include <vector>
#include <memory>
#include <string>
#include <math.h>

#include "PuzzleReader.h"
#include "Cell.h"

class SudokuGrid {
public:
    SudokuGrid(PuzzleReader::BasicGrid basic_grid);

    void print_grid();

    // Short-hand for local use
    static const int side_length = PuzzleReader::side_length;

private:
    std::vector<std::shared_ptr<Cell>> _cells;
};


#endif //SUDOKU_SOLVER_SUDOKUGRID_H

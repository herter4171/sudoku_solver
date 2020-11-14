//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_SOLVER_H
#define SUDOKU_SOLVER_SOLVER_H

#include <memory>
#include <vector>

#import "SudokuGrid.h"
#import "CellGroup.h"

class Solver {

public:
    typedef CellGroup::CellVec CellVec;

    Solver(std::shared_ptr<SudokuGrid> grid);

    int update();

    // Short-hand for local use
    static const int side_length = SudokuGrid::side_length;

private:
    void _set_geometry();

    std::shared_ptr<SudokuGrid> _the_grid;

    std::vector<CellGroup> _rows, _cols, _squares;
};


#endif //SUDOKU_SOLVER_SOLVER_H

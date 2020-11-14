//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_CELL_H
#define SUDOKU_SOLVER_CELL_H

#include <string>
#include <stdexcept>

class Cell {
public:
    Cell(int row, int col, std::string init_val);

    bool is_empty();

    int get_val();

private:
    // Grid indices
    int _row, _col;

    // Empty cells have zero as _val
    const int _empty_val = 0;

    // Cell value (Zero for blank)
    int _val;
};


#endif //SUDOKU_SOLVER_CELL_H
